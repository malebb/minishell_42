/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 11:26:28 by mlebrun           #+#    #+#             */
/*   Updated: 2021/03/08 16:40:04 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include <unistd.h>

# include "cmd.h"

int		echo(t_cmd const *cmd, char **envp_ptr[]);
int		cd(t_cmd const *cmd, char **envp_ptr[]);
int		env(t_cmd const *cmd, char **envp_ptr[]);
int		export_cmd(t_cmd const *cmd, char **envp_ptr[]);

#endif
