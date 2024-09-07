/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:35:51 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/14 18:46:30 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;
	char	space;
	char	comma;
	char	first;

	first = '0';
	space = ' ';
	comma = ',';

	while (a <= '9')
	{
		if (first > 0) 
		{
			write(1, &space, 1);
			write(1, &comma, 1);
		}
		else
		{
			first++;
		}
		while (b <= '9')
		{
			while (c <= '9')
			{
				write(1, &a, 1);
				write(1, &b, 1);
				write(1, &c, 1);

				c++;
			}	

			b++;		
		}
		a;;
	}	
}
