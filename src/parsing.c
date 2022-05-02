#include "../minishell.h"

char	**get_path(char **envp)
{
	char	**path;
	int		counter;

	path = NULL;
	counter = 0;
	while (envp[counter])
	{
		if (ft_strncmp(envp[counter], "PATH=", 5) == 0)
		{
			path = ft_split(envp[counter] + 5, ':');
			break ;
		}
		++counter;
	}
	return (path);
}

// char	**get_var_from_envp(char **envp, char *var)
// {
// 	char	**path;
// 	int		counter;

// 	path = NULL;
// 	counter = 0;
// 	while (envp[counter])
// 	{
// 		if (ft_strncmp(envp[counter], "PATH=", 5) == 0)
// 		{
// 			path = ft_split(envp[counter] + 5, ':');
// 			break ;
// 		}
// 		++counter;
// 	}
// 	return (path);
// }

char	*find_binary(char *command, char **envp)
{
	char	**path;
	char	*binary;
	int		counter;

	counter = -1;
	if (!command || !command[0] || ft_strchr(command, '/'))
		return (command);
	path = get_path(envp);
	while (path[++counter])
	{
		binary = ft_strcat_delim(path[counter], '/', command);
		if (access(binary, X_OK) == 0)
		{
			ft_freesplit(path);
			return (binary);
		}
		free(binary);
	}
	ft_freesplit(path);
	return (ft_strdup(command));
}

char	*substitute_envp(char *input, char **envp)
{
	int		i;
	char    *subbed;

	i = -1;
	subbed = ft_strdup("");
	while (input[++i])
	{
		if (input[i] == '$' && input[i + 1])
		{
			subbed = ft_strjoin(subbed, ft_find_envp(input + i + 1, envp));
			while (input[i + 1] && !is_in(input[i + 1], FT_SPACE))
				++i;
		}
		else if (((i > 0 && is_in(input[i - 1], FT_SPACE)) || i == 0) &&
			input[i] == '~')
		{
			subbed = ft_strjoin(subbed, ft_find_envp("HOME", envp));
			// ++i;
		}
		else
			subbed = ft_strcat_delim(subbed, input[i], ""); // <<< not really good, might change if feeling good 
	}
	// free(input); << not needed since we change free it in main
	return (subbed);
}

char	**parser(char *input, char **envp)
{
	char	**args;
	// char	*binary;
	// int		code;

	input = substitute_envp(input, envp);
	//printf("%s\n", input);
	args = ft_split_space(input, FT_SPACE);
    
	//args[0] = find_binary(args[0], envp);
	free(input);
	return args;
	// code = execve(args[0], args, NULL);
	// ft_freesplit(args);
	// if (code < 0)
	// 	ft_exit_message(binary, 2);
}
