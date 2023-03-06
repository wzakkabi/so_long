/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:23:55 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/06 19:03:49 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"
//function check wach kain C ola E ola  p and if there is some other carracter

int	check_ecp(char **p, struct s_strct s)
{
	s.y = ((s.e = 0), (s.c = 0), (s.p = 0), (s.line = ft_strlen(p[0])), -1);
	while (p[++s.y])
	{
		s.x = -1;
		while (p[s.y][++s.x])
		{
			if (p[s.y][s.x] == 'P')
				s.p++;
			else if (p[s.y][s.x] == 'E')
				s.e++;
			else if (p[s.y][s.x] == 'C')
				s.c++;
			else if (p[s.y][s.x] != '0' && p[s.y][s.x] != '1')
				return (putstr("there is someting other caracter in the map"));
		}
		if (s.line != ft_strlen(p[s.y]) || p[s.y][0] != '1' ||
		p[s.y][s.x - 1] != '1')
			return (putstr("check 1 in the firt or the last or line"));
	}
	if (check_line_first_and_last(p[0], p[s.y - 1]) == 0)
		return (putstr("check the first line or the last"));
	if (s.e != 1 || s.p != 1 || s.c < 1)
		return (putstr("check P OR C or E"));
	return (1);
}
//check wach kain fin idoz l player bach i yakol kolchi

int	check_p_path_valid_or_not(char **p)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (p[++y])
	{
		while (p[y][++x])
		{
			if (p[y][x] == 'C' || p[y][x] == 'E')
				return (0);
		}
		x = -1;
	}
	return (1);
}

/*hna kan3mer kolchi b p fin 9der iwsl l player o 
flkher kantcheck wach ba9a chi c ola E ila kaint ba9a rah invalid path*/
void	check_path(char **mp, int *y, int x)
{
	struct s_strct	date;

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

// hna kan9lb ela '1' wach kain f lkher o lwel
int	check_line_first_and_last(char *first, char *last)
{
	int	x;

	x = 0;
	if (!first || !last)
		return (0);
	while (first[x] && last[x])
	{
		if (first[x] != '1' || last[x] != '1')
			return (0);
		x++;
	}
	return (1);
}

//hna kan read l map o kan malloki liha
void	read_map(char ***map, char *file)
{
	int		x;
	int		fd;
	char	*cnt;

	fd = ((x = 0), open(file, O_RDONLY));
	while (1)
	{
		cnt = get_next_line(fd);
		if (cnt == 0)
			break ;
		free(cnt);
		x++;
	}
	close(fd);
	(*map) = (char **)malloc((x + 1) * sizeof(int *));
	x = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		(*map)[x] = get_next_line(fd);
		if ((*map)[x] == 0)
			break ;
		x++;
	}
	close(fd);
}
