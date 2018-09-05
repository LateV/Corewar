#include "libft/libft.h"
#include <fcntl.h>
#include "asm.h"

//int ft_check_arg(t_header **header)
//{
//    t_command *tmp;
//
//    tmp = (*header)->com_list;
//    while(tmp)
//    {
//        tmp = tmp->next;
//    }
//}


void init_struct(t_header **header)
{
    *header = malloc(sizeof(t_header));
    (*header)->prog_name = NULL;
    (*header)->name__len = 0;
    (*header)->prog_size = 0;
    (*header)->comment = NULL;
    (*header)->comment_len = 0;
    (*header)->com_list = NULL;
    (*header)->curr_label = NULL;
}

int ft_find_pointer(char *s, t_command **node)
{
    int i;
    int k;
    int num;
    char *str;

    i = 0;
    num = 0;
    str = ft_strtrim(s);
    while(str[i])
    {
        if(str[i] == ',')
            num++;
        if (str[i] == ':' && str[i - 1] && str[i - 1] == '%')
        {
            k = i++;
            while(str[k] && str[k] != ' ' && str[k] != ',')
                k++;
            (*node)->pointer_arg[num] = ft_strsub(str,i,k-i);
        }
        i++;
    }
    free(str);
    return 1;
}

int ft_find_comment(const char *str)
{
    int i;

    i = 0;
    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    if(str[i] == '#')
        return (1);
    return (0);

}


int read_file(const char *str, t_header **header)
{
    t_command *new;
    char *s;
    int fd;
    char *line;
    int num;

    num = 0;
//   fd = open("../champs/ex.s", O_RDONLY);
    if((fd = open(str, O_RDONLY)) < 0)
        error_exit(str);
    while (get_next_line(fd, &line) > 0)
    {
        num++;
        if(ft_find_comment(line))
        {
            free(line);
            continue;
        }
        if(ft_strstr(line,NAME_CMD_STRING))
        {
            if((ft_check_name(line,header)) > 0)
            {
                //ft_free()
                error_cases(ft_check_name(line,header));
            }
        }
        else if(ft_strstr(line,COMMENT_CMD_STRING))
        {
            if((ft_check_comment(line,header)) > 0)
            {
                //ft_free()
                error_cases(ft_check_comment(line,header));
            }
        }
        else
        {
            new = new_node();
            new->num = num;
            s = ft_find_label(line, &new,header);
            ft_find_pointer(line, &new);
            ft_find_command(s, &new);
            push_back(header,new);
        }
       free(line);
    }
    ft_printf("!");
    ft_count_pointer(*header);
    ft_printf("!");
    ft_check_params(*header);
//    new = (*header)->com_list;
//    ft_printf("name %s, comment %s \n",(*header)->prog_name, (*header)->comment);
//    while(new != NULL)
//    {
//        (*header)->prog_size += new->size;
//        int k = 0;
//        ft_printf("label %s command %s\n",new->label, new->command_name);
//        ft_printf("codage_octal %d\n",new->codage_octal);
//        ft_printf("opcode %d\n", new->is_codage_octal);
//        ft_printf("size %d\n",new->size);
//        while(new->pointer_arg[k])
//        {
//            ft_printf("pointer %s\n",new->pointer_arg[k]);
//            k++;
//        }
//        k = 0;
//        while(k < 3)
//        {
//            ft_printf("arg_type %d-> num %ld\n",new->type_arg[k],new->num_arg[k]);
//            k++;
//        }
//        k = 0;
//        while(k < 3)
//        {
//            ft_printf("byte_num %d\n",new->byte_sum[k]);
//            k++;
//        }
//        new = new->next;
//    }
    ft_write_to_file(*header);
    return (1);
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
    while(g_def[i].first_arg[k])
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



int ft_check_params(t_header *header)
{
    t_command *tmp;
    tmp = header->com_list;
    int i = 0;

    while(tmp)
    {
        i = 0;
        if(tmp->opcode > 0)
        {
            if (!ft_check_arg_for_command(tmp->command_name, tmp->type_arg)) {

                ft_printf("str %s, error1\n",tmp->command_name);
            }
            while (i < 3)
            {
                if (tmp->pointer_arg[i] != NULL)
                    if (!ft_find_label_to_pointer(header->com_list, tmp->pointer_arg[i]))
                        ft_printf("no label for pointer\n");
                //ft_printf("str %s\n",tmp->pointer_arg[i]);
                i++;
            }
        }
        tmp = tmp->next;
    }
    return 1;
}