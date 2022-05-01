/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:24:19 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/30 05:23:01 by gnuncio-         ###   ########.fr       */
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