/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:44 by mamehri           #+#    #+#             */
/*   Updated: 2026/10/28 10:52:22 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_pointer(unsigned long n, int *rtn)
{
	unsigned long	base_len;
	char			*base;

	base = "0123456789abcdef";
	base_len = ft_strlen(base);
	if (n < base_len)
	{
		write(1, base + n, 1);
		*rtn += 1;
	}
	else
	{
		ft_put_pointer(n / base_len, rtn);
		ft_put_pointer(n % base_len, rtn);
	}
}
