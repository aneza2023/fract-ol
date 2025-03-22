/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending_prg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:30:29 by anezka            #+#    #+#             */
/*   Updated: 2025/03/22 14:56:42 by ahavrank         ###   ########.fr       */
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

int correct_ending(void *fractol)
{
    free(fractol);
    exit (0);
}