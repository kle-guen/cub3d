-include ./configuration/Sources.mk
-include ./configuration/Includes.mk
-include ./configuration/Bonus.mk

NAME		= cub3D

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -I $(INCLUDES_DIR) -I libft -I gnl -I minilibx-linux

SRCS		+= gnl/get_next_line.c
SRCS		+= gnl/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)
OBJS_DIR 	= objects
OBJS_PATH	= $(addprefix $(OBJS_DIR)/, $(OBJS))

BONUS		+= gnl/get_next_line.c
BONUS		+= gnl/get_next_line_utils.c

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[2K\r\033[3;35m$<: \033[3;36mloading..\033[0m"

B_OBJS		= $(BONUS:.c=.o)
B_OBJS_DIR 	= objects
B_OBJS_PATH	= $(addprefix $(B_OBJS_DIR)/, $(B_OBJS))

$(B_OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[2K\r\033[3;35m$<: \033[3;36mloading..\033[0m"

$(NAME): $(OBJS_PATH)
	@$(MAKE) --no-print-directory -C libft/
	@printf "\033[2K\r\033[4;34mlibft:\033[0m \033[1;32mCompiled \033[1;32m[√]\033[0m\n"
	@$(MAKE) --no-print-directory -C minilibx-linux/
	@printf "\033[2K\r\033[4;34mminilibx-linux:\033[0m \033[1;32mCompiled \033[1;32m[√]\033[0m\n"
	@$(CC) $(CFLAGS) $(OBJS_PATH) minilibx-linux/libmlx.a libft/libft.a -o $(NAME) -lXext -lX11 -lm
	@printf "\033[2K\r\033[4;34m$(NAME):\033[0m \033[1;32mCompiled [√]\033[0m\n"

all: $(NAME)

clean:
	@$(MAKE) --no-print-directory -C libft/ clean
	@printf "\033[2K\r\033[4;34mlibft:\033[0m \033[1;31mObject Delete \033[1;32m[√]\033[0m\n"
	@$(MAKE) --no-print-directory -C minilibx-linux/ clean
	@printf "\033[2K\r\033[4;34mminilibx-linux:\033[0m \033[1;31mObject Delete \033[1;32m[√]\033[0m\n"
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r\033[4;34m$(NAME):\033[0m \033[1;31mObject Delete \033[1;32m[√]\033[0m\n"

fclean: clean
	@$(MAKE) --no-print-directory -C libft/ fclean
	@printf "\033[2K\r\033[4;34mlibft:\033[0m \033[1;31mLibft Delete \033[1;32m[√]\033[0m\n"
	@rm -rf $(NAME)
	@printf "\033[2K\r\033[4;34m$(NAME):\033[0m \033[1;31m$(NAME) Delete \033[1;32m[√]\033[0m\n"

re: fclean all

bonus: $(B_OBJS_PATH)
	@$(MAKE) --no-print-directory -C libft/
	@printf "\033[2K\r\033[4;34mlibft:\033[0m \033[1;32mCompiled \033[1;32m[√]\033[0m\n"
	@$(MAKE) --no-print-directory -C minilibx-linux/
	@printf "\033[2K\r\033[4;34mminilibx-linux:\033[0m \033[1;32mCompiled \033[1;32m[√]\033[0m\n"
	@$(CC) $(CFLAGS) $(B_OBJS_PATH) minilibx-linux/libmlx.a libft/libft.a -o $(NAME) -lXext -lX11 -lm
	@printf "\033[2K\r\033[4;34m$(NAME):\033[0m \033[1;32mCompiled [√]\033[0m\n"

.PHONY: all clean fclean re bonus