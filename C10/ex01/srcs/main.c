/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 22:19:59 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/05 16:22:50 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	print_error(char *path, char *program_name)
{
	ft_putstr(basename(program_name));
	ft_putstr(": ");
	ft_putstr(path);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	errno = 0;
}

void	display_file(char *program_name, char *path)
{
	int				fd;
	long			size;
	unsigned char	buf[BUFFER_SIZE];

	if (path == NULL)
		fd = 0;
	else
		fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		print_error(path, program_name);
		return ;
	}
	size = read(fd, buf, BUFFER_SIZE);
	while (size)
	{
		if (errno)
		{
			print_error(path, program_name);
			return ;
		}
		write(1, buf, size);
		size = read(fd, buf, BUFFER_SIZE);
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		display_file(argv[0], 0);
	else
	{
		i = 0;
		while (++i < argc)
			display_file(argv[0], argv[i]);
	}
	return (0);
}
