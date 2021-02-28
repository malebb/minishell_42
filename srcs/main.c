/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 20:30:10 by clbrunet          #+#    #+#             */
/*   Updated: 2021/02/28 15:29:02 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "parsing.h"
#include "ft.h"
#include "command.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	int		line_read;
	t_command	**commands;

	(void)argv;
	if (argc != 1)
		return (1);
	line_read = 1;
	while (line_read == 1)
	{
		if (print_prompt())
			return (1);
		line_read = get_next_line(&line);
		commands = parse_line(line);
		free(line);
		find_exec(envp, "pwd");
		free_commands(commands);
	}
	if (line_read == -1)
		return (1);
	return (0);
}
