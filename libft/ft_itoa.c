#include<stdlib.h>

int counter(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while(n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	neg(int n)
{
	if (n >= 0)
		return (1);
	else
		return (-1);
}

void num_disp(char *out, int n, int len)
{
	out[len] = 0;
	len--;
	if (n < 0)
		out[0] = '-';
	while (n != 0)
	{
		out[len] = (n % 10) * neg(n) + '0';
		len--;
		n /= 10;
	}
}

char *ft_itoa(int n)
{
	char	*out;

	if (n == 0)
	{
		out = (char *)malloc(sizeof(char) * 2);
		if (out == NULL)
			return (NULL);
		out = "0";
		return (out);
	}
	out = (char *)malloc(sizeof(char) * (counter(n)) + 1);
	if (out == NULL)
		return (NULL);
	num_disp(out, n, counter(n));
	return (out);
}