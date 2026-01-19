/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:16:49 by mzoubir           #+#    #+#             */
/*   Updated: 2026/01/09 13:35:12 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static int	free_memory(char **ptr, int c)
{
	while (c >= 0)
		free(ptr[c--]);
	free(ptr);
	return (0);
}

static int	fill_split(char **ptr, const char *s, char c)
{
	int		i;
	int		j;
	int		counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			ptr[counter] = ft_substr(s, i, j);
			if (!ptr[counter++])
				return (free_memory(ptr, counter - 2));
			i += j;
		}
		else
			i++;
	}
	return (ptr[counter] = NULL, 1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	if (!fill_split(ptr, s, c))
		return (NULL);
	return (ptr);
}
