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

    if(ft_strstr(str,NAME_CMD_STRING))
    {
        arr = ft_strsplit(str,' ');
        if(ft_strequ(arr[0],NAME_CMD_STRING))
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
        arr = ft_strsplit(str,' ');
        if(ft_strequ(arr[0],COMMENT_CMD_STRING))
        {
            (*header)->comment_len = ft_strlen(arr[1]);
            (*header)->comment= ft_strdup(arr[1]);
        }
        ft_clear(arr);
        return (1);
    }
    return 0;
}




int read_file(const char *str)
{
    t_header *header;
    int fd;
    char *line;

    fd = open(str, O_RDONLY);
    if(fd < 0)
        error_exit(str);
    header = malloc(sizeof(t_header));
    while (get_next_line(fd, &line) > 0)
    {
        if(ft_check_name(line,&header))
        {
            printf("%s\n",line);
            ft_printf("name\n");
        }
        else if(ft_check_comment(line,&header))
        {
            printf("%s\n",line);
            ft_printf("cmd\n");
        }
        else
        {
            printf("%s\n",line);
            ft_printf("command\n");
        }
    }
    printf("%s\n", header->comment);
    printf("%s\n", header->prog_name);
    return (1);
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