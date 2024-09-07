/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:19:01 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/05 15:43:16 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

int		sum(int val1, int val2);
int		sub(int val1, int val2);
int		mul(int val1, int val2);
int		div(int val1, int val2);
int		mod(int val1, int val2);
void	ft_putstr(char *str);
void	rec(int nb);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);

# define DIV_ZERO_MSG "Stop : division by zero"
# define MOD_ZERO_MSG "Stop : modulo by zero"

#endif
