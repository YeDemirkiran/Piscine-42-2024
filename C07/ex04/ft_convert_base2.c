/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 02:12:14 by ybayart           #+#    #+#             */
/*   Updated: 2024/08/28 17:32:45 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
	}
	return (i);
}

int	int_power(int num, int pow)
{
	int	i;

	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	i = num;
	while (pow-- > 1)
		i *= num;
	return (i);
}

int	int_len(long int nbr, int size, int is_neg)
{
	int	i;

	i = 0;
	if (is_neg == -1)
		i++;
	while (nbr > 0)
	{
		nbr /= size;
		i++;
	}
	return (i);
}

char	*ft_print_rc(int nbr, char *base, char *res, int is_neg)
{
	int	i;
	int	size;

	i = 0;
	size = int_len(nbr, ft_strlen(base), is_neg);
	if (is_neg == -1)
		res[0] = '-';
	if (nbr == 0)
	{
		res[0] = base[0];
		res[1] = '\0';
	}
	while (nbr > 0)
	{
		res[(size - i - 1)] = base[nbr % ft_strlen(base)];
		i++;
		nbr /= ft_strlen(base);
	}
	return (res);
}

char	*ft_putnbr_base(int nbr, char *base, int is_neg)
{
	int		nb;
	char	*res;
	int		size;
	int		len;

	nb = nbr;
	size = ft_strlen(base);
	len = int_len(nb, size, is_neg);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if ((is_neg == -1 && len == 1) || (len == 0 && is_neg == 0))
	{
		res[0] = base[0];
		return (res);
	}
	return (ft_print_rc(nb, base, res, is_neg));
}
