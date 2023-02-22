/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:04:13 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/02/23 00:07:12 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "long.h"

int test_map(char *file)
{
    char **map;
    int vld;
    struct strct s;
    int x = 0;
    read_map(&map, file);
    vld = check_ecp(map, s);
    if(vld == 1)
        printf("there is someting other caracter in the map");
    else if(vld == 2)
        printf("check 1 in the firt or the last or line");
    else if (vld == 3)
        printf("check P OR C or E");
    else if(vld == 4)
        printf("check the first line or the last");
    else
    {
        vld = 0;
        while(map[vld])
        {
            check_path(map, &vld, 0);
            vld++;
        }
        vld = check_p_path_valid_or_not(map);
        if(vld == 0)
            return 0;
    }
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
            if(x == 1)
            {
                printf("1");
            }
            else
                printf("path_invalid :(");
        }
    }
    return 0;
}