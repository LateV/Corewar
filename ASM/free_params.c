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



int ft_find_command(t_command **node)
{
    int i;
    int flag;
    char *str;
    char *string;
    char *s;
    int k;
    s = (*node)->line;
    i = 0;
    flag = 0;

    while(s[i])
    {
        if(s[i] == ' ' || s[i] == '%' || s[i] == ':' || s[i] == '\t')
            break;
        i++;
    }
    str = ft_strsub(s,0,i);
    k = i;
    i = 0;
    while(i < 17)
    {
        if(ft_strequ(str,g_def[i].name))
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
    free(str);
    if(flag == 0)
        return -1;
    else
    {
        string = ft_strsub(s,k,ft_strlen(s)-k);
        free((*node)->line);
        (*node)->line = ft_strtrim(string);
        free(string);
    }
    return 1;
}

int validte_label_2(t_command *node)
{
    int i;
    char *str;

    i = 0;
    str = node->line;
    while(str[i])
    {
        if(str[i] == ':')
        {

            if(str[i-1] && (ft_isspace(str[i-1]) || str[i-1] == '%' || str[i-1] == ','))
            {
                if (ft_find_command(&node) == -1)
                    return (-1);
                return 0;
            }
            else
            {
                while(--i > 0)
                    if(!ft_strchr(LABEL_CHARS,str[i]))
                        return (-1);
                return 1;
            }
        }
        i++;
    }
    return  1;
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


//int ft_find_t_tir(char *str, int k, t_command *node, int type)
//{
//    int i = 0;
//
//    if((str[i+1] && ft_isdigit(str[i + 1])) || (ft_isdigit(str[i]) && !str[i+1]))
//    {
//        if(check_for_digit(str+1) == -1)
//        {
//            if (label_char(str + 1) == -1)
//                return -1;
//            node->pointer_arg[k] = ft_strdup(str);
//        }
//        else
//            node->num_arg[k] = ft_atoi_long(str);
//    }
//    else if(str[i] && str[i] == ':')
//    {
//        if(label_char(str+1) == -1)
//            return -1;
//        node->pointer_arg[k] = ft_strdup(str+1);
//    }
//    node->type_arg[k] = type;
//    return 0;
//}


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
//        if(str[i+1] == ':')
//        {
//            if(ft_find_t_tir(str+1,k,tmp,2) == -1)
//                return -1;
//            return 1;
//        }
//        if(ft_isdigit(str[i + 1]) || str[i+1] == '-')
//        {
//            if(ft_find_t_tir(str,k,tmp,2) == -1)
//                return -1;
//            tmp->num_arg[k] = ft_atoi_long(str+1);
//            return 1;
//        }

    if(check_for_digit(str) != -1 || (str[i] == ':') || (str[i] == '-' && check_for_digit(str+1) != -1))
    {
        if(ft_find_t_int(str,k,tmp,3) == -1)
            return -1;
        return 1;
    }
    return -1;
}



void find_arg(t_command **node, t_header **header)
{
    char **arr;
    char *str = NULL;

    int i = 0;
    int j = 0;

    char *s;
    s = (*node)->line;

    while(s[i])
    {
        if(s[i] == ',')
            j++;
        i++;
    }
    if(j > 2)
        error_cases(6,header);
    i = 0;
    arr = ft_strsplit(s,',');
    while(arr[i])
    {
        if(str)
            free(str);
        str = ft_strtrim(arr[i]);
        //ft_printf("'%s'\n",str);
        if(ft_fill_arg_param(str, *node, i) < 0)
        {
            ft_printf("%s\n", str);
//            ft_clear(arr);
//            free(str);
            error_cases(1,header);
        }
        i++;
    }
//    ft_clear(arr);
//    free(str);
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


int ft_find_label_to_pointer(t_command *list,char *pointer)
{
    t_command *tmp;

    tmp = list;
    while(tmp)
    {
        if(ft_strequ(tmp->label,pointer))
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

int ft_check_arg_for_command(char *name, int *arg)
{
    int i;

    i = 0;
    while(i < 17)
    {
        if(ft_strequ(name,g_def[i].name))
            break;
        i++;
    }
    int k = 0;
    while(k < 3)
    {
        if(arg[0] == g_def[i].first_arg[k])
        {
            k = 0;
            while(k < 3)
            {
                if(arg[1] == g_def[i].second_arg[k])
                {
                    k = 0;
                    while(k < 2)
                    {
                        if(arg[2] == g_def[i].third_arg[k])
                        {
                            return 1;
                        }
                        k++;
                    }
                }
                k++;
            }
        }
        k++;
    }
    return 0;
}



void ft_check_params(t_header *header)
{
    t_command *tmp;
    tmp = header->com_list;
    int i = 0;

    if(ft_strlen(header->file_name) > 128)
    {
        error_cases(7,&header);
    }
    if(header->comment_len > 2048)
        error_cases(8,&header);
    while(tmp)
    {
        i = 0;
        if(tmp->opcode > 0)
        {
            if (!ft_check_arg_for_command(tmp->command_name, tmp->type_arg)) {
                error_cases(9,&header);
            }
            while (i < 3)
            {
                if (tmp->pointer_arg[i] != NULL)
                    if (!ft_find_label_to_pointer(header->com_list, tmp->pointer_arg[i]))
                        error_cases(10,&header);
                i++;
            }
        }
        tmp = tmp->next;
    }
}




void error_exit( const char *str)
{
    ft_printf("Can't read source file %s\n",str);
    exit(0);
}

int ft_check_extension(const char **str, int y)
{
    size_t len;

    if(ft_strequ(str[y], "-a"))
        y--;
    len = ft_strlen(str[y]);
    if(str[y][len-1] == 's' && str[y][len-2] == '.')
        return (y);
    return (-1);
}







