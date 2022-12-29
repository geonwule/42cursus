/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:21:29 by geonwule          #+#    #+#             */
/*   Updated: 2022/12/28 21:38:48 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// ft_printf
void	out_cs(const char *format, int i, va_list ap);
void	out_x2xp(const char *format, int i, va_list ap);
void	printp(unsigned int j, char	*y);
void	out_diu(const char *format, int i, va_list ap);
int		ft_printf(const char *str, ...);
char	*low_hex(unsigned int i);
char	*upp_hex(unsigned int i);

// libft
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
