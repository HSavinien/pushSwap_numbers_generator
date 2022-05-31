/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:19:32 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/31 15:00:17 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	do_parsing(int ac, char **av, int *min, int *max)
{
	int	lst_len;

	if (ac < 2 || ac > 4)
		exit(printf("error arg\nusag : %s <lst_len> [min|max] [max]\n", av[0]));
	lst_len = atoi(av[1]);
	*min = 0;
	if (ac == 3)
		*max = atoi(av[2]);
	else if (ac == 4)
	{	
		*min = atoi(av[2]);
		*max = atoi(av[3]);
	}
	else
		*max = atoi(av[1]);
	if (lst_len <= 0)
		exit(printf("error: must generate at least one number\n"));
	if (*min < 0)
		exit(printf("error: can only generate positive numbers\n"));
	if (*max - *min < lst_len)
		exit(printf("error: range can't fit %d unique numbers\n", lst_len));
	return (lst_len);
}

int	is_duplicated(int nb, int *gen, int end)
{
	int	credit;
	int	i;

	credit = 2;
	i = 0;
	while (gen[i] < end && credit)
	{
		if (nb == gen[i])
			credit --;
		i ++;
	}
	if (credit)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	int	len;
	int	min;
	int	max;
	int	*gen;

	len = do_parsing(ac, av, &min, &max);
	gen = calloc(sizeof (int), len + 1);
	gen[len] = max + 1;
	srand(time(0));
	while (len)
	{
		gen[len - 1] = (rand() % (max - min)) + min;
		while (is_duplicated(gen[len - 1], gen, max + 1))
			gen[len - 1] = ((gen[len - 1] + 1) % (max - min)) + min;
		printf("%d ", gen[len - 1]);
		len --;
	}
	printf("\n");
}
