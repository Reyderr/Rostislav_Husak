#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size);

int main()
{
	int z;
	int i[10] = {10, 100, 55, -10, 40};
	
	sort_int_tab(i, 5);
	while (i[z])
		printf("%i\n", i[z++]);
//	printf("%d\n", ft_itoa(i));
	return (0);
}
