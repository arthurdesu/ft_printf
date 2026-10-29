/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 11:56:44 by mamehri           #+#    #+#             */
/*   Updated: 2026/10/29 08:07:34 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_pointer(uintptr_t n, int *rtn)
{
	uintptr_t	base_len;
	char		*base;

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
