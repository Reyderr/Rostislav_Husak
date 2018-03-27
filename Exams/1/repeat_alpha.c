#include "unistd.h"

int count_alpha(char c)
{
	int count;

	if (c >= 'A' && c <= 'Z')
		count = c - 'A' + 1;
	else if (c >= 'a' && c <= 'z')
		count = c - 'a' + 1;
	else 
		count = 1;
	return (count);
}


int main(int ac, char **av)
{
	int count;

	if (ac == 2)
		while (*av[1])
		{	
			count = count_alpha(*av[1]);
			while(count--)
				write(1, av[1], 1);
			av[1]++;
		}
	write(1,"\n", 1);
	return (0);
}