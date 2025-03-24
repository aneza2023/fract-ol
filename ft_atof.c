/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezka <anezka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:49:39 by anezka            #+#    #+#             */
/*   Updated: 2025/03/24 15:05:59 by anezka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

double ft_atofcont(char *argv)
{
    int i;
    double   result;
    double   decimal;
    double   decim_places;
    
    i = 0;
    result = ft_atoi(argv);
    decimal = 0.0;
    decim_places = 10;
    printf("result> %f\n", result);
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
