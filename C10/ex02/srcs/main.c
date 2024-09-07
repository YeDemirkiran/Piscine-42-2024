/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:29:06 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/05 16:23:26 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

char	*g_program_name;
char	*g_buffer;
int		g_buffer_size;
int		g_fd;

void	display_file(int fd)
{
	long long	i;
	int			tmp;

	if (g_buffer_size <= 0)
	{
		while (read(fd, g_buffer, 1))
			if (errno)
				return ;
	}
	else
	{
		i = 0;
		while (read(fd, &g_buffer[i % g_buffer_size], 1))
		{
			if (errno)
				return ;
			++i;
		}
		tmp = i % g_buffer_size;
		if (i >= g_buffer_size)
			write(1, g_buffer + tmp, g_buffer_size - tmp);
		write(1, g_buffer, tmp);
	}
}

void	display(int argc, char *argv[])
{
	int	i;

	i = 2;
	while (++i < argc)
	{
		errno = 0;
		g_fd = open(argv[i], O_RDONLY);
		if (g_fd == -1)
		{
			print_error(argv[i]);
			continue ;
		}
		if (argc > 4)
		{
			if (i > 3)
				ft_putstr("\n");
			ft_putstr("==> ");
			ft_putstr(argv[i]);
			ft_putstr(" <==\n");
		}
		display_file(g_fd);
		close(g_fd);
	}
}

int	main(int argc, char *argv[])
{
	g_program_name = argv[0];
	g_buffer_size = ft_atoi(argv[2]);
	g_buffer = (char *)malloc(g_buffer_size);
	if (argc == 3)
		display_file(0);
	else
		display(argc, argv);
	free(g_buffer);
	return (0);
}
