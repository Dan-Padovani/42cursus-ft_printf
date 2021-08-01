/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:21:20 by dpadovan          #+#    #+#             */
/*   Updated: 2021/07/31 21:29:47 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_unsigned_itoa(unsigned int n)
{
	int				i;
	char			*str;

	if (n == 0)
	{
		str = (char *)malloc(2);
		str[0] = 48;
		str[1] = '\0';
		return (str);
	}
	i = ft_intlen(n);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i != 0)
	{
		i--;
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

int	ft_print_unsigned_int(va_list name)
{
	unsigned int		number;
	int					len;
	char				*ptr_ft;

	number = va_arg(name, int);
	ptr_ft = ft_unsigned_itoa(number);
	len = ft_putstr(ptr_ft);
	free(ptr_ft);
	return (len);
}
