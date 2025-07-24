
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int i;
    char *res;

    i = 0;
    res = malloc((ft_strlen(s) + 1) * sizeof(char));
    if (!res)
        return ((void *) 0);
    while (s[i])
    {
        ft_strlcat(res, f(i, &s[i]), 2);
        i++;
    }
    return (res);
}

/*
Return value The string created from the successive applications
of ’f’.
Returns NULL if the allocation fails.

External functs. malloc

Description Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to store the
results from the successive applications of f.

*/