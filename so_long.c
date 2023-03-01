/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:15:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/02 00:55:41 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"


void so_long(char **mp)
{
	struct t_img;
	void *mlx;
	void *mlx_win;
	int x = 0;
	int y = 0;

	t_img.relative_path = "./stone.xpm";
	while(mp[y])
		y++;
	x = ft_strlen(mp[x]);
	t_img.img_width = 10;
	t_img.img_height = 10;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, x * 50, y * 50, "so_long");
	t_img.img = mlx_xpm_file_to_image(mlx, t_img.relative_path, &t_img.img_width , &t_img.img_height);
	
	mlx_loop(mlx);
}
