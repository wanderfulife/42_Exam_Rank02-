#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	find_dup(char *s, int idx)
{
	int iter = 0;

	while (iter < idx)
	{
		if (s[iter] == s[idx])
			return (1);
		iter++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	size_t i = 0;
	size_t j;
	
	if (ac == 3)
	{
		while(av[1][i])
		{
			if (!find_dup(av[1], i))
			{
				j = 0;
				while(av[2][j])
				{
					if (av[1][i] == av[2][j])
					{
						ft_putchar(av[1][i]);
						break ;
					}
					j++;
				}
			}
			i++;
		}
	}
}