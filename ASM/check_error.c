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

t_def_error error_def[10] = {
        {1,"not correct quotes"},
        {2,"syntax error at token .name"},
        {3,"syntax error at token .comment"},
        {4,"invalid command param"},
        {5,"5"},
        {6,"to many arg"},
        {7,"not correct name len"},
        {8,"not correct comment len"},
        {9,"not correct arg for cmd"},
        {10,"not correct label"}
};


int ft_check_quotes(char *str)
{
    int i;

    i = -1;
    while(str[++i])
        if(str[i] == '"')
        {
            while (str[++i])
                if(str[i] == '"')
                {
                    if(str[++i] == '\0')
                        return 0;
                    break;
                }
            while (str[i] == ' ')
                i++;
            if(str[i] && (str[i] == ' ' || str[i] == '#' ))
                return 0;
            else
                return 1;
        }
    return 1;
}

void validate_name_comment(t_header **header, char *type)
{
    char *str;
    int len;

    len = ft_strlen(type);
    if(len == 5)
        str = (*header)->bot_name;
    else
        str = (*header)->comment;
    if(ft_strnstr(str,type, len))
    {
        if (ft_check_quotes(str) == 1)
            error_cases(1,header);
        while(str[len] && str[len] != '"')
        {
            if(str[len] && str[len] != ' ' && str[len] != '\t')
                error_cases(2,header);
            len++;
        }
    }
    else
        error_cases(3,header);
}



void fill_name_cmt(t_header **header)
{
    char **arr;

    arr = ft_strsplit((*header)->bot_name, '"');
    if(arr[1])
        (*header)->bot_name = ft_strdup(arr[1]);
    else
        (*header)->bot_name = ft_strdup("");
    ft_clear(arr);
    (*header)->name__len = (int)ft_strlen((*header)->bot_name);
    arr = ft_strsplit((*header)->comment, '"');
    if(arr[1])
        (*header)->comment = ft_strdup(arr[1]);
    else
        (*header)->comment = ft_strdup("");
    (*header)->comment_len = (int)ft_strlen((*header)->comment);
    ft_clear(arr);
}




void validate_params(t_header **header)
{
    validate_name_comment(header,NAME_CMD_STRING);
    validate_name_comment(header,COMMENT_CMD_STRING);
    ft_printf("2\n");
    fill_name_cmt(header);
    ft_printf("3\n");
    validate_label(header);
    ft_printf("4\n");
    ft_check_params(*header);
}

void error_cases(int k, t_header **header)
{
    int i;
    i = 0;
    while(i < 11)
    {
        if(error_def[i].num == k)
        {
            ft_printf("%s\n", error_def[i].str);
            ft_free(header);
            exit(0);
        }
        i++;
    }
}
