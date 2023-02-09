#include <mlx.h>
#include <stdlib.h>

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

//cc -L./mini_libx/minilibx-linux -lmlx -framework OpenGL -framework AppKit
int main(int ac, char **av)
{
	t_vars	*vars;

    vars = malloc(sizeof(t_vars));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 300, 300, "mlx_test");
	// map_read(mapname, vars);
	// img_xpm_set(vars);
	// map_set(vars, 2, vars->c_collect);
	// mlx_key_hook(vars->win, close, vars);
	// mlx_hook(vars->win, 17, 0, exit_game, vars);
	mlx_loop(vars->mlx);
}