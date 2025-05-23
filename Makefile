NAME			:= push_swap
CFLAGS			:= -Wextra -Wall -Werror -O0 -g3
#CFLAGS			:= 

MAKEFLAGS		+= --no-print-directory

LIBFLAGS		:=

HEADERS			:= -Iinclude

LIB_DIR			:= ./lib

LIBFT_DIR		:= $(abspath $(LIB_DIR)/libft)
LIBFT			:= $(LIBFT_DIR)/libft.a

SRC_DIR			:= ./src
SRCS			:= \
				$(SRC_DIR)/operations/append_operation.c \
				$(SRC_DIR)/operations/rrot_operations.c \
				$(SRC_DIR)/operations/swap_operations.c \
				$(SRC_DIR)/operations/rot_operations.c \
				$(SRC_DIR)/operations/push_operations.c \
				$(SRC_DIR)/operations/do_ops.c \
				$(SRC_DIR)/parsing/parse_args.c \
				$(SRC_DIR)/parsing/duplicate_check.c \
				$(SRC_DIR)/cdll/pop_cdll.c \
				$(SRC_DIR)/cdll/push_cdll.c \
				$(SRC_DIR)/cdll/cdll_get.c \
				$(SRC_DIR)/cdll/init_cdll.c \
				$(SRC_DIR)/cdll/cdll_get_minmax.c \
				$(SRC_DIR)/debug/print_stack.c \
				$(SRC_DIR)/debug/print_opperations.c \
				$(SRC_DIR)/sorting/check_sorted.c \
				$(SRC_DIR)/sorting/mini_sort.c \
				$(SRC_DIR)/sorting/quick_select.c \
				$(SRC_DIR)/sorting/rotate_to_top.c \
				$(SRC_DIR)/sorting/sort_five.c \
				$(SRC_DIR)/sorting/sort_recursive.c \
				$(SRC_DIR)/sorting/sort_three_only.c \
				$(SRC_DIR)/calculations/find_correct_place.c \
				$(SRC_DIR)/calculations/optimal_push.c \
				$(SRC_DIR)/calculations/cost_reduction.c \
				$(SRC_DIR)/calculations/util.c \
				$(SRC_DIR)/calculations/node_is_blacklist.c \
				$(SRC_DIR)/calculations/lis.c \
				$(SRC_DIR)/calculations/find_best_lis.c \
				\

OBJS			:= ${SRCS:.c=.o}

MAIN			:= $(SRC_DIR)/main.c

all: $(NAME)

$(NAME): $(MAIN) $(OBJS) $(LIBFT) ./include/push_swap.h
		@echo
		@echo "   /)  /)",
		@echo " ପ(˶•-•˶)ଓ ♡",
		@echo -n "  /づ  づ ˚₊‧꒰$(NAME) :: Wait  ꒱ ‧₊˚⭒"
		@$(CC) $(CFLAGS) $(MAIN) $(OBJS) $(LIBFT) $(LIBFLAGS) -o $(NAME)
		@echo "\b\b\b\b\b\b\b\b\b\b\b\b\bDone  ꒱ ‧₊˚⭒"
		@echo 

$(LIBFT):
		@$(MAKE) --directory $(LIBFT_DIR) all CFLAGS="$(CFLAGS)"

bonus:
		@$(MAKE) --directory checker_bonus all CFLAGS="$(CFLAGS)"
		@cp checker_bonus/checker .

.c.o:
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
		@$(MAKE) --directory $(LIBFT_DIR) clean 
		@rm -rf $(OBJS)
		@find . -name '*.gcda' -delete
		@find . -name '*.gcno' -delete

rm:
		@$(MAKE) --directory $(LIBFT_DIR) fclean
		@$(MAKE) --directory checker_bonus fclean
		@rm -rf $(NAME)
		@rm -rf checker

fclean: clean rm pre post

re: fclean all

pre:
		@echo
		@echo "   /)  /)",
		@echo " ପ(˶•-•˶)ଓ ♡",
		@echo -n "  /づ  づ ˚₊‧꒰$(NAME) :: $(MAKECMDGOALS) :: Wait  ꒱ ‧₊˚⭒"

post:
		@echo "\b\b\b\b\b\b\b\b\b\b\b\b\bDone  ꒱ ‧₊˚⭒"
		@echo 

.PHONY: all clean fclean re test pre post rm coverage

coverage:
	rm -rf coverage_reports
	find . -name '*.gcda' -delete
	make --directory . re CFLAGS="-fprofile-arcs -ftest-coverage" CC=gcc-10
	sh -c "./push_swap 9 0 1 7 10 89 -1 -78 100 98 87"
	sleep 2
	mkdir -p coverage_reports
	find . -name '*.gcda' -exec mv -n {} . \;
	find . -name '*.gcno' -exec mv -n {} . \;
	find . -name '*.c' -exec gcov-10 -o . {} \;  >> coverage_reports.txt
	find . -name '*.gcov' -exec mv {} coverage_reports/ \;
	find . -name '*.gcda' -delete
	find . -name '*.gcno' -delete


# reference for cleanup
# nm -C --defined-only *.o | grep ' T ' > defined.txt
# nm -C --undefined-only *.o > undefined.txt
