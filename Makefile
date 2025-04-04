NAME			:= push_swap
CFLAGS			:= -Wextra -Wall -Werror -Ofast
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
				$(SRC_DIR)/operations/get_opposite.c \
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
				$(SRC_DIR)/sorting/rotate_to_top.c \
				$(SRC_DIR)/sorting/sort_recursive.c \
				$(SRC_DIR)/calculations/find_correct_place.c \
				$(SRC_DIR)/calculations/optimal_push.c \
				$(SRC_DIR)/calculations/cost_reduction.c \
				$(SRC_DIR)/calculations/util.c \
				$(SRC_DIR)/calculations/node_is_blacklist.c \
				$(SRC_DIR)/calculations/lis.c \
				\


OBJS			:= ${SRCS:.c=.o}

MAIN			:= $(SRC_DIR)/main.c

all: $(NAME) pre post

$(NAME): $(MAIN) $(OBJS) $(LIBFT) ./include/push_swap.h
		@$(CC) $(CFLAGS) $(MAIN) $(OBJS) $(LIBFT) $(LIBFLAGS) -o $(NAME)

$(LIBFT):
		@$(MAKE) --directory $(LIBFT_DIR) all CFLAGS="$(CFLAGS)"

.c.o:
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
		@$(MAKE) --directory $(LIBFT_DIR) clean 
		@rm -rf $(OBJS)

rm:
		@$(MAKE) --directory $(LIBFT_DIR) fclean
		@rm -rf $(NAME)

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

.PHONY: all clean fclean re test pre post rm