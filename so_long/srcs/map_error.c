#include "so_long.h"

// 'E' 'C' 'P' min_1
int min_map_contain(t_vars *vars)
{
    if (vars->contain != 1)
    {
        write(2, "Map error : Not enough or overflow map consist\n", 47);
        return (1);
    }
    return (0);
}

// 정사각형 은 직사각형이다.
// 네 각의 크기가 모두 직각이다.
// 마주보는 두 변(대변)의 길이가 같다. -> 모든 width가 동일해야 한다. get_next할때 width 다를때 체크.
// 마주보는 두 변(대변)이 평행하다.
// 두 대각선의 길이가 같다.
// 각 대각선이 서로 합동인 직각삼각형으로 양분한다.
// 각 대각선이 내각이 분할되는 비율이 일정하다.
// 각 대각선을 지름으로 하는 원에 내접한다.
int rectangular_check(t_vars *vars)
{
    if (vars->width_e == -1)
    {
        write(2, "Map error : Map is not rectangular\n", 35);
        return (1);
    }
    return (0);
}

int surrounded_wall(t_vars *vars)
{
    int i;

    i = 0;
    while (vars->map[i] != '\0')
    {
        if ((i < vars->width && vars->map[i] != '1') ||                         // 윗변
            (i % vars->width == 0 && vars->map[i] != '1') ||                    // 왼쪽사이드
            ((i >= vars->width * (vars->height - 1)) && vars->map[i] != '1') || // 아랫변
            ((i + 1) % vars->width == 0 && vars->map[i] != '1'))                // 오르쪽 사이드
        {
            write(2, "Map error : Not surrounded wall\n", 32);
            return (1);
        }
        i++;
    }
    return (0);
}

// for (int i = 0; i < (int)ft_strlen(map); i++)
// {
//     printf("%c", map[i]);
//     if ((i == 12 && i != 13) || (i - 12) % 13 == 0)
//         printf("\n");
// }
// printf("\n");

// int parsing_able(t_vars *vars)
// {
// }