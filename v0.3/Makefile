NAME = so_long

GREEN		= \033[0;32m
RED		= \033[0;31m
RESET		= \033[0m

CC = gcc -g3

FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11 -lm
MAKE_NOPRINT = $(MAKE) --no-print-directory

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

SRC_GNL = ./libs/gnl/*.c
PRINTF_PATH = libs/ft_printf/
FT_PRINTF = libs/ft_printf/libftprintf.a



all: $(NAME)

$(FT_PRINTF):
	@$(MAKE_NOPRINT) -C $(PRINTF_PATH)

$(NAME):${FT_PRINTF}
	@$(CC) $(FLAGS) $(SRC) $(SRC_GNL) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)so_long compiled :) $(RESET)"

clean:
	@$(MAKE_NOPRINT) clean -C $(PRINTF_PATH)
	@rm $(NAME)
	@echo "$(RED)so_long was delete $(NAME) $(RESET)"

fclean:
	@$(MAKE_NOPRINT) fclean -C ${PRINTF_PATH}
	@rm -fr $(NAME)

re: fclean all

val:
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes ./$(NAME) ./maps/map_1.ber
run:
	@./$(NAME) ./maps/map_1.ber

.PHONY: all clean fclean re