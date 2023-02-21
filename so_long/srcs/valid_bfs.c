#include "so_long.h"

static int bfs(t_vars *vars, int *c_cnt, int step, int *exit)
{
    char *map = vars->map2;

    
}

static char *map_copy(t_vars *vars)
{
    char *map2;

    map2 = (char *)malloc(sizeof(char) * (ft_strlen(vars->map) + 1));
    if (map2 == NULL)
        return (0);
    ft_strlcpy(map2, vars->map, ft_strlen(vars->map) + 1);
    return (map2);
}

int valid_path_bfs(t_vars *vars)
{
    int i;
    int p;
    int c_cnt = vars->c_collect;
    int e;

    i = 0;
    p = 0;
    vars->map2 = map_copy(vars);
    while (vars->map[i] != '\0')
    {
        if (vars->map[i] == 'P')
            p = i;
        i++;
    }
    e = 0;
    if (!bfs(vars, &c_cnt, p, &e))
        return (1);
    return (0);
}