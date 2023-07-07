/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:34:25 by anmanuky          #+#    #+#             */
/*   Updated: 2023/03/02 11:40:12 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_fd(const char c, int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(const char *s, int fd);
int		convert_to_char(va_list ap);
int		convert_to_hex(va_list ap, char x);
int		convert_to_integer(va_list	ap);
int		convert_to_string(va_list ap);
void	ft_putnbr_fd(int n, int fd);
int		convert_to_unsigned_int(va_list ap);
char	help_hex_u(int rem);
char	help_hex(int rem);
char	*reverse_str(char *str);
int		convert_to_pointer(va_list ap);
int		convert_to_percent(int n);

#endif
