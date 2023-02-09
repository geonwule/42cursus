#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

# define TILE "./img/tile.xpm"
# define WALL "./img/wall.xpm"
# define COLLECT "./img/collect.xpm"
# define EXIT_OPEN "./img/exit_open.xpm"
# define EXIT_CLOSE "./img/exit_close.xpm"
# define CHOBO_UP "./img/chobo_up.xpm"
# define CHOBO_DOWN "./img/chobo_down.xpm"
# define CHOBO_RIGHT "./img/chobo_right.xpm"
# define CHOBO_LEFT "./img/chobo_left.xpm"


typedef struct s_vars
{
	void	*mlx;
	void	*win;

    int     width;
    int     height;
    char    *map;
    int     c_collect;

    void    *tile;
    void    *wall;
    void    *collect;
    void    *exit_open;
    void    *exit_close;
    void    *chobo_up;
    void    *chobo_down;
    void    *chobo_right;
    void    *chobo_left;
}	t_vars;

#endif