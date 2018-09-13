#include "asm.h"

static void check_coma(t_command **node, t_header **header)
{
    int i;
    int j;
    char *s;

    i = 0;
    j = 0;
    s = (*node)->line;
    while(s[i])
    {
        if(s[i] == ',')
            j++;
        i++;
    }
    if(j > 2)
        error_cases(6,header);
}

static int check_t_int(char *str, int k, t_command *node, int type)
{
    int i = 0;

    if(check_for_digit(str) != -1 || (str[i] == '-' && check_for_digit(str+1)!= -1))
    {
        node->num_arg[k] = ft_atol(str);
        node->type_arg[k] = type;
        return 1;
    }
    else if(str[i] && str[i] == ':')
    {
        if(is_label_char(str + 1) == -1)
            return -1;
        node->pointer_arg[k] = ft_strdup(str+1);
        node->type_arg[k] = type;
        return 1;
    }
    return -1;
}


static int check_t_dir(char *str, int k, t_command *node, int type)
{
    int i = 0;

    if(ft_isdigit(str[i]) || str[i] == '-')
    {
        node->num_arg[k] = ft_atol(str);
        node->type_arg[k] = type;
        if(str[i] == '-')
            str++;
        if(check_for_digit(str) == -1)
            return -1;
        return 1;
    }
    else if(str[i] && str[i] == ':')
    {
        if(is_label_char(str + 1) == -1)
            return -1;
        node->pointer_arg[k] = ft_strdup(str+1);
        node->type_arg[k] = type;
        return 1;
    }
    return -1;
}



int find_arg_type(char *str, t_command *tmp, int k)
{
    int i;
    i = 0;
    if(str[i] == 'r')
    {
        if(check_for_digit(str+1) == -1)
            return -1;
        tmp->type_arg[k] = 1;
        tmp->num_arg[k] = ft_atol(str + 1);
        return 1;
    }
    if(str[i] == '%')
    {
        if (check_t_dir(str + 1, k, tmp, 2) == -1)
            return -1;
        return 1;
    }
    if(check_for_digit(str) != -1 || (str[i] == ':') || (str[i] == '-' && check_for_digit(str+1) != -1))
    {
        if(check_t_int(str, k, tmp, 3) == -1)
            return -1;
        return 1;
    }
    return -1;
}


void split_line_for_arg(t_command **node, t_header **header)
{
    char **arr;
    char *str = NULL;
    int i = 0;

    check_coma(node,header);
    arr = ft_strsplit((*node)->line,',');
    while(arr[i])
    {
        if(str)
            free(str);
        str = ft_strtrim(arr[i]);
        if(find_arg_type(str, *node, i) < 0)
        {
            ft_clear(arr);
            free(str);
            error_cases(1,header);
        }
        i++;
    }
    ft_clear(arr);
    free(str);
}

