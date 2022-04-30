/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:20:05 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/30 03:50:08 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_init_all(game, argc, argv);
	ft_create_sprites(game);
	ft_draw_map(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &ft_handle_input, game);
	mlx_hook(game->win_ptr, DestroyNotify, NoEventMask, &close_game, game);
	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	mlx_expose_hook(game->win_ptr, &ft_redraw, game);
	mlx_loop(game->mlx_ptr);
	ft_destroy_all(game);
}
