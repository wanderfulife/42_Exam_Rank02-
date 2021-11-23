#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h> 
#include <stdio.h>

typedef struct {
	va_list	arg;
	int		counter;
}	t_hold;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

static t_hold	*init()
{
	t_hold *args;

	args = (t_hold *)malloc(sizeof(t_hold));
	if (!args)
		return (NULL);
	args->counter = 0;
	return (args);
}

int	get_hex(int n)
{
	int	i = 1;

	while (n >= 16)
	{
			n /= 16;
			i++;	
	}
	return (i);
}

int	get_len(int n)
{
	int	i = 0;

	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_hex(int n)
{
	char *str;
	int len;

	len = get_hex(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (len >= 0)
	{
		if (n % 16 < 10)
			str[len--] = n % 16 + '0';
		else 
			str[len--] = 'a' - 10 + (n % 16);
		n /= 16;
	}
	return (str);
}
char *ft_itoa(int n)
{
	char	*str;
	int		len;

	len = get_len(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len--] = '\0';

	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	else if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}

	return (str);
}

void	print_hex(t_hold *args)
{
	char *str;

	str = ft_hex(va_arg(args->arg, int));
	args->counter += ft_strlen(str);
	ft_putstr(str);
}

void	print_int(t_hold *args)
{
	char *str;

	str = ft_itoa(va_arg(args->arg, int));
	args->counter += ft_strlen(str);
	ft_putstr(str);
}

void	print_str(t_hold *args)
{
	char *str;

	str = va_arg(args->arg, char *);
	args->counter += ft_strlen(str);
	ft_putstr(str);
}

void	getflag(char c, t_hold *args)
{
	if (c == 's')
		print_str(args);
	else if (c == 'd')
		print_int(args);
	else if (c == 'x')
		print_hex(args);
	else if (c == '%')
	{
		ft_putchar('%');
		args->counter++;
	}
}

int	ft_printf(char *str, ...)
{
	t_hold	*args;
	int		count = 0;
	int		i = 0;

	args = init();
	va_start(args->arg, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			args->counter++;
		}
		else if (str[i] == '%')
		{
			getflag(str[++i], args);
		}
			i++;
	}
	count += args->counter;
	va_end(args->arg);
	free(args);
	return (count);
}

int	main(void)
{
	int hex  = 45678;
	int count = ft_printf("un nobre hexadecimal est %x",hex);

	ft_printf("%d",count);

	
}

