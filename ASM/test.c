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

//    int  a[4];
//    a[0]=0;
//    a[1]=234;
//    a[2]=131;
//    a[3]=243;

//    if (!(fd = open("test.cor", O_TRUNC | O_WRONLY)))
//        ft_putstr("Open error");
//    for(int i = 0; i < 4; i++)
//    {
//        ft_putchar_fd(0,fd);
//    }

    int a = 1;
    int b = 2;
    int c = 2;

    int a_1;
    int b_1;
    int c_1;

    a_1 = a << 6;
    //ft_printf("%d",a_1);
    b_1 = b << 4;
    c_1 = c << 2;

    int sum = a_1 | b_1 | c_1;
    ft_printf("%d",sum);
}
//
//
//#include "libft/libft.h"
//#include <stdio.h>
//#include <fcntl.h>
//
//void  ft_rewrite(char *inp, char *wr)
//{
//    int  fd;
//
//    if (inp == NULL || wr == NULL)
//        return ;
//    if (!(fd = open(inp, O_TRUNC | O_WRONLY)))
//        ft_putstr("Open error");
//    if (write(fd, wr, ft_strlen(wr)))
//        ft_putstr("Write success!");
//}
//
//union						u_byterange
//{
//    int						num;
//    char					ch2[2];
//    char					ch[4];
//}							t_byterange;
//
//
//void main(void){
////    int i = 10003;
////    char wr[1];
////    wr[0] = (char)i;
////    wr[1] = 0;
//
//    int a[4];
//    a[0]=0;
//    a[1]=234;
//    a[2]=131;
//    a[3]=243;
//    t_byterange.num = 0;
//    t_byterange.num = 0xea83f3;
//
//    int fd = open("test.cor", O_TRUNC | O_WRONLY);
//    // char *a = "zork";
//    for(int i = 3; i > -1; i--)
//    {
//        ft_putchar_fd(t_byterange.ch[i],fd);
//    }
//}