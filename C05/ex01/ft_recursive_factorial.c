/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:31:50 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/26 12:16:32 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	factorial;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	factorial = nb * ft_recursive_factorial(nb - 1);
	return (factorial);
}
