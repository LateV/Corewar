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
        if (str[i] == ':' && str[i - 1] && str[i - 1] == '%')
        {
            k = i++;
            while(str[k] && str[k] != ' ' && str[k] != ',')
                k++;
            (*node)->pointer_arg[num] = ft_strsub(str,i,k-i);
            num++;
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
    int i = 0;
//   fd = open("../champs/ex.s",O_RDONLY);
    if((fd = open(str, O_RDONLY)) < 0)
        error_exit(str);
    while (get_next_line(fd, &line) > 0)
    {
        i++;
        if(ft_strstr(line,NAME_CMD_STRING))
        {
            ft_check_name(line,header);
            // ft_printf("co")
        }
        else if(ft_strstr(line,COMMENT_CMD_STRING))
        {
            ft_check_comment(line,header);
        }
        else
        {
            //free new node;
            if(ft_strlen(line) == 0)
            {
                free(line);
                continue;
            }
            new = new_node();
            //function that will check for empty line, or line with \n etc...
            s = ft_find_label(line, &new,header);
            ft_find_pointer(line, &new);
            ft_find_command(s, &new);
            push_back(header,new);
         //   free(new);
        }
       free(line);
    }
//    i = 0;
//    new = (*header)->com_list;
//    while(new != NULL)
//    {
//        int k = 0;
//        i++;
//        ft_printf("LIST NUM %d\n",i);
//        ft_printf("LABEL %s\n",new->label);
//        ft_printf("COMMAND %s\n",new->command_name);
//        ft_printf("LABEL SIZE %d\n",new->label_size);
//        while(new->pointer_arg[k])
//        {
//            ft_printf("POINTER %d:%s\n",k,new->pointer_arg[k]);
//            k++;
//        }
//        k = 0;
//        while(k < 3)
//        {
//            ft_printf("ARG_TYPE and ARG_NUM %d:%d %ld\n",k,new->type_arg[k],new->num_arg[k]);
//            k++;
//        }
//        new = new->next;
//    }
    return (1);
}
