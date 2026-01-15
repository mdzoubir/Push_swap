/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 15:26:39 by mzoubir           #+#    #+#             */
/*   Updated: 2026/01/15 15:26:40 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	free_cmd_list(t_ope **lst)
{
	t_ope	*tmp;
	t_ope	*current;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		if (current->line)
			free(current->line);
		free(current);
		current = tmp;
	}
	*lst = NULL;
}

void	add_cmd_back(t_ope **lst, char *line)
{
	t_ope	*new_node;
	t_ope	*last;

	if (!lst)
		return ;
	new_node = malloc(sizeof(t_ope));
	if (!new_node)
		return ;
	new_node->line = line;
	new_node->next = NULL;
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new_node;
}
