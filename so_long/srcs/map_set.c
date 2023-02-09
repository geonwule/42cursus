#include "./so_long.h"

void	end_game(t_vars *vars, int win_or_fail)
{
	if (vars->c_move < 0)	// free_need
		return ;
	if (win_or_fail)
		write(1, "Oh my god... fail...\n", 21);
	else
		write(1, "Success!! game end!!\n", 21);
	exit(0);
}

static void	exit_put_image(t_vars *vars, int width, int height)
{
	if (vars->c_collect == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_open, width*50, height*50);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_close, width*50, height*50);
}

static void	player_put_image(t_vars *vars, int width, int height, int key)
{
	if (key == W)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chobo_up, width*50, height*50);
	else if (key == A)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chobo_left, width*50, height*50);
	else if (key == S)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chobo_down, width*50, height*50);
	else if (key == D)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->chobo_right, width*50, height*50);
}

void map_set(t_vars *vars, int key_code, int c_collect)
{
	int height = 0;
	int width;

	if (c_collect < 0)	// c_collect where?
		return ;
	while (height < vars->height)
	{
		width = 0;
		while (width < vars->width)
		{
			if (vars->map[height*(vars->width) + width] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, width*50, height*50);
			else if (vars->map[height*(vars->width) + width] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->tile, width*50, height*50);
			else if (vars->map[height*(vars->width) + width] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collect, width*50, height*50);
			else if (vars->map[height*(vars->width) + width] == 'P')
				player_put_image(vars, width, height, key_code);
			else if (vars->map[height*(vars->width) + width] == 'E')
				exit_put_image(vars, width, height);
			else if (vars->map[height*(vars->width) + width] == 'M')	//bonus
				mlx_put_image_to_window(vars->mlx, vars->win, vars->monster, width*50, height*50);
			width++;
		}
		height++;
	}
}