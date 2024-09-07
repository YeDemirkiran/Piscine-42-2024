/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:22:21 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/29 11:42:04 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	str_arr_len(char **strs, int size)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (++i < size)
		len += str_len(strs[i]);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		a;
	int		b;

	if (size < 1)
		return (malloc(1));
	a = sizeof(char) * str_arr_len(strs, size);
	i = sizeof(char) * str_len(sep) * (size - 1);
	str = malloc(a + i + sizeof(char));
	if (str == NULL || size < 1)
		return (NULL);
	i = -1;
	a = 0;
	while (++i < size)
	{
		b = 0;
		while (strs[i][b] != 0)
			str[a++] = strs[i][b++];
		b = 0;
		while (sep[b] != 0 && i < size - 1)
			str[a++] = sep[b++];
	}
	str[a] = 0;
	return (str);
}
