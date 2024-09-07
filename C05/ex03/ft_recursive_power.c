/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:09:15 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/26 12:24:44 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	pow;

	pow = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		pow = 1;
	else if (power > 1)
		pow *= ft_recursive_power(nb, power - 1);
	else
		pow = nb;
	return (pow);
}
