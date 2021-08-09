/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:23:40 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/07/21 11:23:40 by afiat-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_number_len(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count += 1;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*ft_uitoa(unsigned int nb)
{
	char	*a;
	int		l;

	l = ft_number_len(nb);
	a = (char *)malloc(sizeof(char) * (l + 1));
	if (!a)
		return (NULL);
	a[l--] = '\0';
	if (nb == 0)
		a[l] = 0 + '0';
	while (nb > 0)
	{
		a[l--] = nb % 10 + '0';
		nb /= 10;
	}
	return (a);
}

void	ft_putnbr_tab(t_print *tab)
{
	int		i;
	int		j;
	char	*num;
	int		len;

	i = 0;
	j = va_arg(tab->args, int);
	if (!j)
	{
		tab->tl += write(1, "0", 1);
		return ;
	}
	num = ft_itoa(j);
	if (!num)
		return ;
	while (j && num[i])
		tab->tl += write(1, &num[i++], 1);
	free(num);
}

void	ft_putunsignednbr_tab(t_print *tab)
{
	int				i;
	unsigned int	j;
	char			*num;
	int				len;

	i = 0;
	j = va_arg(tab->args, int);
	if (!j)
	{
		tab->tl += write(1, "0", 1);
		return ;
	}
	num = ft_uitoa(j);
	if (!num)
		return ;
	while (num[i])
		tab->tl += write(1, &num[i++], 1);
	free(num);
}
