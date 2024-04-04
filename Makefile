CC = cc 

FLAGC = -Wall -Wextra -Werror -fsanitize=address -g3

NAME = so_long

#BONUS = pipex_bonus

SRC = so_long.c get_next_line_utilis.c get_next_line.c utilis_1.c

#SRC_BONUS =

OBJE = ${SRC:.c=.o}

#OBJE_bonus = ${SRC_BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJE}
	${CC} ${FLAGC} ${OBJE} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#${BONUS} : ${OBJE_bonus}
#	${CC} ${FLAGC} -o ${BONUS} ${OBJE_bonus}

#bonus : ${BONUS}

%.o: %.c
	${CC} ${FLAGC} -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	rm -f ${OBJE}

fclean : clean
	rm -f $(NAME)

re: fclean all #bonus
