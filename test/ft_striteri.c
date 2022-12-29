
//s = string on which to iterate
//f = function apply to each character
//return : none
//func : none
//des : applies function on each character of the string passed as argument,
//passing its index as first argument.
//Each character is passed by address to 'f' to be modified if necessary
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
