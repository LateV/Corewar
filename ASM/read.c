#include "asm.h"

void ft_fill_list(int num, char *line, t_header **header)
{
    t_command *node;

    if (ft_strstr(line, NAME_CMD_STRING))
        (*header)->bot_name = ft_strtrim(line);

    else if (ft_strstr(line, COMMENT_CMD_STRING))
        (*header)->comment = ft_strtrim(line);
    else
    {
        node = create_new_node(num,ft_strtrim(line));
        push_back(header,node);
    }
}

void push_back(t_header **header, t_command *new_node)
{
    t_command *tmp;

    tmp = (*header)->com_list;
    if((*header)->com_list == NULL)
    {
        (*header)->com_list = new_node;
        return ;
    }
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = new_node;
}

int ft_skip_comment(char *str)
{
    int i;

    i = 0;
    if(ft_strlen(str) == 0)
    {
        free(str);
        return (1);
    }
    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    if(str[i] == '#' || str[i] == '\0')
    {
        free(str);
        return (1);
    }
    return (0);

}


void read_file(const char *str, t_header **header)
{
    int fd;
    char *line;
    int num;
    t_command *tmp;

    line = NULL;
    num = 0;
    (*header)->file_name = str;
    if((fd = open(str, O_RDONLY)) < 0)
        error_exit(str);
    while (get_next_line(fd, &line) > 0)
    {
        num++;
        if (ft_skip_comment(line))
            continue;
        else
            ft_fill_list(num,line,header);
        free(line);
    }
    if(line == NULL)
        error_exit("empty file\n");
    ft_validate_all_params(header);
    ft_check_params(*header);
    ft_count_pointer(*header);
    tmp = (*header)->com_list;
    int j;
    while(tmp)
    {
        j = 0;
        ft_printf("num=%d label=%s cmd=%s opcode=%d codage_pwdoctal=%d size=%d\n",tmp->num,tmp->label,tmp->command_name,tmp->opcode, tmp->codage_octal, tmp->size);
        while(j < 3)
        {
            ft_printf("type %d num %d pointer %s sum %d\n",tmp->type_arg[j],tmp->num_arg[j],tmp->pointer_arg[j],tmp->byte_sum[j]);
            j++;
        }
        tmp=tmp->next;
    }
    ft_write_to_file(*header);
}

