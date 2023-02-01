#include <mlx.h>

typedef struct s_data{
    void    *img;
    void    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;

int main()
{
    void    *mlx;
    t_data    img;
    void    *mlx_win;

    mlx = mlx_init();
    img.img = mlx_new_image(mlx, 1080, 720);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
     /*
    ** After creating an image, we can call `mlx_get_data_addr`, we pass
    ** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
    ** then be set accordingly for the *current* data address.
    ** image를 만들었다면, 우리는 `mlx_get_data_addr`을 불러올 수 있다.
    ** `bits_per_pixel`, `line_length`, `endian`의 주소를 보낸다. 
    ** 그러고 나서 보내진 주소는 *현재 데이터 주소*를 위해 적절히 set 될 것이다. 
    */
    mlx_win = mlx_new_window(mlx, 1080, 720, "new_window");
    mlx_loop(mlx);
}