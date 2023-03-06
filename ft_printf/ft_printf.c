#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	ft_hex(long unsigned x, int fd, int cap)
{
	int	z;
	int	f;

	f = 0;
	if (fd != 1 && x == 0)
		return (0);
	if (x > 15)
		f = ft_hex(x / 16, fd, cap);
	z = x % 16;
	z = z + 48 + (z >= 10) * (7 + (cap > 100) * 32);
	write(1, &z, (++f > 0));
	return (f);
}

int	cr(int i, int m)
{
	if (m == 4)
		return (ft_strchr("xXcu", i) == 0);
	if (m == 1)
		return (ft_strchr("cp", i) == 0);
	if (m == 115)
		return (0);
	if (m == 9)
		return (i == -1 || i == 0);
	if (m == 8)
		return (ft_strchr("duixX", i) != 0);
	if (m == 99 || m == 0)
		return (write(1, &i, 1));
	if (m == -1)
	{
		ft_putchar_fd('%', 1);
		if (i != '%')
			write(1, &i, 1);
		return (2);
	}
	return (0);
}

int	po(void *s, int fd, int x)
{
	int		n;
	char	*px;

	if (x == 's')
	{
		px = (char *)s;
		if (px == 0)
			px = "(null)";
		n = -1;
		while (px[++n] != 0 && (n < fd || -1 > fd))
			cr(px[n], 0);
		return (n);
	}
	else if (x == 'c')
		return (write(1, &fd, 1));
	else if (x == 'p')
	{
		if (fd != -1)
			ft_putstr_fd("0x", 1);
		return ((fd != -1) * 2 + ft_hex((long unsigned)s, (fd == -2), 'x'));
	}
	return (0);
}

int	ft_nbr(unsigned int i, int s, int pr)
{
	char	c;
	int		f;

	f = 0;
	if (i == 0 && s != 'c' && pr != 99)
		return (0);
	if (s == 'x' || s == 'X')
		return (ft_hex(i, 1, s));
	if (s == 'c')
		return (cr(i, 0));
	if (s != 'u' && (int)i < 0)
	{
		if (pr == 99)
			ft_putchar_fd('-', 1);
		i = -1 * i;
		s = 0;
	}
	if (i >= 10)
		f = ft_nbr(i / 10, 2, pr);
	c = (i % 10) + 48;
	write(1, &c, ((++f != 0) && (pr != 0)));
	return (f + (++s == 1));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		l;
	int		x;
	char	*e;

	va_start(args, str);
	x = -1;
	l = 0;
	e = "+-# .1234567890*";
	while (++x > -3 && str[x] != 0)
		if (l >= 0 && str[x] == 37 && ft_strchr(e, str[x + 1]) != 0)
			l = (-1 * (l + ft_bonu(str, x, args))) - (str[0] == '%');
	else if (str[x] == '%' && ft_strchr("csidupxX%", str[x + 1]) && l >= 0)
		if (str[++x] == 'p' || str[x] == 's')
			l += po(va_arg(args, void *), -2, str[x]);
	else if (str[x] == '%')
		l += cr('%', 0);
	else
		l += ft_nbr(va_arg(args, unsigned int), str[x], 99);
	else if (l >= 0)
		l += write(1, str + x, 1);
	else if (l < 0 && ft_strchr(e, str[x]) == 0)
		l = -1 * (l + (str[0] == '%'));
	va_end(args);
	return (l);
}
