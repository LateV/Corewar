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



int check_for_digit(char *str)
{
    int k = 0;
    while(str[k])
    {
        if(!ft_isdigit(str[k]))
        {
            return 1;
        }
        k++;
    }
    return 0;
}

void ft_fill_arg_param(char *str,int k, t_command **node)
{
    char *s;
    int len;

    int  i = 0;
    //ft_printf("str %s\n",str);
    len = ft_strlen(str);
    if(str[i] == 'r' && str[i+1] && ft_isdigit(str[i + 1]))
    {
        (*node)->type_arg[k] = 1;
        s = ft_strsub(str,i+1,len);
        if(check_for_digit(s))
            ft_printf("error1");
        (*node)->num_arg[k] = ft_atoi(s);
        free(s);
        return;
    }
    if(str[i] == '%')
    {
        if((str[i] == '%' &&  str[i+1] && ft_isdigit(str[i + 1])))
        {
            (*node)->type_arg[k] = 2;
            s = ft_strsub(str,i+1,len);
            if(check_for_digit(s))
                ft_printf("error2\n");
            (*node)->num_arg[k] = ft_atoi_long(s);
            free(s);
            return;
        }
        else if(str[i] == '%' &&  str[i+1] && str[i+1] == ':' && str[i+2] && str[i+2] != ' ' && str[i+2] != '\t' )
        {
            (*node)->type_arg[k] = 2;
            (*node)->num_arg[k] = 0;
        }
        else
        {
            ft_printf("error3\n");
        }
        return;
    }
    if(ft_isdigit(str[i]))
    {
        if(check_for_digit(str))
            ft_printf("error2\n");
        (*node)->type_arg[k] = 3;
        (*node)->num_arg[k] = ft_atoi_long(str);

        return;
    }
    ft_printf("error4\n");

}
void ft_find_arg_type(char *str, t_command **node)
{
    char *line;
    char **arr;
    size_t k;
    size_t len;

    k = 0;

    len = ft_strlen((*node)->command_name);
    int l;

    l = ft_strlen(str);
    if(str[l - 1] && str[l - 1] == ',')
    {
        ft_printf("no arg for command1\n");
    }
    if(ft_strlen(str) == 0)
    {
        free(str);
        return ;
    }
    line = ft_strsub(str, (int)len ,ft_strlen(str) - len);
    free(str);
    if(ft_strequ(line,""))
    {
        ft_printf("no arg for command2\n");
        exit(0);
    }
    arr = ft_strsplit(line,',');
    if(ft_arr_len(arr) > 3)
    {
        ft_printf("to much arg\n");
        exit(0);
    }
//    while(arr[k])
//    {
//        ft_printf("str '%s'\n", arr[k]);
//        k++;
//    }
    k = 0;
    while(k < ft_arr_len(arr))
    {
        arr[k] = ft_strtrim(arr[k]);
        ft_fill_arg_param(arr[k],k,node);
        k++;
    }
    ft_clear(arr);
    free(line);
}

void ft_check_command(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i])
        i++;
    }
}

void ft_find_command(char *str, t_command **node)
{
    int i;
    int flag;


    i = 0;
    flag = 0;
    char *s;
    s = ft_strtrim(str);
    free(str);


    while(i < 17)
    {
        if(ft_strnstr(s,g_def[i].name,ft_strlen(g_def[i].name)))
        {
            flag = 1;
            (*node)->command_name = g_def[i].name;
            (*node)->size = 1;
            (*node)->label_size = g_def[i].label_size;
            (*node)->is_codage_octal = g_def[i].codage_octal;
            (*node)->opcode = g_def[i].opcode;
            break;
        }
        i++;
    }
    if(flag == 0 && !ft_strequ(s,""))
    {
        ft_printf("'%s'\n",s);
        ft_printf("not correct command\n");
        exit(1);
    }
    ft_find_arg_type(s, node);
    ft_count_opcode(*node);
}