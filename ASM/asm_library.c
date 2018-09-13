#include "asm.h"

int ft_isspace(char c)
{
    if(c == ' ' || c == '\t')
        return 1;
    return 0;
}

int ft_find_char_num(char *str, char c)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] == c)
            return i;
        i++;
    }
    return -1;
}

int check_for_digit(char *str)
{
    int k = 0;
    while(str[k])
    {
        if(!ft_isdigit(str[k]))
            return -1;
        k++;
    }
    return 1;
}


int label_char(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(!ft_strchr(LABEL_CHARS,str[i]))
            return -1;
        i++;
    }
    return 0;
}

size_t	ft_arr_len(char **arr)
{
    size_t	count;

    count = 0;
    while (arr[count])
        count++;
    return (count);
}

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


