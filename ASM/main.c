#include "asm.h"

int ft_check_flag(const char **argv, int argc)
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


int main(int argc, char const *argv[])
{
    t_header *header;
    int y;

    init_struct(&header);
    if (argc > 1)
    {
        if (ft_check_flag(argv, argc) && ft_check_extension(argv, argc - 1))
        {
           // -a : Instead of creating a .cor file, outputs a stripped and annotated version of the code to the standard output% ;
            ft_printf("flag + format");
        }
        else if((y = ft_check_extension(argv, argc - 1)) > 0)
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
