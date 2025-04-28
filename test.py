#!/usr/bin/python3

import subprocess
import random
import matplotlib.pyplot as plt
import argparse
import os
import statistics
import math, json
from concurrent.futures import ThreadPoolExecutor

global args
args = None

def run_executable(executable_name, input_list, checker_name = None):
	"""Runs the executable with a given list of integers and captures the output."""
	input_list = list(map(str, input_list))
	result = subprocess.run([executable_name] + input_list, text=True, capture_output=True)
	output_lines = result.stdout.splitlines()
	
	# Assuming the first line is the operation count and the second line is the sorted list.
	operations_count = len(output_lines)
	if checker_name != None:
		checker_proc = subprocess.run([checker_name] + input_list, input=result.stdout, text=True, capture_output=True)
		checker_res = checker_proc.stdout.splitlines()
		if (checker_res[0] == 'OK'):
			return [operations_count, True]
		else:
			return [operations_count, False]
	return [operations_count, True]

def generate_random_list(size):
	"""Generates a unique random list of integers between -100000 and 100000."""
	return random.sample(range(-100000, 100001), size)


def collect_data(executable_name, list_size, num_runs, max_workers=4, checker_name = None):
	"""Generates data by running the executable num_runs times with random lists of list_size in parallel."""
	operation_counts = []
	
	def task():
		random_list = generate_random_list(list_size)
		operation_count, passed = run_executable(executable_name, random_list, checker_name)
		return [operation_count, random_list, passed]
	
	with ThreadPoolExecutor(max_workers=max_workers) as executor:
		futures = [executor.submit(task) for _ in range(num_runs)]
		for future in futures:
			operation_counts.append(future.result())
	
	return operation_counts

def log_data(operations_data, log_level, log_name, log_failed = False):
	data = operations_data
	if (log_level > 0 or log_failed):
		data = list(filter(lambda x: ((x[0] >= log_level and log_level >= 0) or (log_failed and not x[2])), data))
	if (data != None and data != []):
		with open(log_name, "w+") as file:
			clean_data = {
				f"run_{x}_cost_{data[x][0]}" : {
					"cost" : data[x][0],
					"items" : data[x][1],
					"pass" : data[x][2]
				}
				for x in range(len(data))
			}
			text = json.dumps(clean_data, indent=4)
			file.write(text)

def run_and_make_plot(plt, plt_pos, pass_colour, arg_count, log_level, fail_colour = 'red'):
	operations_data = collect_data(args.executable, arg_count, args.num_runs, max_workers=args.threads, checker_name=args.checker)
	operations = [operations_data[x][0] for x in range(len(operations_data))]

	success_ops = [x[0] for x in operations_data if x[2]]  # x[2] == passed
	fail_ops = [x[0] for x in operations_data if not x[2]]

	# Log data for 5 elements if logging is enabled
	if (args.log == True and log_level) or args.log_failed:
		log_data(operations_data, log_level, f"runs_{arg_count}_data.json", log_failed = args.log_failed)
	
	# Calculate statistics for 5 elements
	mean = statistics.mean(operations)
	median = statistics.median(operations)
	mode = statistics.mode(operations)
	stdev = statistics.stdev(operations)
	minstat = min(operations)
	maxstat = max(operations)

	# Plot for 3 elements
	plt.subplot(*plt_pos)
	plt.hist(
		[success_ops, fail_ops],
		bins=20,
		stacked=True,
		color=[pass_colour, fail_colour],  # red = fail, green = success
		edgecolor='black'
	)
	plt.title(f"Operations to Sort {arg_count} Random Numbers")
	plt.xlabel("Number of Operations")
	plt.ylabel("Frequency")
	plt.text(0.7, 0.7, f"Mean: {mean:.2f}\nMedian: {median}\nMode: {mode}\nStd Dev: {stdev:.2f}\nMin: {minstat}\nMax: {maxstat}",
			transform=plt.gca().transAxes, fontsize=9, bbox=dict(facecolor='white', alpha=0.5))


def main():
	global args
	# Setup argument parser
	parser = argparse.ArgumentParser(description="Run executable and plot sorting operation count.")
	parser.add_argument("executable", help="Path to the sorting executable")
	parser.add_argument("--checker", type=str, default=None, help="Checker exe")
	parser.add_argument("--num_runs", type=int, default=100, help="Number of times to run each list size")
	parser.add_argument("--output", type=str, default="output.png", help="Filename to save the output plot")
	parser.add_argument("--threads", type=int, default=4, help="Number of threads to use")
	parser.add_argument("--log", type=int, default=False, help="Log runs")
	parser.add_argument("--log_failed", type=int, default=True, help="Log failed (overrides log)")
	parser.add_argument("--log_100_min", type=int, default=-1, help="Minimum operations required to be logged (100)")
	parser.add_argument("--log_500_min", type=int, default=-1, help="Minimum operations required to be logged (500)")
	parser.add_argument("--log_5_min", type=int, default=-1, help="Minimum operations required to be logged (5)")
	parser.add_argument("--log_3_min", type=int, default=-1, help="Minimum operations required to be logged (3)")

	args = parser.parse_args()
	
	# Print current working directory
	print(args.log)
	# Plotting the results
	plt.figure(figsize=(12, 12))

	run_and_make_plot(plt, [2,2,1], 'pink', 3, args.log_3_min)
	run_and_make_plot(plt, [2,2,2], 'lightgreen', 5, args.log_5_min)
	run_and_make_plot(plt, [2,2,3], 'skyblue', 100, args.log_100_min)
	run_and_make_plot(plt, [2,2,4], 'salmon', 500, args.log_500_min)

	plt.tight_layout()
	plt.savefig(args.output)

if __name__ == "__main__":
	main()