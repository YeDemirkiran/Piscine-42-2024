/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:46:53 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/29 11:51:39 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	pow;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	pow = nb;
	while (power-- > 1)
		pow *= nb;
	return (pow);
}
