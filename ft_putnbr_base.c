/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 02:00:24 by mamehri           #+#    #+#             */
/*   Updated: 2026/10/28 08:23:13 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long n, int *rtn, char *base)
{
	long	base_len;

	base_len = ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		*rtn += 1;
	}
	if (n < base_len)
	{
		write(1, base + n, 1);
		*rtn += 1;
	}
	else
	{
		ft_putnbr_base(n / base_len, rtn, base);
		ft_putnbr_base(n % base_len, rtn, base);
	}
}
