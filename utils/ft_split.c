/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:16:49 by mzoubir           #+#    #+#             */
/*   Updated: 2025/10/17 21:16:50 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (c != s[i])
		{
			counter++;
			i++;
			while (s[i] && c != s[i])
				i++;
		}
		i++;
	}
	return (counter);
}

static void	free_memory(char **ptr, int c)
{
	while (c >= 0)
		free(ptr[c--]);
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		counter;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	ptr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	(1 == 1) && (i = 0, counter = 0);
	while (s[i])
	{
		j = 1;
		if (c != s[i])
		{
			while (s[i + j] && c != s[i + j])
				j++;
			ptr[counter] = ft_substr(s, i, j);
			if (!ptr[counter++])
				return (free_memory(ptr, counter - 2), NULL);
		}
		i += j;
	}
	return (ptr[counter] = NULL, ptr);
}