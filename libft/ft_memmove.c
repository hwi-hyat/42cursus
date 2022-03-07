void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;
	void temp;

	i = 0;
	while(i < len)
	{
		temp = src[i];
		dest[i] = temp;
		i++;
	}
}