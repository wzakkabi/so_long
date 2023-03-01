/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:15:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/01 00:10:19 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

void so_long(char **mp)
{
	void *mlx;
	void *mlx_win;

	int x = 0;
	int y = 0;
	while(mp[y])
		y++;
	x = ft_strlen(mp[x]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, x * 50, y * 50, "so_long");
	mlx_loop(mlx);
}
// int main()
// {
// 	void *mlx;
// 	void *mlx_win;
	
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 700, "so_long");
// 	mlx_loop(mlx);
// }