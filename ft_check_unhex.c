/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_unhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:16:01 by mamehri           #+#    #+#             */
/*   Updated: 2026/10/28 08:26:51 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_unhex(char c1, int *rtn, va_list *args)
{
	if (c1 == 'u')
		ft_putnbr_base(va_arg(*args, unsigned int), rtn, "0123456789");
	else if (c1 == 'x')
		ft_putnbr_base(va_arg(*args, unsigned int), rtn, "0123456789abcdef");
	else if (c1 == 'X')
		ft_putnbr_base(va_arg(*args, unsigned int), rtn, "0123456789ABCDEF");
}
