/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:39:58 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/01 20:23:43 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	print_nbr(char ***dict, long nbr, int digit)
{
	int	trim;

	print_nbr_dict(dict, nbr / ft_pow(10, ((digit - 1) / 3) * 3));
	ft_putstr(" ");
	print_nbr_dict(dict, ft_pow(10, ((digit - 1) / 3) * 3));
	trim = digit % 3;
	trim = (trim == 0) * 3 + (trim != 0) * trim;
	if (trim_int(nbr, trim, 0) == 0)
		return ;
	if (int_len(trim_int(nbr, trim, 1)) <= 3)
		ft_putstr(" and ");
	else
		ft_putstr(", ");
	print_nbr_dict(dict, trim_int(nbr, trim, 0));
}

void	print_nbr_ones(char ***dict, long nbr, int digit)
{
	if (digit % 3 == 0)
	{
		if (get_int_face_value(nbr, 0) != 1)
		{
			print_nbr_dict(dict, get_int_face_value(nbr, 0));
			ft_putstr(" ");
		}
		print_nbr_dict(dict, get_int_place_value(nbr, 0)
			/ get_int_face_value(nbr, 0));
		ft_putstr(" ");
		if (trim_int(nbr, 1, 0) != 0)
			print_nbr_dict(dict, trim_int(nbr, 1, 1));
	}
	if (digit % 3 == 2)
	{
		print_nbr_dict(dict, get_int_place_value(nbr, 0));
		ft_putstr("-");
		print_nbr_dict(dict, trim_int(nbr, 1, 1));
	}
}

void	print_nbr_dict(char ***dict, long nbr)
{
	char	*buff;
	long	digit;

	buff = get_value_in_dict(dict, ft_itoa(nbr));
	if (buff != NULL)
	{
		ft_putstr(buff);
		return ;
	}
	digit = int_len(nbr);
	if (digit > 3)
	{
		print_nbr(dict, nbr, digit);
	}
	else
		print_nbr_ones(dict, nbr, digit);
}

void	free_dict(char ***dict)
{
	long	i;

	if (dict == NULL)
		return ;
	i = -1;
	while (dict[++i])
	{
		if (dict[i] == NULL)
			continue ;
		if (dict[i][0])
			free(dict[i][0]);
		if (dict[i][1])
			free(dict[i][1]);
		free(dict[i]);
	}
	free(dict);
}

int	main(int ac, char *argv[])
{
	char	***dict;

	if ((ac < 2 || ac > 3)
		|| (ac == 2 && check_input(argv[ac - 1]) == 0))
	{
		ft_putstr("Error\n");
		return (-1);
	}
	if (ac == 3)
		dict = fetch_dict(argv[ac - 2]);
	else
		dict = fetch_dict(DICT_PATH);
	if (dict == NULL)
	{
		ft_putstr("Dict Error\n");
		return (-1);
	}
	print_nbr_dict(dict, ft_atoi(argv[ac - 1]));
	ft_newline();
	free_dict(dict);
	return (0);
}
