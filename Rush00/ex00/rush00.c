/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:44:24 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/20 14:23:44 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	write_x(int x, int y, int y_counter)
{
	int	x_counter;

	x_counter = 1;
	while (x_counter <= x)
	{
		if (y_counter == 1 || y_counter == y)
		{
			if (x_counter == 1 || x_counter == x)
				ft_putchar('o');
			else
				ft_putchar('-');
		}
		else
		{
			if (x_counter == 1 || x_counter == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
		}
		x_counter++;
	}
}

void	rush(int x, int y)
{
	int			y_counter;

	y_counter = 1;
	while (y_counter <= y)
	{
		write_x(x, y, y_counter);
		ft_putchar('\n');
		y_counter++;
	}
}
