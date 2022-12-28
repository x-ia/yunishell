# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2022/12/28 22:58:14 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ********************** Section for Macros (Variables) ********************** #
# Product file
NAME		= mylib.a

# Component names
NAME_LIBC	= libc
NAME_PRINTF	= printf

# Enumeration of files
SRC_PRINTF	= my_printf.c my_dprintf.c my_dprintf_sub.c prf_conv.c prf_getconv.c \
			  prf_setconv.c prf_setconv_flag.c prf_setconv_type.c \
			  prf_setconv_length.c prf_setconv_order.c prf_setconv_wandp.c \
			  prf_convarg.c prf_convarg_s.c prf_convarg_ws.c \
			  prf_convarg_i.c prf_convarg_ui.c prf_convarg_p.c \
			  prf_convarg_dbl.c prf_convarg_nan.c prf_convarg_ftoe.c \
			  prf_convarg_a.c prf_convarg_la.c \
			  prf_chrtostr.c prf_wchrtostr.c \
			  prf_hasflag.c prf_putlen.c  prf_shiftarg.c prf_getpresentret.c \
			  prf_adjustdigit.c \
			  prf_rounddigit.c prf_rounddigit_fill.c prf_rounddigit_getlen.c \
			  prf_rounddigit_a.c prf_rounddigit_a_getlen.c \
			  prf_rounddigit_a_fill.c prf_rounddigit_a_fill_len.c \
			  prf_putplane.c prf_putpadding.c \
			  prf_putchar.c prf_putstr.c prf_putstrn.c \
			  prf_ulltostr_o.c prf_ulltostr_x.c prf_ftoa.c \
			  prf_strjoin.c prf_strtoupper.c prf_hexdigitadd.c \
			  prf_strnchr.c prf_strrnchr.c prf_isdigit19.c prf_isxdigit1f.c \
			  my_wcslen.c my_isxdigit.c my_lltostr.c my_ulltostr.c
SRC_LIBC	= my_isalpha.c my_isdigit.c my_isalnum.c \
			  my_isascii.c my_isprint.c \
			  my_strlen.c my_memset.c my_bzero.c my_memcpy.c my_memmove.c \
			  my_strlcpy.c my_strlcat.c my_toupper.c my_tolower.c \
			  my_strchr.c my_strrchr.c my_strncmp.c my_memchr.c my_memcmp.c \
			  my_strnstr.c my_atoi.c my_calloc.c my_strdup.c \
			  my_substr.c my_strjoin.c my_strtrim.c my_split.c my_itoa.c \
			  my_strmapi.c my_striteri.c \
			  my_putchar_fd.c my_putstr_fd.c my_putendl_fd.c my_putnbr_fd.c \
			  my_lstnew.c my_lstadd_front.c my_lstsize.c my_lstlast.c \
			  my_lstadd_back.c my_lstdelone.c my_lstclear.c \
			  my_lstiter.c my_lstmap.c

# Enumeration of directories
SRCDIR		= ./src
INCDIR		= ./include
OBJDIR		= ./obj
#LIBDIR		= ./$(LIBNAME)/

# Redefination when the specific target (bunus)
ifeq ($(MAKECMDGOALS), bonus)
	SRCS	= $(SRCSB)
	OBJS	= $(OBJSB)
	DEPS	= $(DEPSB)
endif

# Macros to replace and/or integrate
SRCS_LIBC	= $(addprefix $(SRCDIR)/$(NAME_LIBC)/, $(SRC_LIBC))
SRCS_PRINTF	= $(addprefix $(SRCDIR)/$(NAME_PRINTF)/, $(SRC_PRINTF))
SRCS		= $(SRCS_LIBC) $(SRCS_PRINTF)
OBJS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
DEPS		= $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.d)))

# Aliases of commands
CC			= cc
AR			= ar
RM			= rm

# Command options (flags)
CFLAGS		= -MMD -Wall -Wextra -Werror
INCLUDES	= -I$(INCDIR)
ARFLAGS		= rcs
RMFLAGS		= -rf

# Redefination when the specific target (debug)
ifeq ($(MAKECMDGOALS), debug)
	CFLAGS	+= $(DEBUGFLAGS)
	DEF		= -D DEBUG_MODE=1
endif

# ********************* Section for targets and commands ********************* #
# Phonies
.PHONY: all bonus clean fclean re

# Mandatory targets
all: $(NAME)
bonus: $(NAME)
clean:
	$(RM) $(RMFLAGS) $(OBJDIR)
fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
re: fclean $(OBJDIR) all

# Recipes
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
$(OBJDIR):
	@mkdir -p $@
$(OBJDIR)/%.o: $(SRCDIR)/$(NAME_LIBC)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<
$(OBJDIR)/%.o: $(SRCDIR)/$(NAME_PRINTF)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(DEF) $(INCLUDES) -o $@ -c $<

# Including and ignore .dep files when they are not found
-include $(DEPS)

# ******** ******** ******** ******** **** ******** ******** ******** ******** #
