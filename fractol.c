/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:17 by anezka            #+#    #+#             */
/*   Updated: 2025/03/26 19:01:59 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_mandelbrot(char *argv)
{
	if (ft_strncmp(argv, "Mandelbrot", 11) == 0)
		return (0);
	return (1);
}

int	check_julia(char *argv)
{
	if (ft_strncmp(argv, "Julia", 6) != 0)
		error_input();
	return (0);
}

int	getting_val(char *argv1, char *argv2)
{
	double	real;
	double	im;

	real = ft_atofcont(argv1);
	im = ft_atofcont(argv2);
	kickoff_julia(real, im);
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 2 && argc != 4)
		error_input();
	else
	{
		if (check_mandelbrot(argv[1]) == 0 && argc == 2)
			kickoff_mandelbrot();
		else if (check_julia(argv[1]) == 0 && argc == 4)
			getting_val(argv[2], argv[3]);
		else
			error_input();
	}
	return (0);
}
