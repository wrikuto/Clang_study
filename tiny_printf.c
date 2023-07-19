#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <assert.h>

static int	put_char(const char *str)
{
	int		i;
	int		temp;
	int		rtn;

	i = 0;
	temp = 0;
	rtn = 0;
	while(str[i] != '\0')
	{
		temp = write(1, &str[i], 1);
		if (temp == -1)
			return (-1);
		rtn += temp;
		i++;
	}
	return (rtn);
}

// ---

static	int	ft_numdigit(int n)
{
	int	num;
	int	i;

	i = 0;
	num = n;
	if (n < 0)
		i++;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static	int	ft_power(unsigned int base, unsigned int exp)
{
	unsigned int	i;
	unsigned int	result;

	result = 1;
	if (base == 0 && exp < 0)
		return (0);
	else
	{
		i = 0;
		while (i < exp)
		{
			result *= base;
			i++;
		}
	}
	return (result);
}

static ssize_t	ft_print_d(long int n)
{
	int			i;
	int			res;
	char		c;
	ssize_t		w_ret;

	w_ret = 0;
	res = ft_numdigit(n);
	i = res - (n < 0);
	if (n < 0)
	{
		w_ret = w_ret + write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
		return (write(1, "0", 1));
	while (i > 0)
	{
		c = (n / ft_power(10, i - 1)) + '0';
		w_ret = w_ret + write(1, &c, 1);
		n = n % ft_power(10, i - 1);
		i--;
	}
	if (w_ret == res)
		return (w_ret);
	return (-1);
}

// ---

int	tiny_printf(char *format, ...)
{
	int		i;
	int		rtn;
	int		temp;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	rtn = 0;
	temp = 0;
	while(format[i] != '\0')
	{
		if ((format[i] == '%') && (format[i + 1] == 's'))
		{
			temp = put_char(va_arg(ap, char*));
			i++;
		}
		else if ((format[i] == '%') && (format[i + 1] == 'd'))
		{
			temp = ft_print_d(va_arg(ap, int));
			i++;
		}
		else
			temp = write(1, &format[i], 1);
		if (temp == -1)
			return (-1);
		rtn += temp;
		i++;
	}
	rtn += write(1, "\n", 1);
	va_end(ap);
	return (rtn);
}

int main()
{
	tiny_printf("this is tiny printf.\nstring: %s, num: %d", "hello", 1223143);
	return (0);
}