PRINTF = ./libft/libft.a

NAME = cub3d.a

SRCS =  src/parser.c \
		src/init.c \
		src/map_handlers.c \
		src/checkers.c \
		src/cub3d_utils.c \
		src/display.c\
		src/key_actions.c\
		src/sprites.c\

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror 

INCLUDES = -I ./

OFILES = $(SRCS:.c=.o)

$(NAME): $(OFILES)
	$(MAKE) -C ./libft
	cp $(PRINTF) $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OFILES)
	gcc start.c -L/ -lmlx -framework OpenGL -framework AppKit cub3d.a -g

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf src/*.o
	rm -rf *.o

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf src/*.o
	rm -rf $(NAME)

re : fclean all