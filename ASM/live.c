#include "libft/libft.h"
#include "asm.h"


//ft_valid_live()
//{
//
//}



//void ft_find_arg_type(char *str, t_command **node, t_header **header)
//{
//
//}



void ft_find_command(char *str, t_command **node)
{
    int i;


    i = 0;
    char *s;
  //  char *line;
    s = ft_strtrim(str);

    while(i < 17)
    {
        if(ft_strnstr(s,g_def[i].name,ft_strlen(g_def[i].name)))
        {
            ft_printf("%d\n",i);
            //ft_valid_live(); only one argument with T_dir(%);
            (*node)->command_name = g_def[i].name;
            (*node)->num = i;
            (*node)->label_size = ft_strlen(g_def[i].name);

            //ft_printf("line wit command %s\n",s);
           // line = ft_strsub(s,4,ft_strlen(s) - 4);
           // ft_find_arg_type(line, node, header);
           // ft_printf("line without command %s\n",line);
        }
        i++;
    }


}