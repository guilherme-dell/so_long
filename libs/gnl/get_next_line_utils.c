/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 19:05:15 by gnuncio-          #+#    #+#             */
/*   Updated: 2021/08/26 19:05:15 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

int	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

char	*ft_strchr(const char *string, int c)
{
	if (!string)
		return (NULL);
	while (*string)
	{
		if (*string == (char) c)
			return ((char *) string);
		string++;
	}
	if ((char) c == '\0')
		return (0);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str) + 1;
	cpy = malloc(len * sizeof(char));
	if (!cpy)
		return (0);
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	len_str1;
	size_t	len_str2;
	char	*new_str;

	if (!str1 || !str2)
		return (NULL);
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	new_str = malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (new_str == NULL)
		return (NULL);
	while (*str1)
		*(new_str++) = *(str1++);
	while (*str2)
		*(new_str++) = *(str2++);
	*new_str = '\0';
	return (new_str - (len_str1 + len_str2));
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	if (!str)
		return (NULL);
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while ((i < len) && ((start + i) < (unsigned int )ft_strlen(str))
		&& (str[start + i] != '\0'))
	{
		sub_str[i] = str[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
