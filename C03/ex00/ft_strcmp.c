/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:00:25 by yademirk          #+#    #+#             */
/*   Updated: 2024/08/19 15:20:13 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	s1i;
	int	s2i;

	i = 0;
	s1i = 0;
	s2i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] == s2[i])
		{
			s1i++;
			s2i++;
		}
		else
			break ;
		i++;
	}
	return (s1[s1i] - s2[s2i]);
}
