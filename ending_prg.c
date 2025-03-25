/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_prg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:30:29 by anezka            #+#    #+#             */
/*   Updated: 2025/03/25 11:12:07 by anezka           ###   ########.fr       */
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

int allocation_failed(void *fractolpt)
{
    write(1, "Allocation failed\n", 18);
    free(fractolpt);
    exit(1);
}

int correct_ending(t_fractal *fractol)
{
    if (fractol->img != NULL)
        free(fractol->img);
    if (fractol->mlx != NULL)
        free(fractol->mlx);
    if (fractol->z != NULL)
        free (fractol->z);
    if (fractol->c != NULL)
        free(fractol->c);
    free(fractol); 
    exit (0);
}

// void closing(void *param)
// {
//     t_fractal   *fractol;

//     fractol = param;
//     correct_ending(fractol);
// }