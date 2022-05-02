# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:52:03 by dshirely          #+#    #+#              #
#    Updated: 2022/05/02 19:00:17 by dshirely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS=-Werror -Wextra -Wall
NAME=philo
SRC=*.c


all:
	@cc $(SRC) -o $(NAME) $(FLAGS)

clean:
	# @make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re





# SRCS		=*.c

# OBJ			=	${SRCS:.c=.o}

# CC			=	cc

# REMOVE		=	rm -f

# # CFLAGS		=	-Wall -Werror -Wextra -pthread

# NAME		=	philo

# HEADER		=	philo.h

# all:		 $(HEADER) $(NAME)

# $(NAME):	$(OBJ) $(HEADER)
# 			$(CC) ${OBJ} -o ${NAME} ${CFLAGS}
# clean:		
# 			@$(REMOVE) $(OBJ)
# fclean:		clean
# 			@$(REMOVE) $(NAME)

# re:			fclean all

# .PHONY:		all clean fclean re