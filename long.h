/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:25:14 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/17 17:07:54 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_H
# define LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "./gg/get_next_line.h"
# include <unistd.h>

struct cnt
{
	char **p;
	int plr;
	int E;
	int C;
	int x;
	int line;
	int i;
	int y;
};
int check_P_C_E(int fd);
int ft_checkp(char **p);
void	check_path(char **mp, int y, int x);
int check_line_first_and_last(char *p);
char **read_maps(int fd);

#endif