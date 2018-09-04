#include "libft.h"

void	ft_reverse_bits(void *a, size_t size)
{
	size_t	i;
	char	tmp;
	char	*bits;

	i = 0;
	if(!a)
		return;
	bits = (char*)a;
	while (i != size - i)
	{
		tmp = bits[i];
		bits[i] = bits[size - 1 - i];
		bits[size - 1 - i] = tmp;
		i++;
	}
}