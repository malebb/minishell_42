/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_built_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 17:36:01 by clbrunet          #+#    #+#             */
/*   Updated: 2021/03/06 17:42:03 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "built_in.h"
#include "ft.h"

t_built_in_ft	search_built_in(t_cmd const *cmd)
{
	if (ft_strcmp(cmd->exe, "echo") == 0)
		return (&echo);
	else if (ft_strcmp(cmd->exe, "cd") == 0)
		return (&cd);
	else if (ft_strcmp(cmd->exe, "export") == 0)
		return (&export_cmd);
	else if (ft_strcmp(cmd->exe, "env") == 0)
		return (&env);
	return (NULL);
}
