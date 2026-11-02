/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 22:26:10 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/02 12:11:55 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *s, ...);

void	ft_print(char c, int *rtn, va_list *args);

void	ft_putnbr_base(long n, int *rtn, char *base);
void	ft_put_pointer(uintptr_t n, int *rtn);

int		ft_putstr(const char *s);
int		ft_search(char c);

#endif
