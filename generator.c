/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:19:32 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/30 17:26:25 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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
	if (*max - *min < lst_len)
		exit(printf("error: range can't fit %d unique numbers\n", lst_len));
	if (min < 0)
		exit(printf("error: can only generate positive numbers\n"));
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

/*
int	main(int ac, char **av)
{
	int *tab;
	int	i;

	if (ac == 1)
		return(0);
	tab = calloc(sizeof (int), ac + 1);
	tab[ac] = 99;
	i = 1;
	while (i < ac)
	{	
		tab[i - 1] = atoi(av[i]);
		i ++;
	}
	i = 0;
	while (i < ac - 1)
		printf("%d ", tab[i ++]);
	printf("\nis %d duplicated : %d\n",tab[0], is_duplicated(tab[0], tab, 99));
}
*/
int	main(int ac, char **av)
{
	int	len;
	int	min;
	int	max;
	int	*gen;

	len = do_parsing(ac, av, &min, &max);
	gen = calloc(sizeof (int), len + 1);
	gen[len] = max + 1;
	sranddev();
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
