/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:57:26 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/22 16:03:06 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_str(char *str, char *base)
{
	int	i;

	i = 0;
	while (str[i] != 0 && base[i] != 0)
		i++;
	if (str[i] != base[i])
		return (0);
	else
		return (1);
}

int	get_base(char *str, char *arr)
{
	int		base;
	char	*buff;

	base = 0;
	while (*str != 0)
	{
		if (*str == '+' || *str == '-')
			return (0);
		buff = str;
		while (*buff++)
		{
			if (*str == *buff)
				return (0);
		}
		arr[base] = *str;
		base++;
		str++;
	}
	return (base);
}

int	abs(int integer)
{
	if (integer == -2147483648)
		return (2147483647);
	else if (integer < 0)
		return (-integer);
	else
		return (integer);
}

void	write_base(int nbr, int base, char *arr)
{
	char	bin[32];
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (nbr != 0 || start < 1)
	{
		bin[i] = arr[abs(nbr % base)];
		nbr /= base;
		i++;
		start++;
	}
	i--;
	while (i > -1)
	{
		write(1, &bin[i], 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		_base;
	char	arr[100];

	_base = get_base(base, arr);
	if (_base <= 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
	}
	write_base(nbr, _base, arr);
}
