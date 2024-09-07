/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:06:24 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/21 18:38:08 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	while (str[i] != 0 && to_find[i2] != 0)
	{
		if (str[i] == to_find[i2])
		{
			i2++;
		}
		else
		{
			i2 = 0;
		}
		i++;
	}
	if (to_find[i2] == 0)
		return (&str[i - str_len(to_find)]);
	else
		return (0);
}
