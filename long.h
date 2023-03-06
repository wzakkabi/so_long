/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:25:14 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/06 23:23:40 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LONG_H
# define LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "./gg/get_next_line.h"
# include <unistd.h>

struct s_strct
{
	int	e;
	int	c;
	int	p;
	int	x;
	int	y;
	int	line;
};

struct s_game
{
	void	*mlx;
	void	*mlx_wind;
	void	*imgstone;
	void	*imghol;
	void	*imgcoin;
	void	*imgtri9;
	void	*imgplr;
	char	**mp;
	int		xpostion;
	int		ypostion;
	int		xepostion;
	int		yepostion;
	int		img_width;
	int		img_height;
	int		y;
	int		x;
	int		move;
	int		move_new_line;
	int		coin;
	int		c;
};

int		putstr(char *a);
void	free_malloc(char **p, int not_struct, struct s_game *g);
int		test_map(char *file);
void	ft_putnbr(int n);
int		main(int ac, char **av);
void	so_long(char *file);
void	put_xpm_to_pointer(struct s_game *g);
void	move_gg(struct s_game *g);
int		ft_close(struct s_game *g);
int		test(int key, struct s_game *g);
void	count_c_e(struct s_game *g);
void	put_img(struct s_game *g);
void	put_img_chyata(struct s_game *g);
int		check_ecp(char **p, struct s_strct s);
int		check_p_path_valid_or_not(char **p);
void	check_path(char **mp, int *y, int x);
int		check_line_first_and_last(char *first, char *last);
void	read_map(char ***map, char *file);
#endif