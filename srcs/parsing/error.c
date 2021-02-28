/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:02:26 by clbrunet          #+#    #+#             */
/*   Updated: 2021/02/23 14:38:28 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "ft.h"

void	free_commands(t_command **commands)
{
	(void)commands;
	/* free */
}

int	syntax_error(char const *unexpected_token)
{
	ft_putstr_fd(2, "minishell: syntax error near unexpected token `");
	ft_putstr_fd(2, unexpected_token);
	ft_putstr_fd(2, "'\n");
	return (1);
}
