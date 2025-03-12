/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:50 by anezka            #+#    #+#             */
/*   Updated: 2025/03/11 10:27:34 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

/* int	ma(void)
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
} */
/* 
void ft_hook(void *params)
{
    mlx_t   *julia = params;
    if (mlx_is_key_down(julia, MLX_KEY_ESCAPE))
		mlx_close_window(julia);
}

int kickoff_julia(double real, double im)
{
    mlx_t       *julia;
    mlx_image_t *julia_set; 
    int         x;
    int         y;    

    julia = mlx_init(1000, 1000, "julia", true);
    if (julia == NULL)
    {
        write(1, "error\n", 7);
        return (1);
    }
    mlx_loop_hook(julia, ft_hook, julia);
    julia_set = mlx_new_image(julia, 250, 250);
    mlx_image_to_window(julia, julia_set, 0, 0);
    mlx_put_pixel(julia_set, 0, 0, 0xFF0000FF);

    mlx_loop(julia);
    mlx_terminate(julia);
    return (0);
} */