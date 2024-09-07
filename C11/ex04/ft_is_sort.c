/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 22:26:52 by gicho             #+#    #+#             */
/*   Updated: 2024/09/05 15:18:13 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	first_cmp;
	int	comparison;

	first_cmp = 0;
	while (length-- > 1)
	{
		comparison = f(tab[length], tab[length - 1]);
		if (comparison == 0)
			continue ;
		if (first_cmp == 0)
			first_cmp = comparison;
		else if ((first_cmp < 0 && comparison > 0)
			|| (first_cmp > 0 && comparison < 0))
			return (0);
	}
	return (1);
}
