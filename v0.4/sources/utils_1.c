/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:24:48 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/29 21:14:17 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char		*aux1;
	unsigned char		*aux2;
	size_t				i;

	aux1 = (unsigned char *)dest;
	aux2 = (unsigned char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while (i < len)
	{
		aux1[i] = aux2[i];
		i++;
	}
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned char	*aux1;
	unsigned char	*aux2;
	size_t			i;

	i = 0;
	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	while ((aux1[i] != '\0' || aux2[i] != '\0') && i < len)
	{
		if (aux1[i] != aux2[i])
			return (aux1[i] - aux2[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *str, const char *target, size_t len)
{
	size_t	target_len;
	size_t	i;

	i = 0;
	target_len = ft_strlen(target);
	if (*target == '\0')
		return ((char *)str);
	while ((*str != '\0') && (i < len))
	{
		if ((ft_strncmp(str, target, target_len) == 0) && (i + \
		target_len <= len))
			return ((char *) str);
		str++;
		i++;
	}
	return (NULL);
}

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*aux;
	unsigned char	caracter;
	size_t			i;

	i = 0;
	caracter = (unsigned char)c;
	aux = (unsigned char *)str;
	while (i < len)
	{
		aux[i] = caracter;
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t len)
{
	int		*ptr;
	size_t	total_size;

	total_size = count * len;
	ptr = malloc(len * count);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return ((void *)ptr);
}
