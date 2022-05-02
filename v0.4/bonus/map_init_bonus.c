/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:27:39 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/05/02 01:52:53 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close_game_init(char *err_msg, t_game *game)
{
	free(game);
	ft_printf(err_msg);
	exit(EXIT_FAILURE);
}

void	ft_init_map(char *argv, t_game *game)
{
	char	*map_full;
	char	*map_line;
	char	*temp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_close_game_init(RED"Error\n"GREY"invalid map name \n"RESET, game);
	map_full = ft_strdup("");
	map_line = get_next_line(map_fd);
	while (map_line)
	{
		if (map_line == 0)
			break ;
		temp = map_full;
		map_full = ft_strjoin(temp, map_line);
		free(temp);
		free(map_line);
		map_line = get_next_line(map_fd);
	}
	free(map_line);
	close(map_fd);
	ft_data_map(game, map_full);
	free(map_full);
}
