/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:17 by anezka            #+#    #+#             */
/*   Updated: 2025/03/24 15:07:40 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int check_mandelbrot(char *argv)
{
    if(ft_strncmp(argv, "Mandelbrot", 10) == 0)
        return (0);
    return (1);
}

int check_julia(char *argv)
{
    if (ft_strncmp(argv, "Julia", 5) != 0)
        error_input();
    return (0);
}

int getting_val(char *argv1, char *argv2)
{
    double   real;
    double   im;

    real =  ft_atofcont(argv1);
    im = ft_atofcont(argv2);
    kickoff_julia(real, im);
    return (0); 
} 

int main(int argc, char *argv[])
{
    if (argc != 2 && argc != 4)
        error_input();
    else
    {
        if (check_mandelbrot(argv[1]) == 0)
            kickoff_mandelbrot();
        else if (check_julia(argv[1]) == 0 && argc == 4)
            getting_val(argv[2], argv[3]);
        else
            error_input();
    }
    return (0);
}
