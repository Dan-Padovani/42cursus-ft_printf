/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:21:20 by dpadovan          #+#    #+#             */
/*   Updated: 2021/07/31 23:31:22 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa(int n)
{
	int			i;
	int			j;
	long int	ln;
	char		*str;

	ln = n;
	j = n < 0;
	if (j > 0)
		ln = ln * -1;
	i = ft_intlen(n) + 1;
	str = (char *)malloc(i + j + 1);
	if (!str)
		return (NULL);
	str [i + j] = '\0';
	while (i != 0)
	{
		i--;
		str [i + j] = ln % 10 + '0';
		ln = ln / 10;
	}
	if (j > 0)
		str [0] = '-';
	return (str);
}

int	ft_print_integer(va_list name)
{
	int		number;
	int		len;
	char	*ptr_ft;

	number = va_arg(name, int);
	ptr_ft = ft_itoa(number);
	len = ft_putstr(ptr_ft);
	free(ptr_ft);
	return (len);
}
