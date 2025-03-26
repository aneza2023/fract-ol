/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_prg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:30:29 by anezka            #+#    #+#             */
/*   Updated: 2025/03/26 17:53:47 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int error_input(void)
{
    write(1, "Parameter invalid\n", 18);
    write(1, "Choose from valid parameters:\n", 30);
    write(1, "'Julia <value> <value>' or 'Mandelbrot'\n", 41);
    exit(1);
}

int allocation_failed(void *mandel)
{
    t_fractal *fractol;

    fractol = mandel;
    write(1, "Allocation failed\n", 18);
    if (fractol->img != NULL)
        mlx_delete_image(fractol->mlx, fractol->img);
    if (fractol->mlx != NULL)
        mlx_terminate(fractol->mlx);
    if (fractol->c != NULL)
        free(fractol->c);
    if (fractol->z != NULL)
        free(fractol->z);
    if (fractol != NULL)
        free(fractol);
    exit(1);
}

void correct_ending(void *mandel)
{
    t_fractal *fractol;

    fractol = mandel;
    mlx_delete_image(fractol->mlx, fractol->img);
    mlx_terminate(fractol->mlx);
    if (fractol->z != NULL)
        free (fractol->z);
    if (fractol->c != NULL)
        free(fractol->c);
    free(fractol); 
    exit (0);
}
