  
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cda-silv <cda-silv@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 20:15:20 by apuchill          #+#    #+#              #
#    Updated: 2020/05/02 13:47:37 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL_FOLDER	= ../
# BUF_OPT	= -D BUFFER_SIZE=
# BUF_SZ	= 20
# BUF_SZS	= 1 2 5 6 20 25 1024 5000 9999 10000000
# ALLTESTS = $(addprefix buf, $(BUF_SZS))

CC		= clang
# CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f
# VARS	= $(BUF_OPT)$(BUF_SZ)
# LIMITS	= -D ARG_MAX="sysconf(_SC_ARG_MAX)" -D OPEN_MAX=1024
COMPL	= $(CC) -o $(NAME) $(SRCS) main.c 

NAME	= a.out

FILES	= get_next_line.c get_next_line_utils.c
SRCS	= $(addprefix $(GNL_FOLDER), $(FILES))

all:		$(NAME)

$(NAME):
			@$(COMPL) 
			@./$(NAME)

tests:		fclean

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all


.PHONY:		all clean fclean re