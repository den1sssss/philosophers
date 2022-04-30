FLAGS=-Werror -Wextra -Wall
NAME=philo
SRC=*.c
# INCLUDES=libft/libft.a

all:
	# @make -C libft/ all
	@gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) 

clean:
	# @make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	# @make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus