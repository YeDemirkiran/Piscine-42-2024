/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:22:48 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/01 20:21:20 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

long	file_lines(char *path)
{
	long	fd;
	char	c;
	char	prev;
	long	lines;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	lines = 1;
	prev = '\n';
	while (read(fd, &c, 1))
	{
		if (c == '\n' && prev != '\n')
			lines++;
		prev = c;
	}
	if (prev == '\n')
		lines--;
	close(fd);
	return (lines);
}

long	check_input(char *str)
{
	long	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' || str[i] == '+' || is_space(str[i])
			|| !is_numeric(str[i]))
			return (0);
	}
	return (1);
}

char	*fetch_keys(long fd)
{
	char	*str;
	long	i;
	long	len;
	char	c;
	char	buffer[256];

	if (fd == -1)
		return (NULL);
	i = -1;
	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == ':')
			break ;
		if (!is_space(c) && is_numeric(c))
			buffer[len++] = c;
	}
	buffer[len] = 0;
	str = fill_string(buffer, len);
	return (str);
}

char	*fetch_values(long fd)
{
	char	*str;
	long	i;
	long	len;
	char	c;
	char	buffer[256];

	len = 0;
	i = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		if (i == 1 || !is_space(c))
		{
			if (is_space(c))
				i = 0;
			else
				i = 1;
			buffer[len++] = c;
		}
	}
	buffer[len] = 0;
	str = fill_string(buffer, len);
	return (str);
}

char	***fetch_dict(char *path)
{
	char	***dict;
	long	fd;
	long	i;
	long	lines;

	lines = file_lines(path);
	dict = malloc(sizeof(char **) * (lines + 1));
	if (dict == NULL)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = -1;
	while (++i < lines)
	{
		dict[i] = malloc(sizeof(char *) * 2);
		dict[i][0] = fetch_keys(fd);
		dict[i][1] = fetch_values(fd);
	}
	dict[i] = NULL;
	return (dict);
}
