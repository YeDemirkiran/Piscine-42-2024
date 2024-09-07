/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:34:20 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/02 16:34:20 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	ft_putchar('\n');
}

void	ft_putnbr(int nb)
{
	long	i;

	i = nb;
	if (i == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (i < 0)
	{
		ft_putchar('-');
		i = i * -1;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	a;

	a = -1;
	while (par[++a].str != NULL)
	{
		ft_putstr(par[a].str);
		ft_putnbr(par[a].size);
		ft_putchar('\n');
		ft_putstr(par[a].copy);
	}
}
