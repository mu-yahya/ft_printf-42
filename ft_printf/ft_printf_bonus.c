#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "ft_printf.h"

int	sp(int x, char i, int mod)
{
	int	y;

	y = -1;
	if (mod >= 1)
	{
		cr('0', 0);
		cr(120 - ((mod == 88) * 32), 0);
		return (2);
	}
	if ((mod == 0 || ++y < 0) && i != 0)
		while (++y < x)
			cr(i, 0);
	return (y * (y > 0));
}

int	calc(char s, long unsigned i, void *o)
{
	long unsigned	l;

	l = (s == 'c') * (i % 256);
	if (o != 0 && (s == 's'))
		l = ft_strlen((char *)o);
	if (ft_strchr("xXuzdi", s) != 0 && i == 0)
		return (0);
	if (s == 'X' || s == 'x' || s == 'u' || s == 'z')
	{
		if (i >= (10 + (s != 'u') * 6))
			l = calc(s, i / (10 + (s != 'u') * 6), 0);
		return (l + 1);
	}
	else if (s == 'd' || s == 'i')
		return (ft_nbr((int)i, s, 0));
	else if (s == 's' && o == 0)
		return ((6 > i && i > 0) * i + (6 <= i || (int)i == -2) * 6);
	else if (s == 's' && l >= 0)
		return ((l > i) * i + (l <= i) * l);
	else if (s == 'p')
		return (2 + (o != 0) * calc('z', (long unsigned)o, o));
	else if (s == 'c' || s == '%')
		return ((l == 0) || (l >= 32 && l <= 126) || s == '%');
	else
		return (2);
}

int	prb(int p[], unsigned int u, void *s, int x)
{
	int	z;
	int	b;
	int	l;

	l = ((((int)u < 0) * 45) + (p[0] * 43) + (p[2] * 32)) * cr(x, 4);
	u += (x == 's') * p[6];
	b = calc(x, u, s) - 1 * (l == '-') - 2 * (x == 'p' * !!s * !(cr(p[6], 9)));
	z = p[5] - b * (x == 'c' || x == 's');
	b = b * (x != 'c' && x != 's') + (u * (x == 'c' || x == 's'));
	if (x == 's' || x == 'c')
		return (sp(z * !p[1], 32, 0) + po(s, b, x) + sp(z * p[1], 32, 0));
	u = (1 - (2 * ((x == 'd' || x == 'i') && (int)u < 0))) * u;
	p[4] = p[4] * !p[1];
	p[6] = p[6] - b * (u || s) + 3 * (p[6] < -1 && !u && !s && !p[4]);
	p[5] += (-b * (u || s) - !!l - 2 * (p[3] || x == 'p') - p[6] * (p[6] > 0));
	z = sp((l > 0) * p[4] * (x == 'p'), l, -5 * !(l > 0));
	z += sp((l > 0) * p[4], l, ((p[3] * x) + (x == 'p')) * p[4]);
	z += sp(!p[1] * p[5], ' ' + (p[4] * 16), 0);
	z += sp((l > 0) * !p[4] * (x == 'p'), l, -5 * (l <= 0));
	z += sp((l > 0) * !p[4], l, ((p[3] * x) + (x == 'p')) * !p[4]);
	z += sp(p[6], '0', 0);
	x = x - ((x == 'd' || x == 'i') * (x - 'u'));
	if (x == 'p')
		return (z + po(s, -1, x) + sp(p[1] * p[5], ' ', 0));
	return (z + ft_nbr(u, x, b + 2) + sp(p[1] * p[5], ' ', 0));
}

int	bp(const char *s, int y, int p[], va_list args)
{
	unsigned int	q;
	void			*x;
	int				a;

	q = 0;
	x = 0;
	while (ft_strchr("1234567890+- #0.*", s[++y]))
		;
	if (s[y] == '%' || ft_strchr("dxXiucsp", s[y]) == 0)
		return (cr(s[y], -1));
	else if (ft_strchr("dxXiuc", s[y]) != 0)
		q = va_arg(args, unsigned int);
	else if (s[y] == 's' || s[y] == 'p')
		x = va_arg(args, void *);
	a = (s[y] != 'p' && s[y] != 'd' && s[y] != 'i');
	p[2] = p[2] * !((int) q < 0 || p[0] == 1 || a != 0);
	p[0] = p[0] * !((int) q < 0 || a != 0);
	p[3] = p[3] * !(q == 0) * (s[y] == 88 || s[y] == 'x');
	if (s[y] == 's' && x != 0)
		p[6] = (p[6] * (p[6] > 0) + ((p[6] == -2) * ft_strlen((char *)x)));
	p[4] = p[4] * (p[6] == -2);
	a = -1;
	while (++a < 5)
		p[a] = (p[a] == 1) * p[a];
	return (prb(p, q, x, s[y]));
}

int	ft_bonu(const char *s, int y, va_list args)
{
	int	pr[7];
	int	p;

	ft_memcpy (pr, (int []){'+', '-', ' ', '#', '0', 0, -2}, 7 * sizeof(int));
	p = -1;
	while (ft_strchr("+- #0", s[++y]))
		while ((++p % 6) != 5)
			if (s[y] == pr[p % 5])
				pr[p % 5] = 1;
	p = y - 1;
	if (s[y] >= 49 && s[y] <= 57)
		pr[5] = ft_atoi(s + y);
	else if (s[y] == '*' && ++y > 0)
		pr[5] = va_arg(args, int);
	if (s[y] != '.')
		while (++y > 0 && (ft_strchr("1234567890", s[y]) != 0))
			;
	if (s[y] == '.' && ++pr[6] > -3 && ft_strchr("1234567890", s[y + 1]) != 0)
		pr[6] = ft_atoi(s + y + 1);
	else if (s[y] == '.' && s[y + 1] == '*')
		pr[6] = va_arg(args, int);
	return (bp(s, p, pr, args));
}

// #include <stdio.h>
// #include <limits.h>

// int main()
// {
// 	printf(" <%012d> \n", LONG_MIN);
// 	ft_printf(" <%012d> \n", LONG_MIN);
// }