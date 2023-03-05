/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:15:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/05 08:50:16 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"



int test(int key, void *p)
{
	(void) p;
	printf("%d\n", key);
	return 0;
}

void so_long(char *file)
{
	struct game g;
	char **mp;
	read_map(&mp, file);
	g.x = ft_strlen(mp[0]);
	g.y = 0;
	while(mp[g.y])
		g.y++;
	if(g.x > 32 || g.y > 16)
	{
		write(1,"x and y not rghit ;(", 20);
		return ;
	}
	g.mlx = mlx_init();
	g.imgstone = mlx_xpm_file_to_image(g.mlx, "./xpm/stone.xpm", &g.img_width, &g.img_height);
	g.imgplr = mlx_xpm_file_to_image(g.mlx, "./xpm/player.xpm", &g.img_width, &g.img_height);
	g.imgtri9 = mlx_xpm_file_to_image(g.mlx, "./xpm/tri9.xpm", &g.img_width, &g.img_height);
	g.imgcoin = mlx_xpm_file_to_image(g.mlx, "./xpm/coin.xpm", &g.img_width, &g.img_height);
	g.imghol = mlx_xpm_file_to_image(g.mlx, "./xpm/hol.xpm", &g.img_width, &g.img_height);
	g.mlx_wind = mlx_new_window(g.mlx, g.x * 79, g.y * 79, "so_long");
	g.x = -1;
	g.y = -1;
	while(mp[++g.y])
	{
		g.x = -1;
		while(mp[g.y][++g.x])
		{
			if(mp[g.y][g.x] == '1')
				mlx_put_image_to_window(g.mlx, g.mlx_wind, g.imgstone, g.x * 79, g.y * 79);
			else if(mp[g.y][g.x] == '0')
				mlx_put_image_to_window(g.mlx, g.mlx_wind, g.imgtri9, g.x * 79, g.y * 79);
			else if(mp[g.y][g.x] == 'P')
			{
				mlx_put_image_to_window(g.mlx, g.mlx_wind, g.imgtri9, g.x * 79, g.y * 79);
				mlx_put_image_to_window(g.mlx, g.mlx_wind, g.imgplr, g.x * 79, g.y * 79);
			}
			else if(mp[g.y][g.x] == 'C')
				mlx_put_image_to_window(g.mlx, g.mlx_wind, g.imgcoin, g.x * 79, g.y * 79);
			else if(mp[g.y][g.x] == 'E')
				mlx_put_image_to_window(g.mlx, g.mlx_wind, g.imghol, g.x * 79, g.y * 79);
		}
	}
	mlx_key_hook(g.mlx_wind, test, NULL);
	mlx_loop(g.mlx);
}










// void so_long(char **mp)
// {
// 	void *mlx;
// 	void *mlx_win;
// 	void	*img;
// 	int		img_width;
// 	int		img_height;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx,1920, 1080, "so_long");
// 	// t_img.img = 
	
// 	img = mlx_xpm_file_to_image(mlx, "MiConv.com__New Project.xpm", &img_width, &img_height);
// 	mlx_put_image_to_window(mlx,  mlx_win, img, 0, 0);
// 	mlx_loop(mlx);
// }
