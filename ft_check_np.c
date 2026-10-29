/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_np.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 06:39:26 by mamehri           #+#    #+#             */
/*   Updated: 2026/10/29 08:07:23 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_np(char c1, int *rtn, va_list *args)
{
	uintptr_t	ar;

	if (c1 == 'p')
	{
		ar = va_arg(*args, uintptr_t);
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
		ft_putnbr_base(va_arg(*args, int), rtn, "0123456789");
}
