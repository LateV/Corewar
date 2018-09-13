#include "asm.h"

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
    int k;

    i = -1;
    k = -1;
    while(++i < 17)
        if(ft_strequ(name,g_def[i].name))
            break;
    while(++k < 3)
        if(arg[0] == g_def[i].first_arg[k])
        {
            k = -1;
            while(++k < 3)
                if(arg[1] == g_def[i].second_arg[k])
                {
                    k = -1;
                    while(++k < 2)
                        if(arg[2] == g_def[i].third_arg[k])
                            return (1);
                }
        }
    return 0;
}

void ft_check_params(t_header *header)
{
    t_command *tmp;
    int i;

    tmp = header->com_list;
    if(ft_strlen(header->file_name) > 128)
        error_cases(7,&header);
    if(header->comment_len > 2048)
        error_cases(8,&header);
    while(tmp)
    {
        if(tmp->opcode > 0)
        {
            if (!ft_check_arg_for_command(tmp->command_name, tmp->type_arg))
                error_cases(9,&header);
            i = -1;
            while (++i < 3)
                if (tmp->pointer_arg[i] != NULL)
                    if (!ft_find_label_to_pointer(header->com_list, tmp->pointer_arg[i]))
                        error_cases(10,&header);
        }
        tmp = tmp->next;
    }
}


