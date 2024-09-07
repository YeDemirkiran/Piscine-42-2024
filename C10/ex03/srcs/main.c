/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 00:26:14 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/05 19:43:52 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

char	*g_program_name;
char	*g_hex;
char	*g_buffer;
char	*g_buf_prev;
int		g_duplicated;
int		g_offset;
int		g_cnt;
int		g_is_on_flag_c;
int		g_last_lines;
int		g_bfd;

int	str_cmp(char *a, char *b)
{
	int	i;

	i = -1;
	while (++i < 16)
		if (a[i] != b[i])
			return (0);
	return (1);
}

void	hexdump_stdin(void)
{
	while (read(0, &g_buffer[g_cnt], 1))
		if (++g_cnt == 16)
			print();
}

void	hexdump_files(int argc, char *argv[], int i, int fd)
{
	i = g_is_on_flag_c;
	while (++i < argc)
	{
		if (open_file(argv[i], &fd) == 0)
			continue ;
		while (read(fd, &g_buffer[g_cnt], 1))
		{
			g_bfd = 0;
			if (errno)
			{
				print_error(argv[i]);
				break ;
			}
			if (++g_cnt == 16)
				print();
		}
	}
	if (g_bfd)
	{
		errno = 9;
		print_error(argv[argc - 1]);
	}
}

void	init_global_vars(void)
{
	g_hex = "0123456789abcdef";
	g_is_on_flag_c = 0;
	g_last_lines = 0;
	g_offset = 0;
	g_cnt = 0;
	g_bfd = 1;
	g_duplicated = 0;
	g_buf_prev = (char *)malloc(17);
	g_buffer = (char *)malloc(17);
}

int	main(int argc, char *argv[])
{
	g_program_name = argv[0];
	init_global_vars();
	if (argc >= 2 && is_flag_c(argv[1]))
		g_is_on_flag_c = 1;
	if (argc == g_is_on_flag_c + 1)
		hexdump_stdin();
	else
		hexdump_files(argc, argv, 0, 0);
	if (g_last_lines)
	{
		if (g_cnt)
		{
			print_input_offset(7, g_offset);
			print_hexadecimal_bytes(g_buffer, 8 * (g_cnt / 8) + g_cnt);
			print_hexadecimal_bytes(g_buffer + 8, g_cnt - 8);
			if (g_is_on_flag_c)
				print_characters(g_buffer, g_cnt);
			ft_putchar('\n');
		}
		print_input_offset(7, g_offset + g_cnt);
		ft_putchar('\n');
	}
	free(g_buffer);
	return (0);
}
