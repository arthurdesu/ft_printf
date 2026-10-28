/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_np.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 14:58:01 by mamehri           #+#    #+#             */
/*   Updated: 2026/10/28 08:24:05 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_np(char c1, int *rtn, va_list *args)
{
	unsigned long	ar;

	if (c1 == 'p')
	{
		ar = va_arg(*args, unsigned long);
		if (ar == 0)
		{
			write(1, "(nil)", 5);
			*rtn += 5;
			return ;
		}
		*rtn += ft_putstr("0x");
		ft_put_pointer(ar, rtn);
	}
	else if ((c1 == 'd') || (c1 == 'i'))
		ft_putnbr_base((int)va_arg(*args, long), rtn, "0123456789");
}
