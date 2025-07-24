CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g   #-fsanitize=address -g 
PTFLAG = -pthread

NAME = philo_bonus
SRC = philo_bonus.c parsing_utils_bonus.c parsing_bonus.c ft_init_bonus.c ft_helper_func_bonus.c philo_routine_bonus.c #monitor.c

OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(PTFLAG) -o $(NAME) $(OBJ)

%.o: %.c mandatory/philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all