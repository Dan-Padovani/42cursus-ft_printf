/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 23:57:19 by dpadovan          #+#    #+#             */
/*   Updated: 2021/07/31 21:44:15 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(va_list name)
{
	char	*string;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	string = va_arg(name, char *);
	if (!string)
	{
		len = write(1, "(null)", 6);
		return (len);
	}
	while (string[i])
	{
		write(1, &string[i], 1);
		i++;
		len++;
	}
	return (len);
}
