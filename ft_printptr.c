/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniof <antoniof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:18:30 by antoniof          #+#    #+#             */
/*   Updated: 2024/11/13 12:41:57 by antoniof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long long ptr)
{
	int		len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

static void	ft_putptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_printc(ptr + 48);
		else
			ft_printc(ptr - 10 + 'a');
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int		len;

	len = 0;
	if (ptr == 0)
	{
		len += ft_prints("(nil)");
		return (len);
	}
	else
	{
		len += ft_prints("0x");
		ft_putptr(ptr);
		len += ft_ptrlen(ptr);
	}
	return (len);
}
