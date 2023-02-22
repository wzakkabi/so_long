/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:25:14 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/22 00:06:39 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_H
# define LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "./gg/get_next_line.h"
# include <unistd.h>

struct strct
{
	int E;
	int C;
	int P;
	int x;
	int y;
	int line;
};
int check_ECP(char **p);
int check_P_C_E(char **p);
void	check_path(char **mp, int *y, int x);
int check_line_first_and_last(char *p);
void	read_map(char ***map, char *file);

#endif