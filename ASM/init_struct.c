#include "asm.h"

t_command *create_new_node(int num, char *str)
{
    t_command *new_node;

    new_node = ft_memalloc(sizeof(t_command));
    new_node->line = ft_strdup(str);
    new_node->num = num;
    new_node->label_size = 2;
    return (new_node);
}


void init_struct(t_header **header)
{
    *header = ft_memalloc(sizeof(t_header));
}
