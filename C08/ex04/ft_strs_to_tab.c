/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:37:42 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/02 13:37:42 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*str_dup(char *str)
{
	char	*res;
	int		i;

	if (!str)
		return (NULL);
	res = malloc(sizeof(char) * (str_len(str) + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (str[++i] != 0)
		res[i] = str[i];
	res[i] = 0;
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock;

	stock = malloc(sizeof(t_stock_str) * (ac + 1));
	if (stock == NULL)
		return (NULL);
	i = -1;
	while (++i < ac)
	{
		stock[i].str = str_dup(av[i]);
		stock[i].size = str_len(av[i]);
		stock[i].copy = str_dup(av[i]);
		if (stock[i].copy == NULL)
			return (NULL);
	}
	stock[i].str = NULL;
	stock[i].copy = NULL;
	stock[i].size = 0;
	return (stock);
}
