/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_unhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 06:40:40 by mamehri           #+#    #+#             */
/*   Updated: 2026/10/29 06:40:43 by mamehri          ###   ########.fr       */
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
