# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2022/12/28 22:57:41 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= my_libc.a
SRCH	= my_libc.h
OBJ1	= my_isalpha.o my_isdigit.o my_isalnum.o my_isascii.o my_isprint.o \
		  my_strlen.o my_memset.o my_bzero.o my_memcpy.o my_memmove.o \
		  my_strlcpy.o my_strlcat.o my_toupper.o my_tolower.o my_strchr.o \
		  my_strrchr.o my_strncmp.o my_memchr.o my_memcmp.o my_strnstr.o my_atoi.o \
		  my_calloc.o my_strdup.o
OBJ2	= my_substr.o my_strjoin.o my_strtrim.o my_split.o my_itoa.o \
		  my_strmapi.o my_striteri.o my_putchar_fd.o my_putstr_fd.o \
		  my_putendl_fd.o my_putnbr_fd.o
OBJB	= my_lstnew.o my_lstadd_front.o my_lstsize.o my_lstlast.o \
		  my_lstadd_back.o my_lstdelone.o my_lstclear.o my_lstiter.o my_lstmap.o
CFLAGS	= -Wall -Wextra -Werror
CC		= gcc
AR		= ar rcs
RM		= rm -f
OBJS 		= $(OBJ1) $(OBJ2)
ifdef WITH_BONUS
	OBJS += $(OBJB)
endif

all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
bonus: 
	make WITH_BONUS=1
%.o: %.c $(SRCH)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ1) $(OBJ2) $(OBJB)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all bonus clean fclean re
