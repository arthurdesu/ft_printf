/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 22:07:33 by mamehri           #+#    #+#             */
/*   Updated: 2026/11/02 06:47:00 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			rtn += 1;
			write(1, format + i, 1);
		}
		i++;
	}
	va_end(args);
	return (rtn);
}
