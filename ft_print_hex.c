/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:17:13 by dpadovan          #+#    #+#             */
/*   Updated: 2021/07/31 23:42:45 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_print_rev(char *n_str)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(n_str);
	str = (char *)malloc(i + 1);
	while (i > 0)
	{
		i--;
		str[j] = n_str[i];
		j++;
	}
	str[j] = '\0';
	free(n_str);
	return (str);
}

static char	*ft_convert_hex(unsigned int num, int type)
{
	int		i;
	int		res;
	char	*n_str;

	i = 0;
	res = 0;
	n_str = (char *)malloc(9);
	if (num == 0)
	{
		n_str[0] = 48;
		n_str[1] = '\0';
		return (n_str);
	}
	while (num != 0)
	{
		res = num % 16;
		num = num / 16;
		if (res < 10)
			n_str[i] = res + 48;
		else
			n_str[i] = res + type;
		i++;
	}
	n_str[i] = '\0';
	return (ft_print_rev(n_str));
}

int	ft_print_hex(va_list name, int type)
{
	unsigned int	number;
	int				len;
	char			*ptr_ft;

	number = va_arg(name, int);
	ptr_ft = ft_convert_hex(number, type);
	len = ft_putstr(ptr_ft);
	free(ptr_ft);
	return (len);
}
