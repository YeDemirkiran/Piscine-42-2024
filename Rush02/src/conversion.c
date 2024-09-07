/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:19:08 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/01 20:15:57 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

long	ft_atoi(char *str)
{
	long	i;
	long	num;
	long	sign;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sign);
}

char	*ft_itoa(long nbr)
{
	char	*str;
	long	digits;
	long	i;

	digits = int_len(nbr);
	str = malloc(sizeof(char) * (digits + (nbr < 0) + 1));
	if (str == NULL)
		return (NULL);
	str[digits] = 0;
	i = -1;
	if (nbr < 0)
		str[++i] = '-';
	while (++i < digits)
		str[i] = get_int_face_value(nbr, i) + '0';
	return (str);
}
