/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:31:50 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/26 12:12:30 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	factorial;

	nb = (long) nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	factorial = nb;
	while (nb > 1)
	{
		nb--;
		factorial *= nb;
	}
	return (factorial);
}
