/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:23:55 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/17 16:32:00 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int ft_checkp(char **p)
{
	struct cnt date;
	
	date.i = 0;
	date.x = 0;
	while(p[date.i])
	{
		while(p[date.i][date.x])
		{
			if(p[date.i][date.x] == 'E' || p[date.i][date.x] == 'C')
				return 1;
			date.x++;
		}
		date.x = 0;
		date.i++;
	}
	return 0;
}

void	check_path(char **mp, int y, int x)
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
}

int check_line_first_and_last(char *p)
{
	int x = 0;
	if(!p)
		return 0;
	while(p[x])
	{
		if(p[x] != '1')
			return 0;
		x++;
	}
	return 1;
}

char **read_maps(int fd)
{
	struct cnt date;

	date.x = 0;
	while(1)
	{
		date.p[date.x] = get_next_line(fd);
		if(date.p[date.x] == 0)
			break;
		date.x++;
	}
	return date.p;
}