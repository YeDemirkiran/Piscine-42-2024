/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:38:14 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/19 19:12:51 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dst_len;
	unsigned int	src_len;

	dst_len = str_len(dest);
	src_len = str_len(src);
	if (dst_len >= size)
		return (dst_len + src_len);
	i = 0;
	while (i < (size - dst_len) - 1 && src[i] != 0)
	{
		dest[i + dst_len] = src[i];
		i++;
	}
	dest[i + dst_len] = 0;
	return (dst_len + src_len);
}
