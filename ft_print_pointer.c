/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:09:13 by dpadovan          #+#    #+#             */
/*   Updated: 2021/07/31 23:38:25 by dpadovan         ###   ########.fr       */
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

static int	ft_intlen(uintptr_t n)
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

static char	*ft_convert_hex(uintptr_t num)
{
	int		i;
	int		j;
	int		res;
	char	*n_str;

	i = 0;
	j = ft_intlen(num);
	res = 0;
	n_str = (char *)malloc(j + 1);
	while (num != 0)
	{
		res = num % 16;
		num = num / 16;
		if (res < 10)
			n_str[i] = res + 48;
		else
			n_str[i] = res + 87;
		i++;
	}
	n_str[i] = '\0';
	return (ft_print_rev(n_str));
}

static char	*ft_ptr_conv(uintptr_t ptr_number)
{
	char	*ptr_aux;
	char	*ptr_str;

	if (!ptr_number)
	{
		ptr_str = (char *)malloc(4);
		ptr_str [0] = '0';
		ptr_str [1] = 'x';
		ptr_str [2] = '0';
		ptr_str [3] = '\0';
		return (ptr_str);
	}
	else
	{
		ptr_aux = ft_convert_hex(ptr_number);
		ptr_str = ft_strjoin("0x", ptr_aux);
	}
	free(ptr_aux);
	return (ptr_str);
}

int	ft_print_pointer(va_list name)
{
	int			len;
	char		*ptr_ft;
	uintptr_t	ptr_number;

	ptr_number = (uintptr_t)va_arg(name, void *);
	ptr_ft = ft_ptr_conv(ptr_number);
	len = ft_putstr(ptr_ft);
	free(ptr_ft);
	return (len);
}
