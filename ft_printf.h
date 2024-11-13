/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniof <antoniof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:21:59 by antoniof          #+#    #+#             */
/*   Updated: 2024/10/18 12:37:45 by antoniof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_print_type(va_list args, const char type);
int	ft_printc(int c);
int	ft_printpercent(void);
int	ft_printu(unsigned int u);
int	ft_printptr(unsigned long long ptr);
int	ft_printhexup(unsigned int hex);
int	ft_printhexlow(unsigned int hex);
int	ft_printi(int i);
int	ft_prints(char *s);

#endif
