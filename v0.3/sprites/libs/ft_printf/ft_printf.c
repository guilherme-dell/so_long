/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 06:50:03 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/29 19:02:05 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ft_call_types(char c, va_list param)
{
	int	characters_printed;

	characters_printed = 0;
	if (c == 'c')
		characters_printed += ft_putchar(va_arg(param, int));
	else if (c == 's')
		characters_printed += ft_putstr(va_arg(param, char *));
	else if (c == 'p')
		characters_printed += ft_put_pointer(va_arg(param, unsigned long int));
	else if (c == 'd' || c == 'i')
		characters_printed += ft_putdi(va_arg(param, int));
	else if (c == 'u' || c == 'x' || c == 'X')
		characters_printed += ft_put_ux(c, va_arg(param, unsigned int));
	else if (c == '%')
		characters_printed += ft_putchar('%');
	return (characters_printed);
}

int	ft_printf(const char *s, ...)
{
	int		characters_printed;
	va_list	param;

	va_start(param, s);
	characters_printed = 0;
	while (*s)
	{
		if (*s == '%' && ft_strchr_2("cspdiuxX%", s[1]) && s++)
			characters_printed += ft_call_types(*s, param);
		else
		{
			write(1, s, 1);
			characters_printed++;
		}
		s++;
	}
	va_end(param);
	return (characters_printed);
}
