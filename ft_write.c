/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:30:01 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/02 07:09:34 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_pc(char c, int *rtn, va_list *args)
{
	char	c2;

	if (c == '%')
	{
		*rtn += 1;
		write(1, &c, 1);
	}
	else if (c == 'c')
	{
		*rtn += 1;
		c2 = va_arg(*args, int);
		write(1, &c2, 1);
	}
}

static void	ft_put_s(char c, int *rtn, va_list *args)
{
	char	*s;

	s = va_arg(*args, char *);
	if (!s)
		*rtn += ft_putstr("(null)");
	else if (c == 's')
		*rtn += ft_putstr(s);
}

static void	ft_put_pdi(char c1, int *rtn, va_list *args)
{
	uintptr_t	ar;

	if (c1 == 'p')
	{
		ar = va_arg(*args, uintptr_t);
		if (ar == 0)
		{
			*rtn += 5;
			write(1, "(nil)", 5);
			return ;
		}
		*rtn += ft_putstr("0x");
		ft_put_pointer(ar, rtn);
	}
	else if ((c1 == 'd') || (c1 == 'i'))
		ft_putnbr_base(va_arg(*args, int), rtn, "0123456789");
}

static void	ft_put_unhex(char c, int *rtn, va_list *args)
{
	if (c == 'u')
		ft_putnbr_base(va_arg(*args, unsigned int), rtn, "0123456789");
	else if (c == 'x')
		ft_putnbr_base(va_arg(*args, unsigned int), rtn, "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_base(va_arg(*args, unsigned int), rtn, "0123456789ABCDEF");
}

void	ft_print(char c, int *rtn, va_list *args)
{
	if (c == '%' || c == 'c')
		ft_put_pc(c, rtn, args);
	else if (c == 's')
		ft_put_s(c, rtn, args);
	else if (c == 'p' || c == 'd' || c == 'i')
		ft_put_pdi(c, rtn, args);
	else if (c == 'u' || c == 'x' || c == 'X')
		ft_put_unhex(c, rtn, args);
}
