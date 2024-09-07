/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yademirk <yademirk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:40:33 by yademirk          #+#    #+#             */
/*   Updated: 2024/09/01 20:20:16 by yademirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# define DICT_PATH "./numbers.dict"

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_newline(void);
void	ft_putstr(char *str);
long	is_space(char c);
long	is_numeric(char c);
long	str_cmp(char *str1, char *str2);

long	ft_pow(long num, long pow);
long	int_len(long nbr);
long	get_int_face_value(long nbr, long index);
long	get_int_place_value(long nbr, long index);
long	trim_int(long nbr, long times, int fix_zeros);

long	ft_atoi(char *str);
char	*ft_itoa(long nbr);

long	file_lines(char *path);
long	check_input(char *str);
char	*fill_string(char buffer[256], long len);
char	*fetch_keys(long fd);
char	*fetch_values(long fd);
char	***fetch_dict(char *path);
long	search_key_in_dict(char ***dict, char *key);
char	*get_value_in_dict(char ***dict, char *key);
void	print_nbr_dict(char ***dict, long nbr);

#endif
