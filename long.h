/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:25:14 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/02 00:46:06 by wzakkabi         ###   ########.fr       */
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

struct s_image
{
	void *mlx;
	void *img;
	char *relative_path;
	int img_width;
	int img_height;
}t_img;


int	check_ecp(char **p, struct strct s);
int		check_P_C_E(char **p);
void	check_path(char **mp, int *y, int x);
int		check_line_first_and_last(char *first, char *last);
int		check_p_path_valid_or_not(char **p);
void	read_map(char ***map, char *file);
int putstr(char *a);
void free_malloc(char **p);
void so_long(char **mp);

#endif