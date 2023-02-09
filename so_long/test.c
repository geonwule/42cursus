#include <mlx.h>
#include "./so_long.h"

void	img_xpm_set(t_vars *vars)
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
}

void	collect_check(int *c, char *map)
{
	int i = 0;
	int j = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			j++;
		i++;
	}
	*c = j;
}
char	*ft_so_long_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i[2];

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2[s2_len - 1] == '\n')
		s2_len -= 1;
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (0);
	i[0] = -1;
	i[1] = -1;
	while (++i[0] < s1_len)
		str[i[0]] = s1[i[0]];
	while (++i[1] < s2_len)
		str[i[0] + i[1]] = s2[i[1]];
	str[s1_len + s2_len] = '\0';
	if (s1 != NULL)
		free((void *)s1);
	return (str);
}

void	map_read(char *map_name, t_vars *vars)
{
	char	*line;
	char	*str = NULL;
	int	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	vars->c_collect = 0;
	vars->height = 0;
	vars->width = ft_strlen(line) - 1;
	while (line)
	{
		vars->height++;
		str = ft_so_long_strjoin(str, line);
		line = get_next_line(fd);
	}
	vars->map = str;
	printf("map = %s\n", vars->map);
	collect_check(&vars->c_collect, vars->map);
	close(fd);
}

void	map_set(t_vars *vars, int key_code, int c_collect)
{
	int height = 0;
	int width;

	while (height < vars->height)
	{
		width = 0;
		while (width < vars->width)
		{
			if (vars->map[height*(vars->width) + width] == '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->wall, width*50, height*50);
			}
			else
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->tile, width*50, height*50);
			}
			width++;
		}
		height++;
	}
}

//cc -L./mini_libx/minilibx-linux -lmlx -framework OpenGL -framework AppKit
int main(int ac, char **av)
{
	t_vars	*vars;
	void	*img_ptr;
	char	*filename = "./img/50_50_resize/chobo_left.xpm";
	char	*mapname = av[1];
	int a=5, b=5;

	vars = malloc(sizeof(t_vars));
	map_read(mapname, vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width*50, vars->height*50, "mlx_test");
	img_xpm_set(vars);
	map_set(vars, 2, vars->c_collect);
	// mlx_key_hook(vars->win, close, vars);
	// mlx_hook(vars->win, 17, 0, exit_game, vars);
	mlx_loop(vars->mlx);
}
// mlx_put_image_to_window(vars.mlx, vars.mlx, img_ptr, 5, 5);

// #include <stdio.h>

// int create_trgb(int t, int r, int g, int b)
// {
//     return (t << 24 | r << 16 | g << 8 | b);
// 	//return (t << 24 | r << 16 | g << 8 | b);
// // << 이 부분이 bit 이동하는 부분임.
// // | 8 | 8 | 8 | 8 | 
// // 32  24  16  8       이런 구조가 있다고 생각하면
// // t는 맨 앞 칸에, r은 두 번째 칸에, ...  이렇게 담김
// }

// int	get_t(int trgb)
// {
// 	return (trgb & (0xFF << 24));
// }

// int main()
// {
// /*	unsigned char num1 = 1;
// 	unsigned char num2 = 3;

// 	printf("%d\n", num1 & num2);

// 	printf("%d\n", num1 | num2);*/
// 	int trgb;
// 	trgb = create_trgb(10, 7, 4, 1);
// 	printf("trgb = %d\n", trgb);
// 	printf("t = %d\n", get_t(trgb));
// }
