#include "so_long.h"

void	move_counting(t_vars *vars)
{
	char	*c;
	vars->c_move++;
	c = ft_itoa(vars->c_move);
	write(1, "now step = ", 10);
	write(1, c, ft_strlen(c));
	write(1, "\n", 1);
	free (c);
}

void contain_check(t_vars *vars, char *map)
{
	int i;
	int collect;
	int starting;
	int exit;

	i = 0;
	collect = 0;
	starting = 0;
	exit = 0;
	vars->contain = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			collect++;
		if (map[i] == 'E')
			exit++;
		if (map[i] == 'P')
			starting++;
		i++;
	}
	vars->c_collect = collect;
	if (starting == 1 && exit == 1 && collect > 0)
		vars->contain = 1;
}

void img_xpm_set(t_vars *vars)
{
	int x;
	int y;

	vars->wall = mlx_xpm_file_to_image(vars->mlx, WALL, &x, &y);
	vars->tile = mlx_xpm_file_to_image(vars->mlx, TILE, &x, &y);
	vars->chobo_up = mlx_xpm_file_to_image(vars->mlx, CHOBO_UP, &x, &y);
	vars->chobo_down = mlx_xpm_file_to_image(vars->mlx, CHOBO_DOWN, &x, &y);
	vars->chobo_right = mlx_xpm_file_to_image(vars->mlx, CHOBO_RIGHT, &x, &y);
	vars->chobo_left = mlx_xpm_file_to_image(vars->mlx, CHOBO_LEFT, &x, &y);
	vars->collect = mlx_xpm_file_to_image(vars->mlx, COLLECT, &x, &y);
	vars->exit_close = mlx_xpm_file_to_image(vars->mlx, EXIT_CLOSE, &x, &y);
	vars->exit_open = mlx_xpm_file_to_image(vars->mlx, EXIT_OPEN, &x, &y);
	vars->monster = mlx_xpm_file_to_image(vars->mlx, MONSTER, &x, &y);
}

int	ft_strlen_nonl(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	return (i);
}

void map_read(char *map_name, t_vars *vars)
{
	char *line;
	char *map = NULL;
	int fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	vars->c_collect = 0;
	vars->height = 0;
	vars->width_e = 1;
	vars->width = ft_strlen(line) - 1;
	while (line)
	{
		vars->height++;
		map = ft_strjoin_so(map, line);
		free (line);
		line = get_next_line(fd);
		if (line && vars->width != (ft_strlen_nonl(line)))
			vars->width_e = -1;
	}
	vars->map = map;
	contain_check(vars, vars->map);
	vars->c_move = 0;
	close(fd);
}