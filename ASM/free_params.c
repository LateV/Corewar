#include "asm.h"

void		ft_clear(char **arr)
{
    size_t	count;

    count = 0;
    while (arr[count])
    {
        free(arr[count]);
        arr[count] = NULL;
        count++;
    }
    free(arr);
    arr = NULL;
}


int find_special_char(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == ' ' || s[i] == '%' || s[i] == ':' || s[i] == '\t')
            return i;
        i++;
    }
    return 0;
}

int find_cmd(t_command **node)
{
    int i;
    int c;
    char *str;

    i = 0;

    c = find_special_char((*node)->line);
    str = ft_strsub((*node)->line,0,c);
    while(i < 17)
    {
        if(ft_strequ(str,g_def[i].name))
        {
            (*node)->command_name = g_def[i].name;
            (*node)->size = 1;
            (*node)->label_size = g_def[i].label_size;
            (*node)->is_codage_octal = g_def[i].codage_octal;
            (*node)->opcode = g_def[i].opcode;
            free(str);
            return 1;
        }
        i++;
    }
    free(str);
    return -1;
}




int ft_find_command(t_command **node)
{
    char *string;
    int pos;
    int len;

    len = (int)ft_strlen((*node)->line);
    pos = find_special_char((*node)->line);
    if(find_cmd(node) == -1)
        return -1;
    else
    {
        string = ft_strsub((*node)->line,pos,len-pos);
        free((*node)->line);
        (*node)->line = ft_strtrim(string);
        free(string);
    }
    return 1;
}




void find_curr_label(t_header **header, t_command *node)
{
    int i;
    char *str;
    char *s;

    if((i = ft_find_char_num(node->line,':')) > 0)
    {
        str = ft_strdup(node->line);
        free(node->line);
        node->label = ft_strsub(str,0,i);
        s = ft_strsub(str,i+1,ft_strlen(str)-i);
        node->line = ft_strtrim(s);
        (*header)->curr_label = ft_strsub(str,0,i);
        free(str);
        free(s);
    }

}


int ft_find_t_int(char *str, int k, t_command *node, int type)
{
    int i = 0;

    if(check_for_digit(str) != -1 || (str[i] == '-' && check_for_digit(str+1)!= -1))
    {
        node->num_arg[k] = ft_atoi_long(str);
        node->type_arg[k] = type;
        return 1;
    }
    else if(str[i] && str[i] == ':')
    {
        if(label_char(str+1) == -1)
            return -1;
        node->pointer_arg[k] = ft_strdup(str+1);
        node->type_arg[k] = type;
        return 1;
    }
    return -1;
}


int ft_find_t_tir(char *str, int k, t_command *node, int type)
{
    int i = 0;

    if(ft_isdigit(str[i]) || str[i] == '-')
    {
        node->num_arg[k] = ft_atoi_long(str);
        node->type_arg[k] = type;
        if(str[i] == '-')
            str++;
        if(check_for_digit(str) == -1)
            return -1;
        return 1;
    }
    else if(str[i] && str[i] == ':')
    {
        if(label_char(str+1) == -1)
            return -1;
        node->pointer_arg[k] = ft_strdup(str+1);
        node->type_arg[k] = type;
        return 1;
    }
    return -1;
}



int ft_fill_arg_param(char *str, t_command *tmp, int k)
{
    int i;
    i = 0;
    if(str[i] == 'r')
    {
        if(check_for_digit(str+1) == -1)
            return -1;
        tmp->type_arg[k] = 1;
        tmp->num_arg[k] = ft_atoi_long(str+1);
        return 1;
    }
    if(str[i] == '%')
    {
        if (ft_find_t_tir(str + 1, k, tmp, 2) == -1)
            return -1;
        return 1;
    }
    if(check_for_digit(str) != -1 || (str[i] == ':') || (str[i] == '-' && check_for_digit(str+1) != -1))
    {
        if(ft_find_t_int(str,k,tmp,3) == -1)
            return -1;
        return 1;
    }
    return -1;
}




void check_coma(t_command **node, t_header **header)
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

void find_arg(t_command **node, t_header **header)
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
        if(ft_fill_arg_param(str, *node, i) < 0)
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

void skip_com(t_command *node)
{
    char *str;
    char *s;
    int i;

    str = node->line;
    if((i = ft_find_char_num(str,'#')) > 0)
    {
        s = ft_strsub(str,0,i);
        free(node->line);
        node->line = ft_strdup(s);
        free(s);
    }
}


void ft_free(t_header **header)
{
    t_command *tmp;

    tmp = (*header)->com_list;
    if((*header)->comment)
        free((*header)->comment);
    if((*header)->bot_name)
        free((*header)->bot_name);
    while(tmp)
    {
        if(tmp->line)
            free(tmp->line);
        free(tmp);
        tmp = tmp->next;
    }
    free(*header);
}







void error_exit( const char *str)
{
    ft_printf("Can't read source file %s\n",str);
    exit(0);
}

int check_extension(const char **str, int y)
{
    size_t len;

    if(ft_strequ(str[y], "-a"))
        y--;
    len = ft_strlen(str[y]);
    if(str[y][len-1] == 's' && str[y][len-2] == '.')
        return (y);
    return (-1);
}







