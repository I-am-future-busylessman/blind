NAME = libft.a

SRCS =  ft_printf.c \
	precision.c \
	print_cs.c \
	print_diu.c \
	print_px.c \
	save_args.c \
	utils.c \
	width.c \
	ft_putchar.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isblank_bonus.c \
	ft_islower_bonus.c \
	ft_isupper_bonus.c \
	ft_strdel_bonus.c \
	ft_isspace_bonus.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	get_next_line.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstsize.c \
	ft_lstadd_front.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstlast.c \
	ft_lstnew.c \
	
CC = gcc

CFLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I ./

OFILES = $(SRCS:.c=.o)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OFILES)

all : $(NAME)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
