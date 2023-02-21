#include "so_long.h"

int exit_game(t_vars *vars)
{
	write(1, "Player has exited the game\n", 27);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->map);
	free(vars->map2);
	free(vars);
	exit(0);
}

// atexit (leaks); /// 가장 윗부분
// void leaks(void) { system("leaks so_long"); }

int map_error(t_vars *vars)
{
	int ret;

	ret = 0;
	if (min_map_contain(vars))
		ret = 1;
	else if (rectangular_check(vars))
		ret = 1;
	else if (surrounded_wall(vars))
		ret = 1;
	else if (valid_path(vars))
	{
		write(2, "Map error : Not valid path\n", 27);
		ret = 1;
	}
	if (ret == 1)
	{
		var_free(vars);
		return (1);
	}
	return (0);
}

void var_free(t_vars *vars)
{
	if (vars->map)
		free(vars->map);
	if (vars->map2)
		free(vars->map2);
	free(vars);
}

void leaks(void) { system("leaks so_long"); } 
// cc -L./mini_libx/minilibx-linux -lmlx -framework OpenGL -framework AppKit
int main(int ac, char **av)
{
	t_vars *vars;
	char *mapname = av[1];
	atexit (leaks); /// 가장 윗부분 
	if (ac != 2)
	{
		write(2, "input only one map\n", 19);
		return (0);
	}
	vars = malloc(sizeof(t_vars));
	map_read(mapname, vars);
	if (map_error(vars))
		return (0);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width * 50, vars->height * 50, "so_long");
	img_xpm_set(vars);
	map_set(vars, 2); //, vars->c_collect);
	mlx_key_hook(vars->win, keyboard_input, vars);
	mlx_hook(vars->win, 17, 0, exit_game, vars);
	mlx_loop(vars->mlx);
}