#include "./so_long.h"

static void input_w(t_vars *vars)
{
	int i = 0;
	while (vars->map[i])
	{
		if (vars->map[i] == 'P')
			break;
		i++;
	}
	if (i - vars->width < 0 || vars->map[i - vars->width] == '1')
		return ;
	if (vars->map[i - vars->width] == 'C')
		vars->c_collect -= 1;
	if (vars->map[i - vars->width] == 'E' && vars->c_collect == 0)
		end_game(vars, 0);
	else if (vars->map[i - vars->width] == 'M')
		end_game(vars, 1);
	if (vars->map[i - vars->width] != '1' && vars->map[i - vars->width] != 'E')
	{
		vars->map[i - vars->width] = 'P';
		vars->map[i] = '0';
		map_set(vars, W, vars->c_collect);
		move_counting(vars);
	}
}

static void	input_a(t_vars *vars)
{
	int i = 0;
	while (vars->map[i])
	{
		if (vars->map[i] == 'P')
			break;
		i++;
	}
	if (i - 1 < 0 || vars->map[i - 1] == '1')
		return ;
	if (vars->map[i - 1] == 'C')
		vars->c_collect -= 1;
	if (vars->map[i - 1] == 'E' && vars->c_collect == 0)
		end_game(vars, 0);
	else if (vars->map[i - 1] == 'M')
		end_game(vars, 1);
	if (vars->map[i - 1] != '1' && vars->map[i - 1] != 'E')
	{
		vars->map[i - 1] = 'P';
		vars->map[i] = '0';
		map_set(vars, A, vars->c_collect);
		move_counting(vars);
	}
}

static void	input_s(t_vars *vars)
{
	int i = 0;
	while (vars->map[i])
	{
		if (vars->map[i] == 'P')
			break;
		i++;
	}
	if (i + vars->width < 0 || vars->map[i + vars->width] == '1')
		return ;
	if (vars->map[i + vars->width] == 'C')
		vars->c_collect -= 1;
	if (vars->map[i + vars->width] == 'E' && vars->c_collect == 0)
		end_game(vars, 0);
	else if (vars->map[i + vars->width] == 'M')
		end_game(vars, 1);
	if (vars->map[i + vars->width] != '1' && vars->map[i + vars->width] != 'E')
	{
		vars->map[i + vars->width] = 'P';
		vars->map[i] = '0';
		map_set(vars, S, vars->c_collect);
		move_counting(vars);
	}
}

static void	input_d(t_vars *vars)
{
	int i = 0;
	while (vars->map[i])
	{
		if (vars->map[i] == 'P')
			break;
		i++;
	}
	if (i + 1 < 0 || vars->map[i + 1] == '1')
		return ;
	if (vars->map[i + 1] == 'C')
		vars->c_collect -= 1;
	if (vars->map[i + 1] == 'E' && vars->c_collect == 0)
		end_game(vars, 0);
	else if (vars->map[i + 1] == 'M')
		end_game(vars, 1);
	if (vars->map[i + 1] != '1' && vars->map[i + 1] != 'E')
	{
		vars->map[i + 1] = 'P';
		vars->map[i] = '0';
		map_set(vars, D, vars->c_collect);
		move_counting(vars);
	}
}

int	keyboard_input(int keycode, t_vars *vars)
{
	if (keycode == W)
		input_w(vars);
	else if (keycode == A)
		input_a(vars);
	else if (keycode == S)
		input_s(vars);
	else if (keycode == D)
		input_d(vars);
	else if (keycode == ESC)
		exit(0);
	return (0);	//no move
}