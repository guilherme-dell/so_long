/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parameters_validator.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 00:41:48 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/30 04:04:31 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_valid_game_parameters(t_game *game)
{
	if (game->map.player < 1)
		ft_error_msg(game, RED"ERROR: "GREY"player not found\n"RESET);
	if (game->map.player > 1)
		ft_error_msg(game, RED"ERROR: "GREY"more than one player\n"RESET);
	if (game->map.keys < 1)
		ft_error_msg(game, RED"ERROR: "GREY"game without collectibles\n"RESET);
	if (game->map.exit < 1)
		ft_error_msg(game, RED"ERROR: "GREY"game without exit\n"RESET);
	if (game->map.exit > 1)
		ft_error_msg(game, RED"ERROR: "GREY"more than one exit\n"RESET);
}

void	ft_init_game(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.number_lines + 1)
	{
		y = 0;
		while (y < game->map.columns)
		{
			if (game->map.map_lines[x][y] == PLAYER)
				game->map.player++;
			if (game->map.map_lines[x][y] == KEYS)
				game->map.keys++;
			if (game->map.map_lines[x][y] == MAP_EXIT)
				game->map.exit++;
			y++;
		}
		x++;
	}
	ft_valid_game_parameters(game);
}

void	ft_valid_map_parameters(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x <= game->map.number_lines)
	{
		y = 0;
		while (y < game->map.columns)
		{
			if (game->map.map_lines[x][y] == WALL
			|| game->map.map_lines[x][y] == FLOOR
			|| game->map.map_lines[x][y] == PLAYER
			|| game->map.map_lines[x][y] == KEYS
			|| game->map.map_lines[x][y] == MAP_EXIT
			|| game->map.map_lines[x][y] == SPIKE)
				y++;
			else
			{
				ft_error_msg(game, RED"ERROR: "GREY"Invalid parameters map\n"\
				RESET);
				break ;
			}
		}
		x++;
	}
}
