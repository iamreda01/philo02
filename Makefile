CC = cc
CFLAGS = -fsanitize=thread -g   #-fsanitize=address -g #-Wall -Wextra -Werror 
PTFLAG = -pthread

NAME = philo
SRC = philo.c parsing_utils.c parsing.c ft_init.c

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