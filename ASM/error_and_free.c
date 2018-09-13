#include "asm.h"


t_def_error error_def[10] = {
        {1,"not correct quotes"},
        {2,"syntax error at token .name"},
        {3,"syntax error at token .comment"},
        {4,"invalid command param"},
        {5,"5"},
        {6,"to many arg"},
        {7,"not correct name len"},
        {8,"not correct comment len"},
        {9,"not correct arg for cmd"},
        {10,"not correct label"}
};



void error_cases(int k, t_header **header)
{
    int i;
    i = 0;
    while(i < 11)
    {
        if(error_def[i].num == k)
        {
            ft_printf("%s\n", error_def[i].str);
            ft_free(header);
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




void error_exit( const char *str)
{
    ft_printf("Can't read source file %s\n",str);
    exit(0);
}

