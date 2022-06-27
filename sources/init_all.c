/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:11:55 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/05/02 01:38:31 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		ft_error_msg(game, RED"MLX_ERROR: "GREY"mlx not initialising.\n"RESET);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->width, \
	game->height, TITLE);
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		ft_error_msg(game, RED"MLX_ERROR: "GREY"failed to create window.\n"\
		RESET);
	}
}

void	ft_init_all(t_game *game, int argc, char **argv)
{
	ft_init_map_args(game);
	ft_create_paths(game);
	ft_verify_map_extension(argc, argv, game);
	ft_init_map(argv[1], game);
	ft_check_map_lines(game);
	ft_init_game(game);
	ft_valid_map_parameters(game);
	init_mlx(game);
}
