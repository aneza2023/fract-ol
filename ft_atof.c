/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:39 by anezka            #+#    #+#             */
/*   Updated: 2025/03/26 19:02:11 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_input_nb(char *argv)
{
	int	countdot;
	int	alpha;
	int	i;

	i = 0;
	countdot = 0;
	alpha = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] == '.' || argv[i] == ',')
			countdot++;
		if (argv[i] < '0' || argv[i] > '9')
			alpha++;
		if ((argv[i] == '+' || argv[i] == '-') && i != 0)
			error_input();
		if ((argv[i] == '+' || argv[i] == '-') && i == 0)
			alpha--;
		i++;
	}
	if (countdot > 1)
		error_input();
	if (alpha > 1 || (alpha == 1 && countdot == 0))
		error_input();
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((nptr[i] == 32) || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	if (nptr[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

double	ft_atofcontforother(double result, char *argv)
{
	double	decimal;
	double	decim_places;
	int		i;

	i = 0;
	decimal = 0.0;
	decim_places = 10;
	while ((argv[i] != '.' && argv[i] != ','))
		i++;
	if (argv[i] == '.' || argv[i] == ',')
	{
		i++;
		while (argv[i] <= '9' && argv[i] >= '0')
		{
			decimal = (argv[i] - '0') / decim_places;
			result += decimal;
			i++;
			decim_places = decim_places * 10;
		}
	}
	return (result);
}

double	ft_atofcontforzero(double result, char *argv)
{
	int		i;
	double	sign;

	sign = 1;
	i = 0;
	while ((argv[i] != '.' && argv[i] != ','))
	{
		if (argv[i] == '-')
			sign = -1;
		i++;
	}
	result = ft_atofcontforother(result, argv);
	return (result * sign);
}

double	ft_atofcont(char *argv)
{
	double	result;

	result = ft_atoi(argv);
	check_input_nb(argv);
	another_chech(argv);
	if (result == 0)
	{
		result = ft_atofcontforzero(result, argv);
		return (result);
	}
	result = ft_atofcontforother(result, argv);
	return (result);
}
