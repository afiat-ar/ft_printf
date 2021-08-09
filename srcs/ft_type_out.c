/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:23:31 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/07/21 11:23:31 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_print_type(t_print *tab, int i, const char *format)
{
	if (format[i] == 's')
		ft_putstr_tab(tab);
	if (format[i] == 'c')
		ft_putchar_tab(tab);
	if (format[i] == 'p')
		ft_output_pointer(tab);
	if (format[i] == 'd')
		ft_putnbr_tab(tab);
	if (format[i] == 'i')
		ft_putnbr_tab(tab);
	if (format[i] == 'u')
		ft_putunsignednbr_tab(tab);
	if (format[i] == 'x')
		ft_puthexa_tab(tab, format[i] - 23);
	if (format[i] == 'X')
		ft_puthexa_tab(tab, format[i] - 23);
	if (format[i] == '%')
		tab->tl += write(1, "%%", 1);
	return (i);
}
