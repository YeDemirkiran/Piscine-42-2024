/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:10:45 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/01 14:47:47 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_newline(void)
{
	write(1, "\n", 1);
}

void	ft_putstr(char *str)
{
	long	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

long	is_space(char c)
{
	if (c == ' ' || (c >= 7 && c <= 13))
		return (1);
	return (0);
}

long	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	str_cmp(char *str1, char *str2)
{
	long	i;

	i = -1;
	while (str1[++i] && str2[i] && str1[i] == str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
	}
	if (str1[i] != str2[i])
		return (0);
	return (1);
}
