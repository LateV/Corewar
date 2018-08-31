#include "libft/libft.h"
#include "asm.h"


//ft_valid_live()
//{
//
//}



void ft_find_arg_type(char *str, t_command **node)
{
    char *line;
    char **arr;
    int i;
    size_t k;
    size_t len;
    int l;


    l = 0;
    i = 0;

    if(ft_strlen(str) == 0)
        return ;
    str = ft_strtrim(str);
    line = ft_strsub(str,ft_strlen((*node)->command_name),ft_strlen(str)-ft_strlen((*node)->command_name));
    arr = ft_strsplit(line,',');
    len = ft_arr_len(arr);
    while (arr[l])
    {
        arr[l] = ft_strtrim(arr[l]);
        l++;
    }
    while(i < 17)
    {
        if(g_def[i].name == (*node)->command_name)
        {
            k = 0;
            while(k < len)
            {
                //ft_printf("arr[%d] =%s\n",k,arr[k]);
                if(arr[k][0] == 'r')
                {
                    (*node)->type_arg[k] = 1;
                    arr[k] = ft_strsub(arr[k],1,ft_strlen(arr[k])-1);
                    (*node)->num_arg[k] = ft_atoi(arr[k]);
                }
                else if(arr[k][0] == '%')
                {
                    (*node)->type_arg[k] = 2;
                    arr[k] = ft_strsub(arr[k],1,ft_strlen(arr[k])-1);
                    (*node)->num_arg[k] = ft_atoi(arr[k]);
                }
                else
                {
                    (*node)->type_arg[k] = 3;
                }
                k++;
            }
        }
        i++;
    }

}



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
            (*node)->command_name = g_def[i].name;
            (*node)->label_size = ft_strlen(g_def[i].name);
            break;
            //ft_printf("line wit command %s\n",s);
           // line = ft_strsub(s,4,ft_strlen(s) - 4);
           // ft_printf("line without command %s\n",line);
        }
        i++;
    }
    ft_find_arg_type(str, node);
}