/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniof <antoniof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:18:16 by antoniof          #+#    #+#             */
/*   Updated: 2024/10/18 12:48:20 by antoniof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int hex)
{
	int		len;

	len = 0;
	if (hex == 0)
		return (1);
	while (hex > 0)
	{
		len++;
		hex = hex / 16;
	}
	return (len);
}

int	ft_printhexlow(unsigned int hex)
{
	int		len;

	len = ft_hex_len(hex);
	if (hex >= 16)
	{
		ft_printhexlow(hex / 16);
		ft_printhexlow(hex % 16);
	}
	else
	{
		if (hex <= 9)
			ft_printc(hex + 48);
		else
			ft_printc(hex - 10 + 'a');
	}
	return (len);
}

int	ft_printhexup(unsigned int hex)
{
	int		len;

	len = ft_hex_len(hex);
	if (hex >= 16)
	{
		ft_printhexup(hex / 16);
		ft_printhexup(hex % 16);
	}
	else
	{
		if (hex <= 9)
			ft_printc(hex + 48);
		else
			ft_printc(hex - 10 + 'A');
	}
	return (len);
}
