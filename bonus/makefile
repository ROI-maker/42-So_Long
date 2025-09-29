NAME = so_long

SRC_DIR = src
SRC_DIR_MAP = src/map
SRC_DIR_PLAYER = src/player
SRC_DIR_UTILS = src/utils
SRC_DIR_GRAPHICS = src/graphics
SRC_DIR_GAMEPLAY = src/gameplay
SRC_DIR_TIMER = src/timer
INC_DIR = ../includes/minilib
LIBFT_DIR = ../includes/minilib
MLX_DIR = ../includes/minilibx-linux

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR_MAP)/map.c \
      $(SRC_DIR_MAP)/map_checker.c \
      $(SRC_DIR_MAP)/path_checker.c \
      $(SRC_DIR_PLAYER)/player.c \
      $(SRC_DIR_UTILS)/exit.c \
      $(SRC_DIR_UTILS)/init_struct.c \
      $(SRC_DIR_UTILS)/ft_free_all.c \
      $(SRC_DIR_GRAPHICS)/graphics.c \
	  $(SRC_DIR_GRAPHICS)/graphics_utils.c \
	  $(SRC_DIR_GRAPHICS)/load_images.c \
      $(SRC_DIR_GAMEPLAY)/gameplay.c \
	  $(SRC_DIR_GAMEPLAY)/gameplay_utils.c \
	  $(SRC_DIR_TIMER)/timer.c \
	  $(SRC_DIR_TIMER)/scores.c \

# Objets
OBJ = $(SRC:.c=.o)

# Compil && flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(INC_DIR)/ft_printf -I$(MLX_DIR)
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm

GREEN = \033[0;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RED = \033[1;31m
RESET = \033[0m

# Rules
all: banner $(NAME)
	@echo "$(GREEN)✔ Build terminé avec succès !$(RESET)"

banner:
	@echo "$(BLUE)====================================$(RESET)"
	@echo "$(YELLOW)        🚀🚀🚀  $(NAME) 🚀🚀🚀    $(RESET)"
	@echo "$(BLUE)====================================$(RESET)"

$(NAME): $(OBJ)
	@echo "$(YELLOW)[Linking]$(RESET) $@"
	@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@echo "$(GREEN)[Compiling]$(RESET) $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)[Cleaning objs]$(RESET)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED)[Removing binary]$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re banner
