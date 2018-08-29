#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

void  ft_rewrite(char *inp, char *wr)
{
    int  fd;

    if (inp == NULL || wr == NULL)
        return ;
    if (!(fd = open(inp, O_TRUNC | O_WRONLY)))
        ft_putstr("Open error");
    if (write(fd, wr, ft_strlen(wr)))
        ft_putstr("Write success!");
}


void main(void){
//    int i = 10003;
//    char wr[1];
//    wr[0] = (char)i;
//    wr[1] = 0;

    int  a[4];
    a[0]=0;
    a[1]=234;
    a[2]=131;
    a[3]=243;

    if (!(fd = open("test.cor", O_TRUNC | O_WRONLY)))
        ft_putstr("Open error");
    for(int i = 0; i < 4; i++)
    {
        ft_putchar_fd(0,fd);
    }
}