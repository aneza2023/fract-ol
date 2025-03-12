/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:59 by anezka            #+#    #+#             */
/*   Updated: 2025/03/11 10:36:31 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "fractol.h"
#include <stdlib.h>
#include <string.h>

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
 //   int         y;    

 //delete later

    im = 0;
    x = 0;
    real = x;
    im = real;
    real=im;
    julia = mlx_init(1000, 1000, "julia", true);
    if (julia == NULL)
    {
        write(1, "error\n", 7);
        return (1);
    }
    mlx_loop_hook(julia, ft_hook, julia);
    julia_set = mlx_new_image(julia, 500, 500);
    if (julia_set == NULL){
        write(1, "error\n", 7);
        return (1);
    }
    mlx_image_to_window(julia, julia_set, 10, 10);
    mlx_image_to_window(julia, julia_set, 500, 500);

    while (x < 100){
        mlx_put_pixel(julia_set, 0 + x, 0 + x, 0xFF0000FF); 
        x++;
    }


    mlx_loop(julia);
    mlx_terminate(julia);
    return (0);
}

//or could use mlx_close_window with if condition?? */