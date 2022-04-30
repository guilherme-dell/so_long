/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:11:57 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/30 06:50:33 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	wordcount(const char *str, char c)
{
	int		counter;
	size_t	words;

	counter = 0;
	words = 0;
	while (str[counter] != '\0' && str[counter] == c)
	{
		counter++;
	}
	while (str[counter] != '\0')
	{
		while (str[counter] != '\0' && str[counter] != c)
			counter++;
		words++;
		while (str[counter] != '\0' && str[counter] == c)
			counter++;
	}
	return (words);
}

static size_t	wordlen(char const *str, char c)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0' && str[counter] != c)
		counter++;
	return (counter);
}

char	**ft_split(char const *str, char c)
{
	char	**arrayret;
	int		i;
	size_t	words;

	i = -1;
	if (!str)
		return (NULL);
	words = wordcount(str, c);
	arrayret = (char **) malloc((words + 1) * sizeof(char *));
	if (!arrayret)
		return (NULL);
	words = 0;
	while ((str[++i]))
	{
		if (str[i] != c && str[i] != '\0')
		{
			arrayret[words] = ft_substr(str, i, wordlen(&str[i], c));
			words++;
			i = (i + wordlen(&str[i], c) - 1);
		}
	}
	arrayret[words] = NULL;
	return (arrayret);
}

t_image	ft_new_sprite(void *mlx, char *img_path, t_game *game)
{
	t_image	img;

	img.ptr = mlx_xpm_file_to_image(mlx, img_path, &img.x, &img.y);
	if (img.ptr == NULL)
		ft_error_msg(game, RED"ERROR: "GREY"read xpm\n"RESET);
	img.pxl = mlx_get_data_addr(img.ptr, &img.bpp, &img.l_size, &img.endian);
	return (img);
}

void	ft_redraw_player(t_game *game, char *path)
{
	mlx_destroy_image(game->mlx_ptr, game->player.ptr);
	game->player.path = path;
	game->player = ft_new_sprite(game->mlx_ptr, game->player.path, game);
}
