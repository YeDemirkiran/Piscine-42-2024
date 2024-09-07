/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:40:53 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/02 13:13:29 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_place_valid(int table[10], int x, int y)
{
	int	i;

	i = -1;
	while (++i < x)
		if (y == table[i]
			|| i + table[i] == x + y
			|| i - table[i] == x - y)
			return (0);
	return (1);
}

void	puzzle_recursive(int table[10], int *res, int pos)
{
	int	i;
	int	i2;

	if (pos == 10)
	{
		*res += 1;
		i2 = -1;
		while (++i2 < 10)
			ft_putchar(table[i2] + '0');
		ft_putchar('\n');
	}
	else
	{
		i = -1;
		while (++i < 10)
		{
			if (is_place_valid(table, pos, i))
			{
				table[pos] = i;
				puzzle_recursive(table, res, pos + 1);
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	table[10];
	int	i;
	int	res;

	i = -1;
	while (++i < 10)
		table[i] = -1;
	res = 0;
	puzzle_recursive(table, &res, 0);
	return (res);
}
