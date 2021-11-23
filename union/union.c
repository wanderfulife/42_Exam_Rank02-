#include <unistd.h>

void ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

char	*ft_strcat(char *s1, char *s2)
{
	size_t i = 0;
	size_t j = 0;

	while (s1[i])
		i++;
	while (s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}

char	*checkdup(char *str)
{
	size_t	i = 0;
	size_t	j;
	int		dup = 0;

	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
			{
				str[j] = str[j + 1];
				dup++;
			}
			j++;
		}
		i++;
	}
	if (dup > 0)
		checkdup(str);
	str[i] = '\0';
	return (str);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_putstr(checkdup(ft_strcat(av[1],av[2])));
	}
	return (0);
}