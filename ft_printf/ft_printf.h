#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	sp(int x, char i, int mod);
int	calc(char s, long unsigned i, void *o);
int	prb(int p[], unsigned int u, void *s, int x);
int	bp(const char *s, int y, int p[], va_list args);
int	ft_bonu(const char *s, int y, va_list args);

int	ft_hex(long unsigned x, int fd, int cap);
int	po(void *s, int fd, int x);
int	cr(int i, int m);
int	ft_nbr(unsigned int i, int s, int pr);
int	ft_printf(const char *str, ...);

#endif
