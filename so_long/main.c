#include <mlx.h>

typedef struct s_data{
    void    *img;
    void    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

typedef struct s_vars{
    void    *mlx;
    void    *win;
}   t_vars;

//cc -Lmini_libx/minilibx-linux -lmlx -framework OpenGL -framework Appkit main.c
int main()
{
    void    *mlx;
    t_data    img;
    void    *mlx_win;
    char    *relative_path = "./img/50_50_resize/chobo_left.xpm";
    int     img_width = 50;
    int     img_height = 50;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1080, 720, "new_window");
    img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    //img.img = mlx_new_image(mlx, 1080, 720);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    //my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}

// int main()
// {
//     t_vars  vars;

//     vars.mlx = mlx_init();
//     vars.win = mlx_new_window(vars.mlx, 1080, 720, "Hello world!");
//     mlx_hook(vars.win, 2, 1L<<0, close, &vars);
//     mlx_loop(vars.mlx);
// }


// int render_next_frame(void *YourStruct);

// int main()
// {
//     void    *mlx;

//     mlx = mlx_init();
//     mlx_loop_hook(mlx, render_next_frame, YourStruct);
//     mlx_loop(mlx);
// }

// void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     char    *dst;

//     dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//     // 괄호 == offset
//     *(unsigned int *)dst = color;
// }

// int close(int keycode, t_vars *vars)
// {
//     mlx_destroy_window(vars->mlx, vars->win);
// }
