/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printeasy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniof <antoniof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:18:45 by antoniof          #+#    #+#             */
/*   Updated: 2024/10/18 13:13:20 by antoniof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prints(char *s)
{
	int	len;

	len = 0;
	if (s == 0)
	{
		return (ft_prints("(null)"));
	}
	while (s[len])
	{
		len += ft_printc(s[len]);
	}
	return (len);
}

int	ft_printu(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len += ft_printc('0');
	else
	{
		if (n / 10 != 0)
			ft_printu(n / 10);
		ft_printc((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}

int	ft_printi(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len += ft_printc('0');
	if (n == -2147483648)
	{
		len += ft_prints("-2147483648");
		return (len);
	}
	if (n < 0)
	{
		len += ft_printc('-');
		n = -n;
	}
	if (n > 0)
		len += ft_printu((unsigned int)n);
	return (len);
}
