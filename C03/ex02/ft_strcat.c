/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:38:14 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/19 13:44:32 by yademirk         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dst_len;

	i = 0;
	dst_len = str_len(dest);
	while (src[i] != 0)
	{
		dest[i + dst_len] = src[i];
		i++;
	}
	dest[i + dst_len] = 0;
	return (dest);
}
