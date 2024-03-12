NAME = philo
SRCS = $(wildcard *.c)
OBJS = ${SRCS:.c=.o}
FLAGS = -Werror -Wextra -Wall -lpthread -g -O3
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