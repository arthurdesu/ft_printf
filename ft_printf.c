/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 22:07:33 by mamehri           #+#    #+#             */
/*   Updated: 2026/10/29 08:17:23 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_search(char c)
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

static	void	ft_print(char c, int *rtn, va_list *args)
{
	if (c == '%' || c == 'c')
		ft_check_pc(c, rtn, args);
	else if (c == 's')
		ft_check_s(c, rtn, args);
	else if (c == 'p' || c == 'd' || c == 'i')
		ft_check_np(c, rtn, args);
	else if (c == 'u' || c == 'x' || c == 'X')
		ft_check_unhex(c, rtn, args);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		rtn;

	if (!format || write(1, 0, 0) == -1)
		return (-1);
	i = 0;
	rtn = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && !format[i + 1])
			return (-1);
		if (format[i] == '%' && ft_search(format[i + 1]))
			ft_print(format[++i], &rtn, &args);
		else if (format[i])
		{
			write(1, format + i, 1);
			rtn += 1;
		}
		i++;
	}
	va_end(args);
	return (rtn);
}
