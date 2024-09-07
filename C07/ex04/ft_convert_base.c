/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 02:12:04 by ybayart           #+#    #+#             */
/*   Updated: 2024/08/28 17:34:12 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		int_power(int num, int pow);
char	*ft_putnbr_base(int nbr, char *base, int is_neg);

int	check_valid(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[++i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] == ' '
				|| (base[i] >= 9 && base[i] <= 13)))
			return (0);
		j = i;
		while (base[++j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

char	*check_sign(char *str, int *is_neg)
{
	*is_neg = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			*is_neg *= -1;
	}
	return (str);
}

char	*ft_atoi(char *str, char *base, int *is_neg, int *size)
{
	int	i;
	int	j;
	int	valid;

	while ((*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	str = check_sign(str, is_neg);
	i = 0;
	while (*str != '\0')
	{
		j = -1;
		valid = 0;
		while (base[++j] != '\0')
			if (*str == base[j])
				valid = 1;
		if (valid == 0)
			break ;
		str++;
		i++;
	}
	*size = i;
	return (str - i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	nb;
	int			is_neg;
	int			size;
	int			ps;
	int			n;

	nb = 0;
	ps = 0;
	nbr = ft_atoi(nbr, base_from, &is_neg, &size);
	if (check_valid(base_from) == 0 || check_valid(base_to) == 0)
		return (NULL);
	while (ps < size)
	{
		n = 0;
		while (base_from[n] != nbr[ps])
			n++;
		nb += n * int_power(ft_strlen(base_from), (size - ps - 1));
		ps++;
	}
	return (ft_putnbr_base(nb, base_to, is_neg));
}
