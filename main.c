/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:04:13 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/21 23:57:29 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int test_map(char *file)
{
    char **map;
    int vld;
    read_map(&map, file);
    vld = check_ECP(map);
    return 1;
}

int main(int ac, char **av)
{
    int x = 0;
    if(ac == 2)
    {
        while(av[1] && av[1][x] != '.')
                x++;
        if(av[1][x] == '.' && av[1][x + 1] == 'b' && av[1][x + 2] == 'e' && av[1][x + 3] == 'r')
        {
            x = test_map(av[1]);
        }
    }
    return 0;
}