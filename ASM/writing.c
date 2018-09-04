#include "libft/libft.h"
#include "asm.h"
#include <fcntl.h>

union						u_byterange
{
    int						num;
    char					ch2[2];
    char					ch[4];
}							t_byterange;

void add_zero(int num, int fd)
{
    while (num > 0){
        print_to_file(fd,1,0);
        num--;
    }
}


void print_to_file(int fd, int byte, int param)
{
    t_byterange.num = param;
    int i;

    i = 3;
    if(byte == 1)
        ft_putchar_fd(t_byterange.num,fd);
    if(byte == 2)
    {
        ft_putchar_fd(t_byterange.ch2[1],fd);
        ft_putchar_fd(t_byterange.ch2[0],fd);
    }
    if(byte == 4)
        while(i > -1)
        {
            ft_putchar_fd(t_byterange.ch[i],fd);
            i--;
        }

}


void ft_write_command_to_file(t_header *header, int fd)
{
    t_command *tmp;
    int i;

    tmp = header->com_list;
    while(tmp)
    {
        if(tmp->opcode > 0)
        {
            t_byterange.num = tmp->opcode;
            print_to_file(fd,1, tmp->opcode);
            if(tmp->is_codage_octal == 1)
                print_to_file(fd,1, tmp->codage_octal);
            i = 0;
            while(i < 3)
            {
                if(tmp->type_arg[i])
                    print_to_file(fd,tmp->byte_sum[i], tmp->num_arg[i]);
                i++;
            }
        }
        tmp = tmp->next;
    }
}


void ft_write_to_file(t_header *header)
{
    int i;
    int fd;

    fd = open("test.cor", O_TRUNC | O_WRONLY);
    print_to_file(fd,4, COREWAR_EXEC_MAGIC);
    i = 0;
    while (header->prog_name[i]){

        print_to_file(fd,1,header->prog_name[i]);
        i++;
    }
    add_zero(PROG_NAME_LENGTH - header->name__len + 4, fd);
    print_to_file(fd, 4, header->prog_size);
    i = 0;
    while (header->comment[i]){

        print_to_file(fd,1,  header->comment[i]);
        i++;
    }
    add_zero(COMMENT_LENGTH - header->comment_len + 4, fd);
    ft_write_command_to_file(header,fd);
}