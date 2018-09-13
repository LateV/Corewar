#include "asm.h"

t_def_error error_def[13] = {
        {1,"not correct quotes"},
        {2,"syntax error at token .name"},
        {3,"syntax error at token .comment"},
        {4,"invalid command param"},
        {5,"5"},
        {6,"to many arg"},
        {7,"not correct name len"},
        {8,"not correct comment len"},
        {9,"not correct arg for cmd"},
        {10,"not correct label"},
        {11,"no name"},
        {12,"no comment"},
        {13,"label exist"}
};


void error_cases(int k, t_header **header)
{
    int i;
    i = 0;
    while(i < 13)
    {
        if(error_def[i].num == k)
        {
            ft_printf("%s\n", error_def[i].str);
            ft_free(header);
            system("leaks my_asm > test.txt");
            exit(0);
        }
        i++;
    }
}
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



void ft_free(t_header **header)
{
    t_command *tmp;
    int i;

    tmp = (*header)->com_list;
    if((*header)->comment)
        free((*header)->comment);
    if((*header)->bot_name)
        free((*header)->bot_name);
    if((*header)->curr_label)
        free((*header)->curr_label);
    if((*header)->file_name)
        free((*header)->file_name);
    while(tmp)
    {
        i = -1;
        while(++i < 3)
            if(tmp->pointer_arg[i])
                free(tmp->pointer_arg[i]);
        if(tmp->line)
            free(tmp->line);
        if(tmp->label)
            free(tmp->label);
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

