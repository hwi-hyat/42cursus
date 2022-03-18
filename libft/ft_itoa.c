#include<stdlib.h>

int counter(int n)
{
	int	i;

	i = 0;
	while(n != 0)
	{
		n /= 10;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

void num_disp(char *out, int n, int neg, int i)
{
	if (i == 0 && neg == -1)
		out[i] = '-';
	if (i == counter(n))
		return;
	n /= (10 * neg);
	num_disp(out, n, neg, i + 1);
	out[i] = (n % 10) * neg + '0';
}

char *ft_itoa(int n)
{
	char	*out;
	int		neg;

	neg = 1;
	if (n < 0)
		neg = -1;
	out = (char *)malloc(sizeof(char) * (counter(n) + 1));
	if(out == NULL)
		return (NULL);
	num_disp(out, n, neg, 0);

	return (out);
}	