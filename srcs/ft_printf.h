/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:24:01 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/07/21 11:24:01 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>
# include <limits.h>

/*
	1- arg to print
	2- width
	3- precission
	4- zero padding
	5- .
	6- -
	7- total length
	8- pos or neg number
	9- is number zero
	10- space flag */
typedef struct s_print
{
	va_list	args;
	int		zero;
	int		minus;
	int		pnt;
	int		tl;
	int		sign;
	int		pad;
	int		sp;
	int		wdt;
	int		prc;
}	t_print;

int		ft_printf(const char *format, ...);
t_print	*ft_reset_struct(t_print *tab);

int		ft_check_flags(t_print *tab, int i, const char *format);
int		ft_check_print_type(t_print *tab, int i, const char *format);

void	ft_putunsignednbr_tab(t_print *tab);
void	ft_putnbr_tab(t_print *tab);
void	ft_putstr_tab(t_print *tab);
void	ft_putchar_tab(t_print *tab);

void	ft_output_pointer(t_print *tab);
void	ft_write_null_p(t_print *tab);
int		ft_numlen_base(unsigned long n, int base);
char	*ft_itoa_base(char *str, unsigned long n, int base, int c);
int		ft_putnbr_base(unsigned long n, char *base);
void	ft_puthexa_tab(t_print *tab, int c);

#endif