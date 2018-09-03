#include "libft/libft.h"
#include "asm.h"
#include <fcntl.h>

union						u_byterange
{
    int						num;
    char					ch2[2];
    char					ch[4];
}							t_byterange;




void ft_write_to_file(t_header *header)
{
    t_byterange.num = 0xea83f3;
    int len;

    ft_printf("-------I AM HERE----------\n");
    int fd = open("test.cor", O_TRUNC | O_WRONLY);
    // char *a = "zork";
    for(int i = 3; i > -1; i--)
    {
        ft_putchar_fd(t_byterange.ch[i],fd);
    }
int i = 0;
    while (header->prog_name[i]){

        t_byterange.num = header->prog_name[i];
        ft_putchar_fd(t_byterange.num,fd);
        i++;
    }
    len = PROG_NAME_LENGTH - header->name__len;
    while (len > 0){

        t_byterange.num = 0;
        ft_putchar_fd(t_byterange.num,fd);
        len--;
    }
    int check_sum = 4;
    while (check_sum > 0){

        t_byterange.num = 0;
        ft_putchar_fd(t_byterange.num,fd);
        check_sum--;
    }
   // size
    t_byterange.num = header->prog_size;
    ft_printf("size %d\n",header->prog_size);
    i = 3;
    while(i > -1){
        ft_printf("%d\n", i);
        ft_putchar_fd(t_byterange.ch2[i],fd);
        i--;
    }

    len = COMMENT_LENGTH - header->comment_len;
    i = 0;
    while (header->comment[i]){

        t_byterange.num = header->comment[i];
        ft_putchar_fd(t_byterange.num,fd);
        i++;
    }
    while (len > 0){

        t_byterange.num = 0;
        ft_putchar_fd(t_byterange.num,fd);
        len--;
    }
    //null

}