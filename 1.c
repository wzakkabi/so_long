/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 09:24:26 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/15 13:29:54 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_P_C_E(int fd)
{
	struct cnt date;
	
	date.x = 0;
	date.E = 0;
	date.C = 0;
	date.plr = 0;
	date.i = 0;
	while(date.p[date.i])
	{
		date.p[date.i] = get_next_line(fd);
		if(!date.p[date.i])
			break;
		date.line = ft_strlen(date.p[0]);
		if(date.line != ft_strlen(date.p[date.i]) || date.p[date.i][0] != '1' || date.p[date.i][date.line - 1] != '1')
			return 0;
		date.x = 0;
		while(date.p[date.i][date.x])
		{
			if(date.p[date.i][date.x] == 'P')
				date.plr++;
			else if(date.p[date.i][date.x] == 'C')
				date.C++;
			else if(date.p[date.i][date.x] == 'E')
				date.E++;
			date.x++;
		}
		date.i++;
	}
	if(date.E != 1 || date.plr != 1 || date.C <= 1)
		printf("check P or E or C");
		return 3;
	return 1;
}

// void	check_path(char **mp, int y, int x)
// {
// 	while (mp[y])
// 	{
// 		while (mp[y][x])
// 		{
// 			if ((mp[y][x] == 'P' && mp[y][x + 1] == '0') || (mp[y][x] == 'P' &&
// 			mp[y][x + 1] == 'C') || (mp[y][x] == 'P' && mp[y][x + 1] == 'E'))
// 				mp[y][x + 1] = 'P';
// 			if ((mp[y][x] == 'P' && mp[y][x - 1] == '0') || (mp[y][x] == 'P' &&
// 			mp[y][x - 1] == 'C') || (mp[y][x] == 'P' && mp[y][x - 1] == 'E'))
// 				mp[y][x - 1] = 'P';
// 			if ((mp[y][x] == 'P' && mp[y + 1][x] == '0') || (mp[y][x] == 'P' &&
// 			mp[y + 1][x] == 'C') || (mp[y][x] == 'P' && mp[y + 1][x] == 'E'))
// 			{
// 				mp[y + 1][x] = 'P';
// 				check_path(mp, 0, 0);
// 			}
// 			if ((mp[y][x] == 'P' && mp[y - 1][x] == '0') || (mp[y][x] == 'P' &&
// 			mp[y - 1][x] == 'C') || (mp[y][x] == 'P' && mp[y - 1][x] == 'E'))
// 				mp[y - 1][x] = 'P';
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }
