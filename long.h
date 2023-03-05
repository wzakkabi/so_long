/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:25:14 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/05 20:22:30 by wzakkabi         ###   ########.fr       */
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

struct game
{
	void *mlx;
	void *mlx_wind;
	void *imgstone;
	void *imghol;
	void *imgcoin;
	void *imgtri9;
	void *imgplr;
	char **mp;
	int xpostion;
	int ypostion;
	int xEpostion;
	int yEpostion;
	int		img_width;
	int		img_height;
	int y;
	int x;
	int move;
	int coin;
	int C;
};

void move_gg(struct game *g);
void	ft_putnbr_fd(int n, int fd);
int	check_ecp(char **p, struct strct s);
int		check_P_C_E(char **p);
void	check_path(char **mp, int *y, int x);
int		check_line_first_and_last(char *first, char *last);
int		check_p_path_valid_or_not(char **p);
void	read_map(char ***map, char *file);
int putstr(char *a);
void free_malloc(char **p);
void so_long(char *file);
void put_img(struct game *g);

#endif