/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:57:17 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/22 16:33:31 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || c == '\t'
		|| c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nbr;
	int	start;

	i = 0;
	sign = 1;
	start = 1;
	nbr = 0;
	while (str[i] != 0)
	{
		if (start == 1 && str[i] == '-')
			sign *= -1;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			start = 0;
			nbr *= 10;
			nbr += str[i] - '0';
		}
		else if (start == 0
			|| (start == 1 && !is_space(str[i]) && str[i] != '+'))
			break ;
		i++;
	}
	return (nbr * sign);
}
