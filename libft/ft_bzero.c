void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while(i < n)
	{
		*s = 0;
		s += 1;
		i++;
	}
}