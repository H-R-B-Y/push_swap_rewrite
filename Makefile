NAME			:= push_swap
CFLAGS			:= -Wextra -Wall -Werror

MAKEFLAGS		+= --no-print-directory

libflags		:=

HEADERS			:= -Iinclude

LIB_DIR			:= ./lib

LIBFT_DIR		:= $(abspath $(LIB_DIR)/libft)
LIBFT			:= $(LIBFT_DIR)/libft.a

# MLX_DIR			:= $(abspath $(LIB_DIR)/mlx_linux)
# MLX				:= ${MLX_DIR}/libmlx.a ${MLX_DIR}/libmlx_Linux.a 
# LIBFLAGS		+= -lXext -lX11 -lm -lz

SRC_DIR			:= ./src
SRCS			:= 

OBJS			:= ${SRCS:.c=.o}

MAIN			:= $(SRC_DIR)/main.c

all: $(NAME) pre post

$(NAME): $(MAIN) $(OBJS)$(LIBFT) ./include/fractol.h
		@$(CC) $(CFLAGS) $(MAIN) $(OBJS)$(LIBFT) $(LIBFLAGS) -o $(NAME)

$(LIBFT):
		@$(MAKE) --directory $(LIBFT_DIR) all CFLAGS="$(CFLAGS)"

.c.o:
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
		@$(MAKE) --directory $(COMPLEX_DIR) clean
		@$(MAKE) --directory $(MLX_WRAP_DIR) clean
		@$(MAKE) --directory $(LIBFT_DIR) clean 
		@rm -rf $(OBJS)

rm:
		@$(MAKE) --directory $(COMPLEX_DIR) fclean
		@$(MAKE) --directory $(MLX_WRAP_DIR) fclean
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

.PHONY: all, clean, fclean, re, test, pre, post, rm