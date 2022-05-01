/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 06:27:26 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/30 06:44:41 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valide_move(t_game *game, char move)
{
	if (move == WALL)
		return (0);
	else if (move == KEYS)
	{
		game->map.keys = game->map.keys - 1;
		return (1);
	}
	else if (move == EXIT_OPEN)
	{
		game->moves++;
		ft_printf("Movement count:"GREEN"%d\n"RESET, game->moves);
		ft_you_win();
		return (close_game(game));
	}
	else if (move == MAP_EXIT && game->map.keys != 0)
		return (0);
	else if (move == SPIKE)
	{
		game->moves++;
		ft_printf("Movement count:"GREEN"%d\n"RESET, game->moves);
		ft_you_lose();
		return (close_game(game));
	}
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
		ft_redraw_player(game, "./sprites/move_w.xpm");
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
		ft_redraw_player(game, "./sprites/move_a.xpm");
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
		ft_redraw_player(game, "./sprites/move_s.xpm");
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
		ft_redraw_player(game, "./sprites/move_d.xpm");
		ft_draw_map(game);
		ft_print_moves(game);
		ft_printf("Movement count:"GREEN"%d\n"RESET, game->moves);
	}
}
