NAME    = minishell
CC      = gcc
FLAGS	= -Wall -Wextra -Werror -ggdb
LFLAGS	= -lreadline -L./libft -lft
SRCDIR	= src/
SRCFILE	=	additional_functions/ft_command_split.c\
			additional_functions/ft_envparam.c\
			additional_functions/ft_split.c\
			additional_functions/funny_functions.c\
			built_in/built_in_commands.c\
			built_in/echo.c\
			built_in/env.c\
			executing/executing.c\
			parsing/new_parsing.c\
			parsing/parse_quotes.c\
			parsing/parsing.c
MAIN	= main.c
BONUS	= main_bonus.c
SRCS	= $(addprefix $(SRCDIR), $(SRCFILE))
OBJDIR	= obj/
OBJFILE = $(SRCFILE:.c=.o)
OBJMAIN = $(addprefix $(OBJDIR), $(MAIN:.c=.o))
OBJBNS	= $(addprefix $(OBJDIR), $(BONUS:.c=.o))
OBJS	= $(addprefix $(OBJDIR), $(OBJFILE))
RM      = rm -rf
LIBHDR  = libft/libft.h
PIPHDR  = minishell.h

all: $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)additional_functions
	@mkdir -p $(OBJDIR)built_in
	@mkdir -p $(OBJDIR)executing
	@mkdir -p $(OBJDIR)parsing
	$(CC) $(FLAGS) -c $< -o $@  -include $(LIBHDR) -include $(PIPHDR)

$(NAME): $(OBJS) $(OBJMAIN) $(HEADER)
	@make -C libft
	$(CC) $(FLAGS) $(OBJS) $(OBJMAIN) $(LFLAGS) -o $(NAME)

bonus: $(OBJS) $(OBJBNS) $(HEADER)
	@make -C libft
	$(CC) $(FLAGS) -g $(OBJS) $(OBJBNS)  -o $(NAME)

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@make -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
