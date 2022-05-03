# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:52:03 by dshirely          #+#    #+#              #
#    Updated: 2022/05/03 15:28:06 by dshirely         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

INC 	= philo.h

SRC		=	main.c\
			routine.c\
			time.c\
			utils.c\

CC 		= gcc

FLAGS	= -Wall -Wextra -Werror -pthread

OBJS 	= $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME) $(OBJS) $(INC)

%.o: %.c $(INC)
		$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
