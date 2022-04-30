/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:05:22 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/29 19:01:45 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	characters_printed;

	characters_printed = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		write(1, str++, 1);
		characters_printed++;
	}
	return (characters_printed);
}

char	*ft_strchr_2(const char *str, int c)
{
	char		caracter;

	caracter = (char)c;
	while (*str)
	{
		if (*str == caracter)
			return ((char *)str);
		else
			str++;
	}
	if (caracter == '\0')
		return ((char *) str);
	return (NULL);
}

char	*ft_itoa(int num)
{
	long long int	new_number;
	int				counter;
	int				sign;
	char			*str_number;

	new_number = num;
	counter = 1;
	sign = num < 0;
	if (sign)
		new_number *= -1;
	while (num / 10 != 0 && ++counter)
		num /= 10;
	str_number = malloc(sizeof(char) * (sign + counter + 1));
	if (!str_number)
		return (0);
	if (sign)
		str_number[0] = '-';
	str_number[sign + counter] = '\0';
	while (counter--)
	{
		str_number[sign + counter] = (new_number % 10) + '0';
		new_number /= 10;
	}
	return (str_number);
}

char	*ft_itoa_base(unsigned long int num, char *base)
{
	unsigned long int		new_number;
	char					*str_number;
	int						count;
	int						i;
	int						base_size;

	new_number = num;
	count = 1;
	i = 0;
	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	while (num / base_size != 0 && ++count)
		num /= base_size;
	str_number = malloc(sizeof(char) * (count + 1));
	if (!str_number)
		return (0);
	i = count;
	while (i--)
	{
		str_number[i] = base[new_number % base_size];
		new_number /= base_size;
	}
	str_number[count] = '\0';
	return (str_number);
}
