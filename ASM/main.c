#include "asm.h"

t_def_com g_def[17] = {
        {1, "live",1,{2,0,0},{0,0,0},{0,0},4,0},
        {2, "ld", 2, {2,3,0},{1,0,0},{0,0},4,1},
        {11, "sti",3,{1,0,0},{1,2,3},{1,2},2,1},
        {3, "st", 2,{1,0,0},{1,3,0},{0,0},4,1},
        {4, "add", 3,{1,0,0},{1,0,0},{1,0},4,1},
        {5, "sub", 3,{1,0,0},{1,0,0},{1,0},4,1},
        {6, "and", 3,{3,2,1},{3,2,1},{1,0},4,1},
        {7, "or", 3,{3,2,1},{3,2,1},{1,0},4,1},
        {8, "xor", 3,{3,2,1},{3,2,1},{1,0},4,1},
        {9, "zjmp",1, {2,0,0},{0,0,0},{0,0},2,0},
        {10, "ldi", 3,{3,2,1},{1,2,0},{1,0},2,1},
        {12, "fork", 1,{2,0,0},{0,0,0},{0,0},2,0},
        {14, "lldi", 3,{1,2,3},{1,2,0},{1,0},2,1},
        {13, "lld", 2,{2,3,0},{1,0,0},{0,0},4,1},
        {15, "lfork",1, {2,0,0},{0,0,0},{0,0},2,0},
        {16, "aff", 1,{1,0,0},{0,0,0},{0,0},4,1},
        {0, "NULL",1, {0,0,0},{0,0,0},{0,0},0,0}
};


int check_flag(const char **argv, int argc)
{
    int i;

    i = argc - 1;
    if (ft_strequ(argv[i], "-a") && argc == 2)
        error_exit("null");
    while(i > 0)
    {
        if(ft_strequ(argv[i], "-a"))
            return (1);
        i--;
    }
    return (0);
}

void get_prog_name(t_header *header)
{
    char *str;
    char *s;

    str = ft_strrchr(header->file_name, '/');
    char_pos(str, '.');
    s = ft_strsub(str,1, char_pos(str, '.') - 1);
    header->file_name = ft_strjoin(s,".cor");
    ft_printf("%s '%s'\n",str, header->file_name );
}

int check_extension(const char **str, int y)
{
    size_t len;

    if(ft_strequ(str[y], "-a"))
        y--;
    len = ft_strlen(str[y]);
    if(str[y][len-1] == 's' && str[y][len-2] == '.')
        return (y);
    return (-1);
}


int main(int argc, char const *argv[])
{
    t_header *header;
    int y;

    init_struct(&header);
    if (argc > 1)
    {
        if (check_flag(argv, argc) && check_extension(argv, argc - 1))
        {
           // -a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output% ;
            ft_printf("flag + format");
        }
        else if((y = check_extension(argv, argc - 1)) > 0)
        {
            read_file(argv[y], &header);
        }
        else
            error_exit(argv[argc - 1]);
    }
    else
        ft_putstr("Usage: ./asm [-a] <sourcefile.s>\n"
                          "    -a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output");
//    //system("leaks my_asm > test.txt");
    return (0);
}
