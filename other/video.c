#include <sys/mman.h>
#include <printf.h>
#include <stdlib.h>

int			main(int ac, char **av)
{
	int		i;
	int		number_of_bytes;
	char	character_to_write;
	char	*str_in_memory;

	number_of_bytes = atoi(av[2]);
	character_to_write = av[1][0];
	str_in_memory = (char*)mmap(0, number_of_bytes + 1, PROT_READ | PROT_WRITE
						, MAP_ANON | MAP_PRIVATE, -1, 0);
	i = 0;
	while (i < number_of_bytes)
	{
		str_in_memory[i] = character_to_write;
		i++;
	}
	str_in_memory[i] = '\0';
	printf("%s\n", str_in_memory);
	return (0);
}
