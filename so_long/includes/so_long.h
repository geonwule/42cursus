#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>  // clean..
// # include "../mini_libx/mlx.h"
#include "get_next_line.h"

#define TILE "./img/tile.xpm"
#define WALL "./img/wall.xpm"
#define COLLECT "./img/collect.xpm"
#define EXIT_OPEN "./img/exit_open.xpm"
#define EXIT_CLOSE "./img/exit_close.xpm"
#define CHOBO_UP "./img/chobo_up.xpm"
#define CHOBO_DOWN "./img/chobo_down.xpm"
#define CHOBO_RIGHT "./img/chobo_right.xpm"
#define CHOBO_LEFT "./img/chobo_left.xpm"
#define MONSTER "./img/monster.xpm"
#define W 13
#define A 0
#define S 1
#define D 2
#define ESC 53

typedef struct s_vars
{
    void *mlx;
    void *win;

    int width;
    int width_e;
    int height;
    char *map;
    char *map2;
    int contain;
    int c_collect;
    int c_move;

    void *tile;
    void *wall;
    void *collect;
    void *exit_open;
    void *exit_close;
    void *chobo_up;
    void *chobo_down;
    void *chobo_right;
    void *chobo_left;
    void *monster;
} t_vars;

//main
void var_free(t_vars *vars);

// map_error
int min_map_contain(t_vars *vars);
int rectangular_check(t_vars *vars);
int surrounded_wall(t_vars *vars);
int valid_path(t_vars *vars);

// map_init
void map_read(char *map_name, t_vars *vars);
void img_xpm_set(t_vars *vars);
void collect_check(int *c, char *map);
void move_counting(t_vars *vars);

// map_set
void map_set(t_vars *vars, int key_code); //, int c_collect);
void end_game(t_vars *vars, int win_or_fail);

// key_input
int keyboard_input(int keycode, t_vars *vars);
void move_counting(t_vars *vars);

// util
char *ft_itoa(int n);
char *ft_strjoin_so(char const *s1, char const *s2);
char *ft_strdup_so(const char *s1);

#endif