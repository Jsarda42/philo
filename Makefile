NAME = philo
SRCS = parsing.c init_data.c utils.c safe.c main.c threads.c routine.c dinner_end.c check_state.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Werror -Wextra -Wall -lpthread -g -O3
CC = cc
RM = rm -rf

all : ${NAME}
${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}
clean : 
	@${RM} ${OBJS}
fclean : clean
	@${RM} ${NAME}
re : fclean all

.PHONY : all fclean clean