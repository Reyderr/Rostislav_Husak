#include <unistd.h>

int ft_skip(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void rostring(char *s)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (s[i])
	{
		while (ft_skip(s[i]))
			i++;
		if (s[i] && !ft_skip(s[i]))
			{
				if (!size)
					while (s[i] && !ft_skip(s[i++]))
						size++;
				else 
				{
					while (s[i] && !ft_skip(s[i]))
						write(1, &s[i++], 1);
					write(1, " ", 1);
				}	
			}
	}
i = 0;
	while (ft_skip(s[i]))
		i++;
	while (size--)
		write(1, &s[i++], 1);
}

int main(int ac, char **av)
{
	if (ac > 1 && *av[1])
		rostring(av[1]);
	write(1, "\n", 1);
	return (0);
}