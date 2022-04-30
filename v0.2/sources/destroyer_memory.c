/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:01:46 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/30 04:50:26 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_string_array(char **free_me)
{
	char	**free_me_too;

	free_me_too = free_me;
	while (*free_me)
		free(*free_me++);
	free(free_me_too);
}

void	ft_destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall.ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.ptr);
	mlx_destroy_image(game->mlx_ptr, game->player.ptr);
	mlx_destroy_image(game->mlx_ptr, game->key.ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit.ptr);
	mlx_destroy_image(game->mlx_ptr, game->door_open.ptr);
	mlx_destroy_image(game->mlx_ptr, game->spike.ptr);
}

void	ft_destroy_all(t_game *game)
{
	ft_destroy_images(game);
	ft_free_string_array(game->map.map_lines);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}
