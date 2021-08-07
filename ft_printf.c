/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:54:34 by dpadovan          #+#    #+#             */
/*   Updated: 2021/08/07 00:50:13 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char str, va_list name)
{
	int	ret;

	if (str == 'c')
		ret = ft_print_char(name);
	if (str == 's')
		ret = ft_print_string(name);
	if (str == 'd' || str == 'i')
		ret = ft_print_integer(name);
	if (str == 'u')
		ret = ft_print_unsigned_int(name);
	if (str == 'x')
		ret = ft_print_hex(name, 87);
	if (str == 'X')
		ret = ft_print_hex(name, 55);
	if (str == 'p')
		ret = ft_print_pointer(name);
	if (str == '%')
	{
		write (1, "%", 1);
		return (1);
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	size_t	len;
	size_t	i;
	va_list	args;

	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len = len + ft_check_format(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
