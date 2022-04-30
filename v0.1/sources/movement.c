/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 06:27:26 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/29 21:07:57 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valide_move(t_game *game, char map)
{
	if (map == WALL)
		return (0);
	else if (map == KEYS)
	{
		game->map.keys = game->map.keys - 1;
		return (1);
	}
	else if (map == EXIT_OPEN)
		return (close_game(game));
	else if (map == MAP_EXIT && game->map.keys != 0)
		return (0);
	else
		return (1);
}

void	ft_move_w(t_game *game)
{
	if (ft_valide_move(game, \
	game->map.map_lines[game->player.y - 1][game->player.x]))
	{
		game->map.map_lines[game->player.y][game->player.x] = FLOOR;
		game->map.map_lines[game->player.y - 1][game->player.x] = PLAYER;
		game->moves++;
		ft_open_door(game, game->map.keys);
		ft_draw_map(game);
		ft_print_moves(game);
		ft_printf("Movement count:"GREEN"%d\n"RESET, game->moves);
	}
}

void	ft_move_a(t_game *game)
{
	if (ft_valide_move(game, \
	game->map.map_lines[game->player.y][game->player.x - 1]))
	{
		game->map.map_lines[game->player.y][game->player.x] = FLOOR;
		game->map.map_lines[game->player.y][game->player.x - 1] = PLAYER;
		game->moves++;
		ft_open_door(game, game->map.keys);
		ft_draw_map(game);
		ft_print_moves(game);
		ft_printf("Movement count:"GREEN"%d\n"RESET, game->moves);
	}
}

void	ft_move_s(t_game *game)
{
	if (ft_valide_move(game, \
	game->map.map_lines[game->player.y + 1][game->player.x]))
	{
		game->map.map_lines[game->player.y][game->player.x] = FLOOR;
		game->map.map_lines[game->player.y + 1][game->player.x] = PLAYER;
		game->moves++;
		ft_open_door(game, game->map.keys);
		ft_draw_map(game);
		ft_print_moves(game);
		ft_printf("Movement count:"GREEN"%d\n"RESET, game->moves);
	}
}

void	ft_move_d(t_game *game)
{
	if (ft_valide_move(game, \
	game->map.map_lines[game->player.y][game->player.x + 1]))
	{
		game->map.map_lines[game->player.y][game->player.x] = FLOOR;
		game->map.map_lines[game->player.y][game->player.x + 1] = PLAYER;
		game->moves++;
		ft_open_door(game, game->map.keys);
		ft_draw_map(game);
		ft_print_moves(game);
		ft_printf("Movement count:"GREEN"%d\n"RESET, game->moves);
	}
}
