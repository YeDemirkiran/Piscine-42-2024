/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:24:11 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/03 16:44:38 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	char_in_charset(char c, char *charset)
{
	int	i;

	i = -1;
	if (c == 0)
		return (1);
	while (charset[++i] != 0)
	{
		if (c == charset[i])
			return (1);
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	a;

	i = -1;
	a = 0;
	while (str[++i] != 0)
	{
		if ((char_in_charset(str[i + 1], charset) == 1)
			&& (char_in_charset(str[i], charset) == 0))
			a++;
	}
	return (a);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		a;
	int		b;
	char	**strs;

	a = count_words(str, charset);
	strs = malloc(sizeof(char *) * (a + 1));
	strs[a] = NULL;
	i = -1;
	str--;
	while (*(++str))
	{
		b = 0;
		while (str[b] != 0 && char_in_charset(str[b], charset) == 0)
			b++;
		if (b < 1)
			continue ;
		strs[++i] = malloc(sizeof(char) * (b + 1));
		a = -1;
		while (++a < b)
			strs[i][a] = *(str++);
		str--;
		strs[i][a] = 0;
	}
	return (strs);
}

"Test1, Test2, Test3"