/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 00:30:20 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/05 18:16:45 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

extern char	*g_program_name;
extern char	*g_buffer;
extern char	*g_hex;
extern int	g_is_on_flag_c;
extern int	g_duplicated;
extern int	g_offset;
extern int	g_cnt;
extern char	*g_buf_prev;
extern int	g_last_lines;

int		is_printable(unsigned char c);
void	ft_putchar(unsigned char c);
void	ft_putstr(char *str);
int		open_file(char *path, int *fd);
void	print_input_offset(int n, int offset);
void	print_hexadecimal_bytes(char *str, int size);
void	print_characters(char *str, int len);
void	print_error(char *file);
int		is_flag_c(char *str);
void	print(void);
int		str_cmp(char *a, char *b);

#endif
