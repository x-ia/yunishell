# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2022/12/29 15:56:42 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME			= yunishell

# Component names
LIBNAME			= mylib

# Check the platform
OS				= $(shell uname)

# Enumeration of files
SRC				= ysh_main.c \
				  ysh_init.c \
				  ysh_sigset.c \
				  ysh_sighandler.c \
				  ysh_lexer.c \
				  ysh_lexer_gettoken.c \
				  ysh_lexer_string.c \
				  ysh_lexer_string_env.c \
				  ysh_lexer_string_lst.c \
				  ysh_lexer_tokenlen.c \
				  ysh_parser.c \
				  ysh_parser_cmdnew.c \
				  ysh_parser_cmdnew_arg.c \
				  ysh_parser_cmdnew_input.c \
				  ysh_parser_cmdnew_output.c \
				  ysh_parser_cmdnew_fdsize.c \
				  ysh_getpath.c \
				  ysh_setpath.c \
				  ysh_exec_builtin.c \
				  ysh_exec_child.c \
				  ysh_fd.c \
				  ysh_env.c \
				  ysh_builtin.c \
				  ysh_builtin_cd.c \
				  ysh_builtin_echo.c \
				  ysh_builtin_env.c \
				  ysh_builtin_exit.c \
				  ysh_builtin_export.c \
				  ysh_builtin_pwd.c \
				  ysh_builtin_unset.c \
				  ysh_lst2map.c \
				  ysh_strisdigit.c \
				  ysh_utils.c

ifneq (, $(findstring test_, $(MAKECMDGOALS)))
	SRC			+= $(MAKECMDGOALS).c
endif

# Enumeration of directories
SRCDIR			= ./src
INCDIR			= ./include
LIBDIR			= ./lib
OBJDIR			= ./obj

# Macros to replace and/or integrate
SRCS			= $(addprefix $(SRCDIR)/, $(SRC))
OBJS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS			= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))
LIBS			= $(LIBDIR)/$(LIBNAME).a

# Aliases of commands
CC				= cc
RM				= rm

# Command options (flags)
CFLAGS			= -MMD -Wall -Wextra -Werror
DEBUGCFLAGS		= -g -ggdb -fno-omit-frame-pointer
ifneq ($(OS), Darwin)
	DEBUGCFLAGS	+= -fstack-usage
endif

DEBUGLDFLAGS	= -fsanitize=address
INCLUDES		= -I$(INCDIR) -I$(LIBDIR)/include
RMFLAGS			= -r
LDFLAGS			= -lreadline

# Redefination when the specific target
ifeq ($(MAKECMDGOALS), debug)
	ifneq ($(OS), Darwin)
		CFLAGS	+= $(DEBUGCFLAGS)
		LDFLAGS	+= $(DEBUGLDFLAGS)
	endif
	DEF			= -D DEBUG_MODE=1
endif

ifneq (, $(findstring test_, $(MAKECMDGOALS)))
	CFLAGS		+= $(DEBUGCFLAGS)
	LDFLAGS		+= $(DEBUGLDFLAGS)
	DEF			= -D DEBUG_MODE=1
endif

ifeq ($(OS), Darwin)
	INCLUDES	+= -I$(shell brew --prefix readline)/include/
	LDFLAGS 	= -L$(shell brew --prefix readline)/lib -lreadline
endif

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all clean fclean re clean_partly debug_lib debug \
		test_lexer_expansion test_lexer_gettoken test_parser test_builtin

# Mandatory targets
all: $(LIBS) $(NAME)
clean:
	$(MAKE) clean -C $(LIBDIR)
	-$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	-$(RM) $(RMFLAGS) $(NAME)
re: fclean all

# Additional targets
debug_lib: 
	$(MAKE) debug -C $(LIBDIR)
debug: fclean debug_lib all
test_lexer_expansion:	all
test_lexer_gettoken:	all	
test_parser:			all	
test_builtin:			all	

# Recipes
$(NAME): $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) $(LIBS) $(LDFLAGS) -o $(NAME)
$(LIBS):
	$(MAKE) -C $(LIBDIR)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #


# Linux OS
# sudo apt install libreadline-dev

# mac OS
# curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
# brew install readline
# brew update && brew upgrade