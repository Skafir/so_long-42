NAME			= so_long

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT 			= make -C ./libft/
MINILIBX	=	make -C ./minilibx-linux/

CC 				= cc

STANDARD_FLAGS 	= -g3 -Wall -Werror -Wextra
MINILIBX_FLAGS	= -Lmlx_linux -L/usr/lib -lXext -lX11 -lm -lz

LIBFT_EX = ./libft/libft.a
MINILIBX_EX = ./minilibx-linux/libmlx.a

LIBFT_PATH = ./libft
MINILIBX_PATH = ./minilibx-linux/

REMOVE 			= rm -f

SRCS 			= srcs/so_long.c srcs/ft_file_checker.c srcs/ft_valid_maps.c srcs/ft_images.c srcs/ft_moove.c srcs/ft_key.c srcs/ft_map_utils.c srcs/ft_maplen.c
OBJS			=	$(SRCS:.c=.o)

all:			$(NAME)

$(NAME): $(OBJS) 
		$(LIBFT)
		$(MINILIBX)
		$(CC) $(OBJS) $(LIBFT_EX) $(MINILIBX_EX)  $(STANDARD_FLAGS) $(MINILIBX_FLAGS) -o $(NAME)
				@echo "$(NAME): $(GREEN)Compiled.$(RESET) 👍"
				@echo

clean:
		$(REMOVE) $(OBJS)
		@if [ -d "$(MINILIBX_PATH)" ]; then \
            make clean -sC $(MINILIBX_PATH); \
        fi
		@if [ -d "$(LIBFT_PATH)" ]; then \
            make clean -sC $(LIBFT_PATH); \
        fi
		@echo "$(NAME): $(RED)$ Deleted.$(RESET) 👍"
		@echo

fclean:
				$(REMOVE) $(OBJS)
				@echo "$(NAME): $(RED)$ Deleted.$(RESET) 👍"
				@echo

re:				fclean all

.PHONY:			all clean fclean re valgrind