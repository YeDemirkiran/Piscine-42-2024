/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:19:11 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/05 16:00:20 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	init(int *operators, int (*func_arr[5])(int, int))
{
	operators['/'] = 0;
	operators['%'] = 1;
	operators['+'] = 2;
	operators['-'] = 3;
	operators['*'] = 4;
	func_arr[0] = div;
	func_arr[1] = mod;
	func_arr[2] = sum;
	func_arr[3] = sub;
	func_arr[4] = mul;
}

int	is_operator_valid(char op)
{
	return (op == '+' || op == '-' || op == '*' || op == '/' || op == '%');
}

void	put_zero_msg(char c)
{
	if (c == '/')
		ft_putstr(DIV_ZERO_MSG);
	if (c == '%')
		ft_putstr(MOD_ZERO_MSG);
}

int	main(int argc, char *argv[])
{
	int		val1;
	int		val2;
	char	op;
	int		operators[50];
	int		(*func_arr[5])(int, int);

	init(operators, func_arr);
	if (argc != 4)
		return (0);
	op = argv[2][0];
	if (argv[2][1] || !is_operator_valid(op))
	{
		ft_putstr("0\n");
		return (0);
	}
	val1 = ft_atoi(argv[1]);
	val2 = ft_atoi(argv[3]);
	if (val2 == 0 && (op == '/' || op == '%'))
		put_zero_msg(op);
	else
		ft_putnbr(func_arr[operators[(int)op]](val1, val2));
	ft_putstr("\n");
	return (0);
}
