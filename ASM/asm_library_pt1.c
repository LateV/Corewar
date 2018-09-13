#include "asm.h"

int ft_isspace(char c)
{
    if(c == ' ' || c == '\t')
        return 1;
    return 0;
}

int char_pos(char *str, char c)
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


int is_label_char(char *str)
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

