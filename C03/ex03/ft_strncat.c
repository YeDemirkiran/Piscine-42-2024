/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:38:14 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/19 18:55:38 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	dst_len;

	i = 0;
	dst_len = 0;
	while (dest[dst_len] != 0)
		dst_len++;
	while (i < nb && src[i] != 0)
	{
		dest[i + dst_len] = src[i];
		i++;
	}
	dest[dst_len + i] = 0;
	return (dest);
}
