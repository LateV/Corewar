#include "libft/libft.h"
#include <fcntl.h>
#include "asm.h"


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
//            num++;
        }
        i++;
    }
    free(str);
    return 1;
}



int read_file(const char *str, t_header **header)
{
    t_command *new;
    char *s;
    int fd;
    char *line;
    int num;

    num = 0;
   //fd = open("../champs/bee_gees.s", O_RDONLY);
    if((fd = open(str, O_RDONLY)) < 0)
        error_exit(str);
    while (get_next_line(fd, &line) > 0)
    {
        num++;
        if(ft_strstr(line,NAME_CMD_STRING))
        {
            ft_check_name(line,header);
        }
        else if(ft_strstr(line,COMMENT_CMD_STRING))
        {
            ft_check_comment(line,header);
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

    //ft_label(*header);
    ft_count_pointer(*header);
    //ft_count_pointer(*header);
    new = (*header)->com_list;
    int i = 0;
    while(new != NULL)
    {
        (*header)->prog_size += new->size;
        int k = 0;
        i++;
        ft_printf("№ %d\n",i);
        ft_printf("label %s command %s\n",new->label, new->command_name);
        //ft_printf("opcode byte %d\n",new->codage_octal);
        ft_printf("size %d\n",new->size);
        while(new->pointer_arg[k])
        {
            ft_printf("pointer %s\n",new->pointer_arg[k]);
            k++;
        }
        k = 0;
        while(k < 3)
        {
            ft_printf("arg_type %d-> num %ld\n",new->type_arg[k],new->num_arg[k]);
            k++;
        }
        k = 0;
        while(k < 3)
        {
            ft_printf("byte_num %d\n",new->byte_sum[k]);
            k++;
        }
        new = new->next;
    }
    ft_printf("total prog size %d\n",(*header)->prog_size);
    return (1);
}
