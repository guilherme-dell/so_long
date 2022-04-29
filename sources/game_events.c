/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:54:51 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/30 01:41:02 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == KEY_ESC)
		close_game(game);
	if (keysym == KEY_W || keysym == KEY_UP)
		ft_move_w(game);
	if (keysym == KEY_A || keysym == KEY_LEFT)
		ft_move_a(game);
	if (keysym == KEY_S || keysym == KEY_DOWN)
		ft_move_s(game);
	if (keysym == KEY_D || keysym == KEY_RIGHT)
		ft_move_d(game);
	return (0);
}

int	ft_redraw(t_game *game)
{
	ft_draw_map(game);
	ft_print_moves(game);
	return (0);
}

int	handle_no_event(void)
{
	return (0);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_destroy_all(game);
	exit(0);
	return (0);
}

void	ft_print_moves(t_game *game)
{
	char	*text;
	int		moves;

	moves = game->moves;
	text = ft_itoa(moves);
	game->text = text;
	mlx_string_put(game->mlx_ptr, game->win_ptr, 48, 20, YELLOW, text);
	free(text);
}
