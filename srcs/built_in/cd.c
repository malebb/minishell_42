/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 11:32:44 by mlebrun           #+#    #+#             */
/*   Updated: 2021/02/28 17:54:15 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	cd(t_cmd *cmd)
{
	/*temporary variable (wait for parsing) */
	char	*path = "../fnem";

	(void)cmd;
	if (printf("ret = %d", chdir(path) == -1))
		return (-1);
	return (1);
}
