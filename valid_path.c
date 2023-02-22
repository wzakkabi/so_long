/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:23:55 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/22 01:51:57 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int check_ECP(char **p)
{
	struct strct s;
	s.y = ((s.x = -1),(s.E = 0),(s.C = 0),(s.P = 0), -1);
	s.line = ft_strlen(p[0]);
	while(p[++s.y])
	{
		while(p[s.y][++s.x])
		{
			if(p[s.y][s.x] == 'P')
				s.P++;
			else if(p[s.y][s.x] == 'E')
				s.E++;
			else if (p[s.y][s.x] == 'C')
				s.C++;
			else if (p[s.y][s.x] != '0' && p[s.y][s.x] != '1')
				return 1;
		}
		if (s.line != ft_strlen(p[s.y]) || p[s.y][0] != '1' || p[s.y][s.x - 1] != '1')
			return 2;
		s.x = -1;
	}
	if(s.E != 1 || s.P != 1 || s.C < 1)
		return 3;
	return 0;
}

void	check_path(char **mp, int *y, int x)
{
	struct strct	date;

	while (mp[*y][++x])
	{
		date.x = ((date.y = 0), 0);
		if ((mp[*y][x] == 'P' && mp[*y][x + 1] == '0') || (mp[*y][x] == 'P' &&
		mp[*y][x + 1] == 'C') || (mp[*y][x] == 'P' && mp[*y][x + 1] == 'E'))
			mp[*y][x + ++date.x] = 'P';
		else if ((mp[*y][x] == 'P' && mp[*y][x - 1] == '0') || (mp[*y][x] == 'P'
		&& mp[*y][x - 1] == 'C') || (mp[*y][x] == 'P' && mp[*y][x - 1] == 'E'))
			mp[*y][x - ++date.x] = 'P';
		else if ((mp[*y][x] == 'P' && mp[*y + 1][x] == '0') || (mp[*y][x] == 'P'
		&& mp[*y + 1][x] == 'C') || (mp[*y][x] == 'P' && mp[*y + 1][x] == 'E'))
			mp[*y + ++date.y][x] = 'P';
		else if ((mp[*y][x] == 'P' && mp[*y - 1][x] == '0') || (mp[*y][x] == 'P'
		&& mp[*y - 1][x] == 'C') || (mp[*y][x] == 'P' && mp[*y - 1][x] == 'E'))
			mp[*y - ++date.y][x] = 'P';
		if (date.x != 0 || date.y != 0)
			x = 0;
		if (date.y != 0)
			*y = 0;
	}
}

// int check_line_first_and_last(char *first, char *last)
// {
// 	int x;

// 	x = 0;
// 	if(!first || !last)
// 		return 0;
// 	while(first[x] && last[x])
// 	{
// 		if(first[x] != '1' || last[x] != '1')
// 			return 0;
// 		x++;
// 	}
// 	return 1;
// }

void	read_map(char ***map, char *file)
{
	int x = 0;
	int fd;
	char *cnt;

	fd = open(file, O_RDONLY);
	while(1)
	{
		cnt = get_next_line(fd);
		if(cnt == 0)
			break;
		//free(cnt);
		x++;
	}
	close(fd);
	(*map) = (char **)malloc((x + 1) * sizeof(int *));
	x = 0;
	fd = open(file, O_RDONLY);
	while(1)
	 {
	 	(*map)[x] = get_next_line(fd);
		if((*map)[x] == 0)
			break;
	 	x++;
	}
	close(fd);
}