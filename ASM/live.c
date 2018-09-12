#include "asm.h"



ssize_t	ft_atoi_long(const char *str)
{
    int			i;
    ssize_t		n;
    ssize_t	    nb;

    i = 0;
    n = 1;
    nb = 0;
    while ((str[i] < 14 && str[i] >= 9) || str[i] == ' ')
        i++;
    if (str[i] == '-' && str[i + 1] <= '9' && str[i + 1] >= '0')
    {
        n = -1;
        i++;
    }
    if (str[i] == '+' && str[i + 1] <= '9' && str[i + 1] >= '0')
        i++;
    while (str[i] <= '9' && str[i] >= '0')
    {
        if (nb * 10 + str[i] - '0' < nb)
            return (n == 1 ? -1 : 0);
        nb = nb * 10 + str[i] - '0';
        i++;
    }
    return (nb * n);
}


