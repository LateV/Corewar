#include "libft/libft.h"
#include <fcntl.h>
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


size_t	ft_arr_len(char **arr)
{
    size_t	count;

    count = 0;
    while (arr[count])
        count++;
    return (count);
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

int ft_check_flag(const char **argv, int argc)
{
    int i;

    i = argc-1;
    if(ft_strequ(argv[i], "-a") && argc == 2)
        error_exit("null");
    while(i > 0)
    {
        if(ft_strequ(argv[i], "-a"))
            return (1);
        i--;
    }
    return (0);
}


int ft_check_name(char *str, t_header **header)
{
    char **arr;

    if(ft_strstr(str, NAME_CMD_STRING))
    {
        arr = ft_strsplit(str,'"');
        if(ft_strequ(ft_strtrim(arr[0]),NAME_CMD_STRING))
        {
            (*header)->name__len = ft_strlen(arr[1]);
            (*header)->prog_name= ft_strdup(arr[1]);
        }
        ft_clear(arr);
        return (1);
    }
    return 0;
}


int ft_check_comment(char *str, t_header **header)
{
    char **arr;

    if(ft_strstr(str,COMMENT_CMD_STRING))
    {
        arr = ft_strsplit(str,'"');
        if(ft_strequ(ft_strtrim(arr[0]),COMMENT_CMD_STRING))
        {
            (*header)->comment_len = ft_strlen(arr[1]);
            (*header)->comment = ft_strdup(arr[1]);
        }
        ft_clear(arr);
        return (1);
    }
    return 0;
}


char  *ft_find_label(char *str, t_command **node, t_header **header)
{
    int i;
    char *line;

    i = 0;
    str = ft_strtrim(str);
    while(str[i])
    {
        if (str[i] == ':' && str[i - 1] && str[i - 1] != '%')
        {
            //check if no syb before :
            //check for valid symb in LABEL
            (*node)->label = ft_strsub(str,0,i);
            line = ft_strsub(str,i+1,ft_strlen(str)-i);
            (*header)->curr_label = (*node)->label;
            return line;
           // printf("LABEL\n start: %d  len: %d -----%s\n",0,i,label);
        }
        i++;
    }
    if((*node)->label == NULL)
        (*node)->label = (*header)->curr_label;
    return str;
}


t_command *new_node()
{
    t_command *new_node;

    new_node = malloc(sizeof(t_command));
    new_node->num = 0;
    new_node->label = NULL;
    new_node->label_size = 2;
    new_node->command_name = NULL;
    new_node->type_arg[0] = 0;
    new_node->type_arg[1] = 0;
    new_node->type_arg[2] = 0;
    new_node->opcode = 0;
    new_node->pointer_arg[0] = NULL;
    new_node->pointer_arg[1] = NULL;
    new_node->pointer_arg[2] = NULL;
    new_node->num_arg[0] = 0;
    new_node->num_arg[1] = 0;
    new_node->num_arg[2] = 0;
    new_node->byte_sum[0] = 0;
    new_node->byte_sum[1] = 0;
    new_node->byte_sum[2] = 0;
    new_node->byte_sum[3] = 0;
    new_node->next = NULL;
    return (new_node);
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
//    (*header)->com_list = tmp;
}







void fill_command_params()
{

}

int main(int argc, char const *argv[])
{
    int y;

    if (argc > 1)
    {
        if(ft_check_flag(argv,argc) && ft_check_extension(argv,argc-1))
        {
            //-a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output% ;
            ft_printf("flag + format");
        }
        else if((y = ft_check_extension(argv,argc-1)) > 0)
        {
            read_file(argv[y]);
        }
        else
            error_exit(argv[argc-1]);
    }
    else
        ft_putstr("Usage: ./asm [-a] <sourcefile.s>\n"
                          "    -a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output");
    return 0;
}
