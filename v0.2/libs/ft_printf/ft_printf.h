/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnuncio- <gnuncio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:25:29 by gnuncio-          #+#    #+#             */
/*   Updated: 2022/04/29 19:01:19 by gnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
char	*ft_strchr_2(const char *str, int c);
char	*ft_itoa(int num);
char	*ft_itoa_base(unsigned long int num, char *base);
int		ft_putdi(int c);
int		ft_put_pointer(unsigned long int c);
int		ft_put_ux(char type, unsigned int c);

#endif