/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamehri <mamehri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 06:40:30 by mamehri           #+#    #+#             */
/*   Updated: 2026/10/29 06:40:32 by mamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_s(char c1, int *rtn, va_list *args)
{
	char	*s;

	s = va_arg(*args, char *);
	if (!s)
		*rtn += ft_putstr("(null)");
	else if (c1 == 's')
		*rtn += ft_putstr(s);
}
