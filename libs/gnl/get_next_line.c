/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:02:10 by gnuncio-          #+#    #+#             */
/*   Updated: 2021/09/05 02:43:45 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*last_line(char **buffer_temp)
{
	char	*temp;

	if (!*buffer_temp)
		return (NULL);
	if (**buffer_temp == 0)
	{
		free(*buffer_temp);
		return (NULL);
	}
	temp = ft_strdup(*buffer_temp);
	free (*buffer_temp);
	*buffer_temp = NULL;
	return (temp);
}

char	*oflw_upd(char *buffer_temp, char *buffer_read)
{
	char	*temp;

	temp = ft_strjoin (buffer_temp, buffer_read);
	free(buffer_temp);
	buffer_temp = ft_strdup(temp);
	free(temp);
	temp = 0;
	return (buffer_temp);
}

char	*residue_ret(char *buffer)
{
	char	*pos_n;
	char	*temp;
	char	pox;
	int		buffer_size;

	if (ft_strlen(buffer) == 0)
		return (0);
	buffer_size = ft_strlen(buffer);
	pos_n = ft_strchr(buffer, '\n') + 1;
	pox = (pos_n - buffer);
	temp = ft_substr(buffer, pox, buffer_size);
	free(buffer);
	buffer = ft_strdup(temp);
	free(temp);
	return (buffer);
}

char	*beautiful_ret(char *buffer)
{
	char	*pos_n;
	char	*temp;

	if (!buffer)
		return (0);
	pos_n = ft_strchr(buffer, '\n') + 1;
	temp = ft_substr(buffer, 0, (pos_n - buffer));
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer_temp;
	int			i;
	char		buffer_read[BUFFER_SIZE + 1];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		if (ft_strchr(buffer_temp, '\n') && buffer_temp != 0)
		{
			ret = beautiful_ret(buffer_temp);
			buffer_temp = residue_ret(buffer_temp);
			return (ret);
		}
		i = read (fd, buffer_read, BUFFER_SIZE);
		buffer_read[i] = '\0';
		if (!buffer_temp && i > 0)
			buffer_temp = ft_strdup(buffer_read);
		else if (i > 0)
			buffer_temp = oflw_upd(buffer_temp, buffer_read);
	}
	return (last_line(&buffer_temp));
}
