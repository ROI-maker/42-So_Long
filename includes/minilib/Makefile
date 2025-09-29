NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

LIBFT_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
             ft_toupper.c ft_tolower.c ft_atoi.c ft_memcmp.c ft_strncmp.c \
             ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_bzero.c ft_putnbr_fd.c \
             ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_memset.c ft_calloc.c \
             ft_memchr.c ft_memcpy.c ft_striteri.c ft_itoa.c ft_strdup.c ft_split.c \
             ft_strrchr.c ft_strjoin.c ft_strtrim.c ft_strmapi.c ft_substr.c \
             ft_strnstr.c ft_strchr.c ft_memmove.c

PRINTF_SRCS = ft_printf/ft_printf.c ft_printf/ft_printf_utils1.c ft_printf/ft_printf_utils2.c

GNL_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS = $(LIBFT_SRCS) $(PRINTF_SRCS) $(GNL_SRCS)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c libft.h ft_printf/ft_printf.h get_next_line/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
