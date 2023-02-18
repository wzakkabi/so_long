/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:15:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/18 13:35:43 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int check_P_C_E(char **p)
{
	struct cnt date;

	date.x = ((date.E = 0),(date.C = 0),(date.plr = 0),(date.i = 0),0);
	while (p[++date.i])
	{
		date.line = ft_strlen(p[0]);
		if (date.line != ft_strlen(p[date.i]) || p[date.i][0] != '1' || p[date.i][date.line - 1] != '1')
			return (0);
		date.x = 0;
		while (p[date.i][date.x])
		{
			if (p[date.i][date.x] == 'P')
				date.plr++;
			else if (p[date.i][date.x] == 'C')
				date.C++;
			else if (p[date.i][date.x] == 'E')
				date.E++;
			date.x++;
		}
	}
	if (date.E != 1 || date.plr != 1 || date.C < 1)
		return (2);
	if (check_line_first_and_last(p[0]) == 0 || check_line_first_and_last(p[date.i - 1]) == 0)
		return (3);
	return (1);
}
