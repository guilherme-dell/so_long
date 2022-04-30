/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:08:01 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/30 04:18:18 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map_args(t_game *game)
{
	game->map.columns = 0;
	game->map.number_lines = 0;
	game->map.map_lines = 0;
	game->map.player = 0;
	game->map.keys = 0;
	game->map.exit = 0;
	game->map.enemys = 0;
	game->width = 0;
	game->height = 0;
	game->moves = 0;
	game->text = "TESTE";
}

void	ft_create_paths(t_game *game)
{
	game->wall.path = "./sprites/wall.xpm";
	game->floor.path = "./sprites/floor.xpm";
	game->player.path = "./sprites/player.xpm";
	game->key.path = "./sprites/key.xpm";
	game->exit.path = "./sprites/door_close.xpm";
	game->door_open.path = "./sprites/door_open.xpm";
	game->spike.path = "./sprites/spikes.xpm";
}

void	ft_create_sprites(t_game *game)
{
	game->wall = ft_new_sprite(game->mlx_ptr, game->wall.path, game);
	game->floor = ft_new_sprite(game->mlx_ptr, game->floor.path, game);
	game->player = ft_new_sprite(game->mlx_ptr, game->player.path, game);
	game->key = ft_new_sprite(game->mlx_ptr, game->key.path, game);
	game->exit = ft_new_sprite(game->mlx_ptr, game->exit.path, game);
	game->door_open = ft_new_sprite(game->mlx_ptr, game->door_open.path, game);
	game->spike = ft_new_sprite(game->mlx_ptr, game->spike.path, game);
}

void	ft_data_map(t_game *game, char *map_full)
{
	game->map.number_lines = ft_count_lines(map_full);
	game->map.map_lines = ft_split(map_full, '\n');
	game->map.columns = ft_strlen(game->map.map_lines[0]);
	game->width = game->map.columns * PIXEL;
	game->height = (game->map.number_lines + 1) * PIXEL;
}
