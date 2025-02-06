
#include "fractol.h"
#include "MLX42.h"

int	ma(void)
{
    t_comp_nb   random;
    int         i;
    double      temp_x;

    random.x = 0.45;
    random.y = 2;

    i = 1;
    while (i < 30)
    {
        temp_x = (random.x * random.x) - (random.y * random.y);
        random.y = 2 * random.x * random.y;
        random.x = temp_x;
        printf("iteration number: %d, value x: %f, value y: %f\n", i, random.x, random.y);
        i++;
    }
    return (0);
}