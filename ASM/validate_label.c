#include "asm.h"

void validate_label(t_header **header)
{
    t_command *tmp;

    tmp = (*header)->com_list;
    while(tmp)
    {
        skip_com(tmp);
        if(validte_label_2(tmp) < 0)
            error_cases(5,header);
        else if(validte_label_2(tmp) == 1)
        {
            find_curr_label(header,tmp);
            ft_find_command(&tmp);
        }
        if(tmp->label == NULL && (*header)->curr_label)
            tmp->label = ft_strdup((*header)->curr_label);
        find_arg(&tmp, header);
        ft_count_opcode(tmp);
        tmp = tmp->next;
    }
}

int validte_label_2(t_command *node)
{
    int i;
    char *str;

    i = 0;
    str = node->line;
    while(str[i])
    {
        if(str[i] == LABEL_CHAR)
        {

            if(str[i-1] && (ft_isspace(str[i-1]) || str[i-1] == DIRECT_CHAR || str[i-1] == SEPARATOR_CHAR))
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
