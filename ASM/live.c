#include "libft/libft.h"
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



void ft_fill_arg_param(char *str, int i, int k, t_command **node)
{
    char *s;
    int len;

    len = ft_strlen(str) - i;

    //ft_printf("%s,%c",str,str[i]);
    if(str[i] == 'r')
    {
        (*node)->type_arg[k] = 1;
        s = ft_strsub(str,i+1,len);
        (*node)->num_arg[k] = ft_atoi(s);
        free(s);
    }
    else if(str[i] == '%')
    {
        (*node)->type_arg[k] = 2;
        s = ft_strsub(str,i+1,len);
        (*node)->num_arg[k] = ft_atoi_long(s);
        free(s);
    }
    else
    {
        (*node)->type_arg[k] = 3;
        (*node)->num_arg[k] = ft_atoi_long(str);
    }

}
void ft_find_arg_type(char *str, t_command **node)
{
    char *line;
    char **arr;
    size_t k;
    int l;
    size_t len;

    k = 0;
    len = ft_strlen((*node)->command_name);
    if(ft_strlen(str) == 0)
    {
        free(str);
        return ;
    }
    line = ft_strsub(str, (int)len ,ft_strlen(str) - len);
    free(str);
    arr = ft_strsplit(line,',');
    while(k < ft_arr_len(arr))
    {
        l = 0;
        while (arr[k][l] == ' ' || arr[k][l] == '\t')
            l++;
        ft_fill_arg_param(arr[k],l,k,node);
        k++;
    }
    ft_clear(arr);
    free(line);
}



void ft_find_command(char *str, t_command **node)
{
    int i;


    i = 0;
    char *s;
    s = ft_strtrim(str);
    free(str);

    while(i < 17)
    {
        if(ft_strnstr(s,g_def[i].name,ft_strlen(g_def[i].name)))
        {
            (*node)->command_name = g_def[i].name;
            (*node)->size = 1;
            (*node)->label_size = g_def[i].label_size;
            (*node)->opcode = g_def[i].codageoctal;
            break;
        }
        i++;
    }
    ft_find_arg_type(s, node);
    ft_count_opcode(*node);
}