/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwule <geonwule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:21:29 by geonwule          #+#    #+#             */
/*   Updated: 2023/01/16 17:26:27 by geonwule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

// ft_printf
int		ft_printf(const char *str, ...);
int		error_check(const char *format);
void	out_cs(const char *format, int i, va_list ap, int *ret);
void	out_x2xp(const char *format, int i, va_list ap, int *ret);
char	*point_hex(unsigned long i);
void	out_diu(const char *format, int i, va_list ap, int *ret);
char	*ft_utoa(unsigned int n);
char	*low_hex(unsigned int i);
char	*upp_hex(unsigned int i);

#endif
