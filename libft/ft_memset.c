void	*ft_memset(void *b, int c, size_t len)
{
	int	i;

	i = 0;
	while (i < len && b[i])
	{
		b[i] = c;
		i++;
	}
}