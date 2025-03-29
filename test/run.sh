#! /usr/bin/bash


for i in {1..1000}; do
	# Generate arguments and run the program
	./numgen.py > args
	./push_swap $(cat args) > sort
	checker_output=$(cat sort | ./checker $(cat args))
	checker2_output=$(cat sort | ./checker_linux $(cat args))
	
	# Check if the outputs are different
	if [[ "$checker_output" != "$checker2_output" ]]; then
		echo "Difference found in run ${i}" >> "diff_${i}.txt"
		cat agrs >> "diff_${i}.txt"
	fi

	# Check if checker output is "KO" and save the arguments if true
	if [[ "$checker_output" == *"KO"* ]]; then
		cat args > "fail_${i}.txt"
	fi
	echo "run ${i} done stat ${checker_output} count: $(cat sort | wc -l)"
done