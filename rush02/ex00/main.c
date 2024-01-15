/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:31:58 by martorre          #+#    #+#             */
/*   Updated: 2023/08/27 19:29:55 by xroca-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_atoi(char *str, int *out);
char	*ft_itoa(int nb);
char	*read_file(char *filename);
void	check(char *str, int num);
int		find_key(char *dict, char *key);
char	*find_value(char *dict, int line);
void	trim_print(char *str);
void	parse_num(int nb, char *dict, int ignore_last, int main_thread);
void	print_value(char *dict, char *key, int add_space);

void	parse_divide(int *nb, int val, char *dict)
{
	parse_num(*nb / val, dict, 0, 0);
	*nb %= val;
}

void	parse_divide_check(int *nb, char *dict, int ignore_last)
{
	if (*nb >= 1000000000)
	{
		parse_divide(nb, 1000000000, dict);
		print_value(dict, "1000000000", *nb > 0);
	}
	if (*nb >= 1000000)
	{
		parse_divide(nb, 1000000, dict);
		print_value(dict, "1000000", *nb > 0);
	}
	if (*nb >= 1000)
	{
		parse_divide(nb, 1000, dict);
		print_value(dict, "1000", *nb > 0);
	}
	if (*nb >= 100)
	{
		parse_divide(nb, 100, dict);
		print_value(dict, "100", *nb > 0);
	}
	if (*nb > 20 && !ignore_last)
	{
		parse_num(*nb / 10 * 10, dict, 1, *nb % 10 == 0);
		*nb %= 10;
	}
}

void	parse_num(int nb, char *dict, int ignore_last, int main_thread)
{
	char	*num;
	int		ignore_zero;

	ignore_zero = nb != 0;
	parse_divide_check(&nb, dict, ignore_last);
	if (!ignore_zero || nb != 0)
	{
		num = ft_itoa(nb);
		if (num)
		{
			print_value(dict, num, !main_thread);
			free(num);
		}
		else
			write(1, "Dict Error\n", 11);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		out;
	char	*dict;
	int		num;

	i = 0;
	out = 1;
	if (argc == 2 || argc == 3)
	{
		num = ft_atoi(argv[argc - 1], &out);
		if (out)
		{
			if (argc == 2)
				dict = read_file("numbers.dict");
			else
				dict = read_file(argv[1]);
			if (dict)
				parse_num(num, dict, 0, 1);
			free(dict);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
}
