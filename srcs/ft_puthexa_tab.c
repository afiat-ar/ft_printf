/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:23:51 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/07/22 11:37:18 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_tab(t_print *tab, int c)
{
	unsigned int	j;
	int				len;
	char			*num;

	j = va_arg(tab->args, unsigned int);
	if (!j)
	{
		tab->tl += write(1, "0", 1);
		return ;
	}
	len = ft_numlen_base(j, 16);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return ;
	num = ft_itoa_base(num, j, 16, c);
	while (num && len-- > 0)
		tab->tl += write(1, &num[len], 1);
	free(num);
}

void	ft_output_pointer(t_print *tab)
{
	unsigned long	j;
	int				l;

	l = 2;
	j = (unsigned long)va_arg(tab->args, void *);
	if (!j)
	{
		ft_write_null_p(tab);
		return ;
	}
	tab->tl += write(1, "0x", 2);
	if (j)
		tab->tl += ft_putnbr_base(j, "0123456789abcdef");
}

void	ft_write_null_p(t_print *tab)
{
	tab->tl += write(1, "0x0", 3);
}
