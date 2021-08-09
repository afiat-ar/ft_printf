/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:24:05 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/07/21 11:24:05 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_tl(int i, char const *format)
{
	int		num;

	num = 0;
	while (ft_isdigit(format[i]))
	{
		num = (num * 10) + (format[i] - '0');
		i++;
	}
	return (num);
}

/**
**	This method call function ft_is_flag, if this
**	condition is true we call ft_print_with_format
**	and if it is false, we call ft_check_print_type
**	to print simple type
**/
int	ft_check_flags(t_print *tab, int i, const char *format)
{
	while (!(ft_isalpha(format[i]) || format[i] == '%'))
		i++;
	i = ft_check_print_type(tab, i, format);
	ft_reset_struct(tab);
	return (i);
}
