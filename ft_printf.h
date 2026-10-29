/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 22:26:10 by mamehri           #+#    #+#             */
/*   Updated: 2026/10/29 08:08:02 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *s, ...);

int		ft_putstr(const char *s);

void	ft_putnbr_base(long n, int *rtn, char *base);
void	ft_put_pointer(uintptr_t n, int *rtn);
void	ft_check_pc(char c1, int *rtn, va_list *args);
void	ft_check_s(char c1, int *rtn, va_list *args);
void	ft_check_np(char c1, int *rtn, va_list *args);
void	ft_check_unhex(char c1, int *rtn, va_list *args);

size_t	ft_strlen(const char *str);

#endif
