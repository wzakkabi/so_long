/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:24:26 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/17 15:41:33 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_path(char **mp, int y, int x)
{
	struct cnt date;
	while (mp[++y])
	{
		while (mp[y][++x])
		{
			date.x = 0;
			date.y = 0;
			if ((mp[y][x] == 'P' && mp[y][x + 1] == '0') || (mp[y][x] == 'P' &&
			mp[y][x + 1] == 'C') || (mp[y][x] == 'P' && mp[y][x + 1] == 'E'))
				mp[y][x + ++date.x] = 'P';
			else if ((mp[y][x] == 'P' && mp[y][x - 1] == '0') || (mp[y][x] == 'P' &&
			mp[y][x - 1] == 'C') || (mp[y][x] == 'P' && mp[y][x - 1] == 'E'))
				mp[y][x - ++date.x] = 'P';
			else if ((mp[y][x] == 'P' && mp[y + 1][x] == '0') || (mp[y][x] == 'P' &&
			mp[y + 1][x] == 'C') || (mp[y][x] == 'P' && mp[y + 1][x] == 'E'))
				mp[y + ++date.y][x] = 'P';
			else if ((mp[y][x] == 'P' && mp[y - 1][x] == '0') || (mp[y][x] == 'P' &&
			mp[y - 1][x] == 'C') || (mp[y][x] == 'P' && mp[y - 1][x] == 'E'))
				mp[y - ++date.y][x] = 'P';
			if(date.x != 0)
				x = 0;
			if(date.y != 0)
				y = 0;
		}
		x = 0;
	}
	return ft_checkp(mp);
}
// void	check_path(char **mp, int y, int x)
// {
// 	while (mp[y][++x])
// 	{
// 		if ((mp[y][x] == 'P' && mp[y][x + 1] == '0') || (mp[y][x] == 'P' &&
// 		mp[y][x + 1] == 'C') || (mp[y][x] == 'P' && mp[y][x + 1] == 'E'))
// 		{
// 			mp[y][x + 1] = 'P';
// 			x = 0;
// 		}
// 		if ((mp[y][x] == 'P' && mp[y][x - 1] == '0') || (mp[y][x] == 'P' &&
// 		mp[y][x - 1] == 'C') || (mp[y][x] == 'P' && mp[y][x - 1] == 'E'))
// 		{
// 			mp[y][x - 1] = 'P';
// 			x = 0;
// 		}
// 		if ((mp[y][x] == 'P' && mp[y + 1][x] == '0') || (mp[y][x] == 'P' &&
// 		mp[y + 1][x] == 'C') || (mp[y][x] == 'P' && mp[y + 1][x] == 'E'))
// 		{
// 			mp[y + 1][x] = 'P';
// 			y = 0;
// 		}
// 		if ((mp[y][x] == 'P' && mp[y - 1][x] == '0') || (mp[y][x] == 'P' &&
// 		mp[y - 1][x] == 'C') || (mp[y][x] == 'P' && mp[y - 1][x] == 'E'))
// 		{
// 			mp[y - 1][x] = 'P';
// 			y = 0;
// 		}
// 	}
// }