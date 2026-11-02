/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:33:35 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/02 07:02:19 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search(char c)
{
	char	*conv;
	int		i;

	i = 0;
	conv = "cspdiuxX%";
	while (conv[i])
	{
		if (conv[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, s + i++, 1);
	return (i);
}

void	ft_putnbr_base(long n, int *rtn, char *base)
{
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n < 0)
	{
		*rtn += 1;
		write(1, "-", 1);
		n *= -1;
	}
	if (n < base_len)
	{
		*rtn += 1;
		write(1, base + n, 1);
	}
	else
	{
		ft_putnbr_base(n / base_len, rtn, base);
		ft_putnbr_base(n % base_len, rtn, base);
	}
}

void	ft_put_pointer(uintptr_t n, int *rtn)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
	{
		*rtn += 1;
		write(1, base + n, 1);
	}
	else
	{
		ft_put_pointer(n / 16, rtn);
		ft_put_pointer(n % 16, rtn);
	}
}
