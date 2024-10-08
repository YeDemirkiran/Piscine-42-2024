/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:33:08 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/29 11:56:46 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;
	long	nbr;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 1;
	nbr = (long)nb;
	while (i <= nbr / 2 && i <= 46341)
	{
		if (i * i == nbr)
			return (i);
		i++;
	}
	return (0);
}
