/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:58:09 by dpadovan          #+#    #+#             */
/*   Updated: 2021/07/31 21:43:22 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_print_integer(va_list name);
int		ft_print_unsigned_int(va_list name);
int		ft_print_hex(va_list name, int type);
int		ft_print_pointer(va_list name);
int		ft_print_string(va_list name);
int		ft_print_char(va_list name);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif