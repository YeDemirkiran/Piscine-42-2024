/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:15:28 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/01 20:21:35 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

long	search_key_in_dict(char ***dict, char *key)
{
	long	i;

	i = -1;
	while (dict[++i])
	{
		if (str_cmp(dict[i][0], key))
			return (i);
	}
	return (-1);
}

char	*get_value_in_dict(char ***dict, char *key)
{
	long	i;

	i = search_key_in_dict(dict, key);
	if (i == -1)
		return (NULL);
	return (dict[i][1]);
}

char	*fill_string(char buffer[256], long len)
{
	char	*str;
	int		i;

	buffer[len] = 0;
	i = -1;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (buffer[++i])
		str[i] = buffer[i];
	str[i] = 0;
	return (str);
}
