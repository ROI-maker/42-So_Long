# **************************************************************************** #
#                                 SO_LONG MAKEFILE                             #
# **************************************************************************** #

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes/minilib -Iincludes/minilib/ft_printf -Iincludes/minilibx-linux
LDFLAGS = -Lincludes/minilib -lft -Lincludes/minilibx-linux -lmlx_Linux -lXext -lX11 -lm

# Colors
GREEN  = \033[0;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
RED    = \033[1;31m
RESET  = \033[0m

# Directories
MANDATORY_DIR = mandatory
BONUS_DIR     = bonus

# **************************************************************************** #
#                            MANDATORY CONFIG                                  #
# **************************************************************************** #

MANDATORY_SRC = $(MANDATORY_DIR)/src/main.c \
				$(MANDATORY_DIR)/src/map/map.c \
				$(MANDATORY_DIR)/src/map/map_checker.c \
				$(MANDATORY_DIR)/src/map/path_checker.c \
				$(MANDATORY_DIR)/src/player/player.c \
				$(MANDATORY_DIR)/src/utils/exit.c \
				$(MANDATORY_DIR)/src/utils/init_struct.c \
				$(MANDATORY_DIR)/src/utils/ft_free_all.c \
				$(MANDATORY_DIR)/src/graphics/graphics.c \
				$(MANDATORY_DIR)/src/gameplay/gameplay.c

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
MANDATORY_NAME = $(MANDATORY_DIR)/so_long

# **************************************************************************** #
#                              BONUS CONFIG                                    #
# **************************************************************************** #

BONUS_SRC = $(BONUS_DIR)/src/main.c \
			$(BONUS_DIR)/src/map/map.c \
			$(BONUS_DIR)/src/map/map_checker.c \
			$(BONUS_DIR)/src/map/path_checker.c \
			$(BONUS_DIR)/src/player/player.c \
			$(BONUS_DIR)/src/utils/exit.c \
			$(BONUS_DIR)/src/utils/init_struct.c \
			$(BONUS_DIR)/src/utils/ft_free_all.c \
			$(BONUS_DIR)/src/graphics/graphics.c \
			$(BONUS_DIR)/src/graphics/graphics_utils.c \
			$(BONUS_DIR)/src/graphics/load_images.c \
			$(BONUS_DIR)/src/gameplay/gameplay.c \
			$(BONUS_DIR)/src/gameplay/gameplay_utils.c \
			$(BONUS_DIR)/src/timer/timer.c \
			$(BONUS_DIR)/src/timer/scores.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_NAME = $(BONUS_DIR)/so_long

# **************************************************************************** #
#                                  RULES                                        #
# **************************************************************************** #

# -------------------- Mandatory -------------------- #
all: $(MANDATORY_NAME)

$(MANDATORY_NAME): $(MANDATORY_OBJ)
	@echo "$(YELLOW)[Linking mandatory]$(RESET)"
	@$(CC) $(MANDATORY_OBJ) $(LDFLAGS) -o $@
	@echo "$(GREEN)✔ Mandatory build complete!$(RESET)"

clean:
	@echo "$(RED)[Cleaning mandatory objects]$(RESET)"
	@rm -f $(MANDATORY_OBJ)

fclean: clean
	@echo "$(RED)[Removing mandatory binary]$(RESET)"
	@rm -f $(MANDATORY_NAME)

re: fclean all

# -------------------- Bonus -------------------- #
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	@echo "$(YELLOW)[Linking bonus]$(RESET)"
	@$(CC) $(BONUS_OBJ) $(LDFLAGS) -o $@
	@echo "$(GREEN)✔ Bonus build complete!$(RESET)"

bonus_clean:
	@echo "$(RED)[Cleaning bonus objects]$(RESET)"
	@rm -f $(BONUS_OBJ)

bonus_fclean: bonus_clean
	@echo "$(RED)[Removing bonus binary]$(RESET)"
	@rm -f $(BONUS_NAME)

bonus_re: bonus_fclean bonus

# -------------------- Compilation -------------------- #
%.o: %.c
	@echo "$(GREEN)[Compiling]$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all re clean fclean bonus bonus_clean bonus_fclean bonus_re
