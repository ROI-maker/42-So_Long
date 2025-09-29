# **************************************************************************** #
#                              MAKEFILE - FT_PRINTF                            #
# **************************************************************************** #

NAME    := libftprintf.a

CC      := cc
CFLAGS  := -Wall -Wextra -Werror
AR      := ar rcs
RM      := rm -f

SRCS    := ft_printf.c \
           ft_printf_utils1.c \
           ft_printf_utils2.c

OBJS    := ft_printf.o ft_printf_utils1.o ft_printf_utils2.o

# =============================== COLORS ===================================== #
GREEN   := \033[32m
YELLOW  := \033[33m
RED     := \033[31m
BLUE    := \033[34m
RESET   := \033[0m

# =============================== RULES ====================================== #

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)[OK] $(NAME) created$(RESET)"

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling:$(RESET) $<"

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)[Clean] Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)[Fclean] $(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
