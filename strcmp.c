#include "fractol.h"
#include "MLX42.h"

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

/* int	main(void)
{
	char str[50] = "aaaajkfhnkan";
	char str2[50] = "aaan";
	size_t n = 10;

	ft_strncmp(str, str2, n);
	printf("%d",ft_strncmp(str, str2, n));
	return (0);
} */