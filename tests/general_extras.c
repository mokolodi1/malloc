// This file should be used to compile with other people's mallocs during
// correction. (Note that their might be some harmless warnings. :D)

// Here's the command to compile with someone else's malloc
// (assumes they included their libft in their project)
// gcc ./tests/general_tests.c ../malloc/tests/general_extras.c -L. -lft_malloc -Llibft -lft -I include -I libft

#include <stdlib.h>

int		ft_count_digits_ularge(uintmax_t number)
{
	int	count;

	if (number == 0)
		return (1);
	count = 0;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

intmax_t			ft_abs_large(intmax_t number)
{
	if (number < 0)
		return (-number);
	return (number);
}

void				write_chars(char *first, char *now, size_t number)
{
	while (now >= first)
	{
		*now = number % 10 + '0';
		number /= 10;
		now--;
	}
}

void				put_size_t(size_t number)
{
	char	string[128 + 1];
	int		length;

	if (number == 0)
		ft_putstr("0");
	else
	{
		length = ft_count_digits_ularge(ft_abs_large(number));
		write_chars(string, string + length - 1, number);
		string[length] = '\0';
		ft_putstr(string);
	}
}
