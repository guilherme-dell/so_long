/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_lines_validator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 00:42:23 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/05/02 06:16:54 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(char	*map)
{
	int	cnt1;
	int	cnt2;

	cnt1 = 0;
	cnt2 = 0;
	while (map[cnt1] != '\0')
	{
		if (map[cnt1] == '\n')
			cnt2++;
		cnt1++;
	}
	return (cnt2);
}

void	ft_check_map_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if ((game->map.map_lines[0][i] != WALL)
		|| (game->map.map_lines[game->map.number_lines][i] != WALL))
		{
			ft_error_msg(game, RED"Error\n"GREY"missing horizontal wall\n"\
			RESET);
			break ;
		}
		i++;
	}
}

void	ft_check_map_lines(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.number_lines)
	{
		if ((int) ft_strlen(game->map.map_lines[i]) != game->map.columns)
			ft_error_msg(game, RED"Error\n"GREY"map is not rectangular\n"\
			RESET);
		if ((game->map.map_lines[i][0] != WALL)
		|| (game->map.map_lines[i][game->map.columns - 1] != WALL))
		{
			ft_error_msg(game, RED"Error\n"GREY"vertical wall is missing\n"\
			RESET);
			break ;
		}
		i++;
	}
	if (((ft_strlen(game->map.map_lines[game->map.number_lines]) \
		> game->map.columns)))
		ft_error_msg(game, RED"Error\n"GREY"map is not rectangular\n"\
			RESET);
	ft_check_map_columns(game);
}
