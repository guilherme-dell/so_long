/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:24:19 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/05/02 04:04:36 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error_msg(t_game *game, char	*message)
{
	ft_printf(message);
	ft_free_string_array(game->map.map_lines);
	free(game);
	exit(EXIT_FAILURE);
}

void	ft_you_win(void)
{
	ft_printf(WIN"\
██    ██  ██████  ██    ██     ██     ██ ██ ███    ██\n\
 ██  ██  ██    ██ ██    ██     ██     ██ ██ ████   ██\n\
  ████   ██    ██ ██    ██     ██  █  ██ ██ ██ ██  ██\n\
   ██    ██    ██ ██    ██     ██ ███ ██ ██ ██  ██ ██\n\
   ██     ██████   ██████       ███ ███  ██ ██   ████\n\
"RESET);
}

void	ft_you_lose(void)
{
	ft_printf(LOSE"\
▓██   ██▓ ▒█████   █    ██     ██▓     ▒█████    ██████ ▓█████\n\
 ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▓██▒    ▒██▒  ██▒▒██    ▒ ▓█   ▀\n\
  ▒██ ██░▒██░  ██▒▓██  ▒██░   ▒██░    ▒██░  ██▒░ ▓██▄   ▒███\n\
  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ▒██░    ▒██   ██░  ▒   ██▒▒▓█  ▄\n\
  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░██████▒░ ████▓▒░▒██████▒▒░▒████▒\n\
   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░░ ▒░ ░\n\
 ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░    ░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░ ░ ░  ░\n\
 ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░ ░   ░ ░ ░ ▒  ░  ░  ░     ░\n\
 ░ ░         ░ ░     ░            ░  ░    ░ ░        ░     ░  ░\n\
 ░ ░\n\
"RESET);
}

void	ft_line_empty(t_game *game, char *map_full)
{
	int	x;

	x = 0;
	while (map_full[x] != '\0')
	{
		if ((map_full[x] == '\n' && map_full[x + 1] == '\n')
			|| (map_full[0] == '\n')
			|| (map_full[ft_strlen(map_full) - 1] == '\n'))
		{
			ft_printf(RED"Error\n"GREY"empty line in map\n"RESET);
			free(map_full);
			free(game);
			exit(EXIT_FAILURE);
		}
		x++;
	}
}
