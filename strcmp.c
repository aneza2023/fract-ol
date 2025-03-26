/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 21:50:11 by anezka            #+#    #+#             */
/*   Updated: 2025/03/26 18:53:22 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n <= 0)
		return (0);
	while ((s1[i] != '\0') && (s2[i] != '\0') && (i < n - 1))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

int another_chech(char *argv)
{
	int i;
	int plusminus;

	i = 0;
	plusminus = 0;
	if (argv[i] == '-' || argv[i] == '+')
		argv++;
	while (argv[i] != '\0')
	{
		if ((argv[i] == '+' || argv[i] == '-'))
			plusminus++;
		i++;
	}
	if (i == 0)
		error_input();
	if ((argv[i - 1] == '.' || argv[i - 1] == ',')
		|| (argv[0] == '.' || argv[0] == ','))
			error_input();
	if (argv[i - 1] == '+' || argv[i - 1] == '-')
		error_input();
	return (0);
}