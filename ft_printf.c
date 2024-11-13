/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniof <antoniof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:05:19 by antoniof          #+#    #+#             */
/*   Updated: 2024/11/13 12:42:26 by antoniof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_printc(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_type(va_list args, const char type)
{
	int		len;

	len = 0;
	if (type == 'c')
		len += ft_printc(va_arg(args, int));
	else if (type == 's')
		len += ft_prints(va_arg(args, char *));
	else if (type == 'p')
		len += ft_printptr(va_arg(args, unsigned long long));
	else if (type == 'd')
		len += ft_printi(va_arg(args, int));
	else if (type == 'i')
		len += ft_printi(va_arg(args, int));
	else if (type == 'u')
		len += ft_printu(va_arg(args, unsigned int));
	else if (type == 'x')
		len += ft_printhexlow(va_arg(args, unsigned int));
	else if (type == 'X')
		len += ft_printhexup(va_arg(args, unsigned int));
	else if (type == '%')
		len += ft_printpercent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	va_list		args;
	int			len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_print_type(args, str[i + 1]);
			i++;
		}
		else
			len += ft_printc(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
