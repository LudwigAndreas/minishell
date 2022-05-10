/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdancy <kdancy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:36:42 by kdancy            #+#    #+#             */
/*   Updated: 2022/05/10 17:36:44 by kdancy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_msh g_msh;

void	very_important_function(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	(void)envp;
}

char	**make_sp_ops(void )
{
	char	**lst;

	lst = malloc(sizeof(*lst) * 11);
	lst[0] = ft_strdup(";");
	lst[1] = ft_strdup("&&");
	lst[2] = ft_strdup("||");
	lst[3] = ft_strdup("&");
	lst[4] = ft_strdup("|");
	lst[5] = ft_strdup("<<");
	lst[6] = ft_strdup(">>");
	lst[7] = ft_strdup("<");
	lst[8] = ft_strdup(">");
	lst[9] = ft_strdup("end");
	lst[10] = NULL;
	return (lst);
}

void	set_g_msh(char **envp)
{
	g_msh.envp = envp;
	g_msh.sp_ops = make_sp_ops();
	g_msh.last_ex_code = 0;
}

int main(int argc, char **argv, char **envp)
{
	char		*input;
	// t_command	*commands;
	// char	**args;
	// int		code;

	very_important_function(argc, argv, envp);
	set_g_msh(envp);
	while (1)
	{
		input = readline("\033[1;31mඞ\033[0mabobus\033[1;36mඞ\033[0m> ");
		add_history(input);
		start(input);
		free(input);
		// ft_freesplit(args);
	}
	return 0;
}
