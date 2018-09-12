#include "asm.h"

t_command *create_new_node(int num, char *str)
{
    t_command *new_node;

    new_node = malloc(sizeof(t_command));
    new_node->line = ft_strdup(str);
    new_node->num = num;
    new_node->opcode = 0;
    new_node->size = 0;
    new_node->label = NULL;
    new_node->label_size = 2;
    new_node->command_name = NULL;
    new_node->type_arg[0] = 0;
    new_node->type_arg[1] = 0;
    new_node->type_arg[2] = 0;
    new_node->is_codage_octal = 0;
    new_node->pointer_arg[0] = NULL;
    new_node->pointer_arg[1] = NULL;
    new_node->pointer_arg[2] = NULL;
    new_node->num_arg[0] = 0;
    new_node->num_arg[1] = 0;
    new_node->num_arg[2] = 0;
    new_node->byte_sum[0] = 0;
    new_node->byte_sum[1] = 0;
    new_node->byte_sum[2] = 0;
    new_node->next = NULL;
    return (new_node);
}


void init_struct(t_header **header)
{
    *header = malloc(sizeof(t_header));
    (*header)->bot_name = NULL;
    (*header)->name__len = 0;
    (*header)->prog_size = 0;
    (*header)->comment = NULL;
    (*header)->comment_len = 0;
    (*header)->com_list = NULL;
    (*header)->curr_label = NULL;
}
