NAME = so_long
NAME_BONUS = so_long_bonus

GREEN		= \033[0;32m
RED		= \033[0;31m
RESET		= \033[0m

CC = gcc -g3

FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11 -lm
MAKE_NOPRINT = $(MAKE) --no-print-directory
INCLUDES = -I ./ -I ./libs/gnl -I ./libs/ft_printf

SRC =	sources/destroyer_memory.c				\
		sources/error_msg.c						\
		sources/game_events.c					\
		sources/init_all.c						\
		sources/init_args.c						\
		sources/map_designer.c					\
		sources/map_extension_validator.c		\
		sources/map_init.c						\
		sources/map_lines_validator.c			\
		sources/map_parameters_validator.c		\
		sources/movement.c						\
		sources/so_long.c						\
		sources/utils_1.c						\
		sources/utils_2.c

SRC_BONUS =	bonus/destroyer_memory_bonus.c			\
			bonus/error_msg_bonus.c					\
			bonus/game_events_bonus.c				\
			bonus/init_all_bonus.c					\
			bonus/init_args_bonus.c					\
			bonus/map_designer_bonus.c				\
			bonus/map_extension_validator_bonus.c	\
			bonus/map_init_bonus.c					\
			bonus/map_lines_validator_bonus.c		\
			bonus/map_parameters_validator_bonus.c	\
			bonus/movement_bonus.c					\
			bonus/so_long_bonus.c					\
			bonus/utils_1_bonus.c					\
			bonus/utils_2_bonus.c

SRC_GNL = ./libs/gnl/*.c
PRINTF_PATH = libs/ft_printf/
FT_PRINTF = libs/ft_printf/libftprintf.a


all: $(NAME)

bonus: $(NAME_BONUS)

$(FT_PRINTF):
	@$(MAKE_NOPRINT) -C $(PRINTF_PATH)

$(NAME):${FT_PRINTF} so_long.h
	@$(CC) $(INCLUDES) $(FLAGS) $(SRC) $(SRC_GNL) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)so_long compiled :) $(RESET)"

$(NAME_BONUS):${FT_PRINTF} so_long.h
	@$(CC) $(INCLUDES) $(FLAGS) $(SRC_BONUS) $(SRC_GNL) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)so_long_bonus compiled :) $(RESET)"

clean:
	@$(MAKE_NOPRINT) clean -C $(PRINTF_PATH)
	@echo "$(RED)compilation files deleted $(RESET)"

fclean:	clean
	@$(MAKE_NOPRINT) fclean -C ${PRINTF_PATH}
	@rm -fr $(NAME)
	@echo "$(RED)$(NAME) was deleted $(RESET)"

fclean_bonus:	clean
	@$(MAKE_NOPRINT) fclean -C ${PRINTF_PATH}
	@rm -fr $(NAME_BONUS)
	@echo "$(RED)$(NAME_BONUS) was deleted $(RESET)"

re: fclean all

val:
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes ./$(NAME) ./maps/map_1.ber
run:
	@./$(NAME) ./maps/map_1.ber

.PHONY: all clean fclean re bonus fclean_bonus