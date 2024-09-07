/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:16:07 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/01 20:08:27 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_pow(long num, long pow)
{
	long	res;

	if (pow == 0)
		return (1);
	res = num;
	while (pow-- > 1)
		res *= num;
	return (res);
}

long	int_len(long nbr)
{
	long	digits;

	if (nbr == 0)
		return (1);
	digits = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		digits++;
	}
	return (digits);
}

long	get_int_face_value(long nbr, long index)
{
	long	i;
	long	digits;
	long	digit;

	digits = int_len(nbr);
	i = -1;
	while (++i <= index)
	{
		if (digits < 2)
			digit = 1;
		else
			digit = ft_pow(10, --digits);
		if (i == index)
			return (nbr / digit);
		nbr %= digit;
	}
	return (-1);
}

long	get_int_place_value(long nbr, long index)
{
	long	i;
	long	digits;
	long	digit;

	digits = int_len(nbr);
	i = -1;
	while (++i <= index)
	{
		if (digits < 2)
			digit = 1;
		else
			digit = ft_pow(10, --digits);
		if (i == index)
			return ((nbr / digit) * ft_pow(10, digits));
		nbr %= digit;
	}
	return (-1);
}

long	trim_int(long nbr, long times, int fix_zeros)
{
	if (nbr < 10)
		return (0);
	if (times > 0)
	{
		if (nbr > get_int_place_value(nbr, 0) || !fix_zeros)
		{
			if (times == 1)
				return (nbr - get_int_place_value(nbr, 0));
			else if (int_len(nbr) - 1
				== int_len(nbr - get_int_place_value(nbr, 0)))
				return (trim_int(nbr - get_int_place_value(nbr, 0),
						times - 1, fix_zeros));
			else
				return (nbr - get_int_place_value(nbr, 0));
		}
		else
		{
			if (times == 1)
				return (nbr / ft_pow(10, times));
			else
				return (trim_int(nbr / ft_pow(10, times), 1, fix_zeros));
		}
	}
	return (nbr);
}
