CC = cc 

FLAGC = -Wall -Wextra -Werror #-fsanitize=address -g

NAME = so_long

#BONUS = pipex_bonus

SRC = so_long.c get_next_line_utilis.c get_next_line.c utilis_1.c

#SRC_BONUS =

OBJE = ${SRC:.c=.o}

#OBJE_bonus = ${SRC_BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJE}
	${CC} ${FLAGC} -o ${NAME} ${OBJE}

#${BONUS} : ${OBJE_bonus}
#	${CC} ${FLAGC} -o ${BONUS} ${OBJE_bonus}

#bonus : ${BONUS}

%.o: %.c
	${CC} ${FLAGC} -c $< -o $@

clean :
	rm -f ${OBJE}

fclean : clean
	rm -f $(NAME)

re: fclean all #bonus
