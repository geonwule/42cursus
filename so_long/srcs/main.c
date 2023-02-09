#include "./so_long.h"

// cc -L./mini_libx/minilibx-linux -lmlx -framework OpenGL -framework AppKit
int main(int ac, char **av)
{
	t_vars *vars;
	char *mapname = av[1];

	if (ac != 2)
		return (0);
	vars = malloc(sizeof(t_vars));
	map_read(mapname, vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width * 50, vars->height * 50, "so_long");
	img_xpm_set(vars);
	map_set(vars, 2, vars->c_collect);
	mlx_key_hook(vars->win, keyboard_input, vars);
	// mlx_key_hook(vars->win, close, vars);
	// mlx_hook(vars->win, 17, 0, exit_game, vars);
	mlx_loop(vars->mlx);
}