#include "asm.h"

void ft_count_opcode(t_command *node)
{
    int a;
    int b;
    int c;
    int i;

    i = -1;
    while(++i < 3)
    {
        if (node->type_arg[i]  == T_REG)
            node->byte_sum[i] = 1;
        if (node->type_arg[i]  == T_DIR)
            node->byte_sum[i] = node->label_size;
        if (node->type_arg[i]  == T_IND)
            node->byte_sum[i] = 2;
        node->size += node->byte_sum[i];
    }
    if(node->is_codage_octal == 1)
    {
        a = node->type_arg[0] << 6;
        b = node->type_arg[1] << 4;
        c = node->type_arg[2] << 2;
        node->codage_octal = a | b | c;
        node->size += 1;
    }
    else
        node->codage_octal = -1;
}

t_command *find_list(t_command *copy, char *str)
{
    while(copy)
    {
        if (ft_strequ(copy->label,str))
            break;
        copy = copy->next;
    }
    return copy;
}



void count_forward(t_command *tmp, int i)
{
    t_command *copy;

    copy = tmp;
    while(copy)
    {
        if (ft_strequ(copy->label,tmp->pointer_arg[i]))
            break;
        else
            tmp->num_arg[i] +=  copy->size;
        copy = copy->next;
    }
}


void count_backward(t_command *copy,t_command *tmp, int i)
{

    while(copy)
    {
        if (copy->num == tmp->num)
            break;
        else
            tmp->num_arg[i] += copy->size;
        copy = copy->next;
    }
    tmp->num_arg[i] = 0xffff - tmp->num_arg[i] + 1;
}


void count_pointer(t_header *node)
{
    int i;
    t_command *tmp;
    t_command *copy;

    tmp = node->com_list;
    while(tmp)
    {
        i = -1;
        while(++i < 3)
            if(tmp->pointer_arg[i])
            {
                copy = find_list(node->com_list,tmp->pointer_arg[i]);
                if(copy && tmp->num < copy->num)
                    count_forward(tmp,i);
                else
                    count_backward(copy,tmp,i);
            }
        node->prog_size += tmp->size;
        tmp = tmp->next;
    }
}




