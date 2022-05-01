/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extension_validator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:48:37 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/05/01 07:13:38 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verify_map_extension(int argc, char **argv, t_game *game)
{
	int	map_len;

	if (argc > 2 || argc < 2)
		ft_error_msg(game, RED"Error\n"GREY"invalid argument\n"RESET);
	map_len = ft_strlen(argv[1]);
	if ((ft_strncmp(argv[1], ".ber", 4)) == 0)
		ft_error_msg(game, RED"Error\n"GREY"only the extension is not valid\n"\
		RESET);
	if (!ft_strnstr(&argv[1][map_len - 4], ".ber", 4))
		ft_error_msg(game, RED"Error\n"GREY"invalid extension \n"RESET);
}
