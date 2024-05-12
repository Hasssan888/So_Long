CC = cc 

FLAGC = -Wall -Wextra -Werror #-fsanitize=address -g3

NAME = so_long

BONUS = S_bouns

SRC = ./Mandatory/so_long.c ./Mandatory/get_next_line_utilis.c ./Mandatory/get_next_line.c ./Mandatory/utilis_1.c ./Mandatory/utilis_2.c  ./Mandatory/check_map.c \
./Mandatory/move_player.c ./Mandatory/print_map.c ./Mandatory/ft_putnbr.c ./Mandatory/utilis_3.c

SRC_BONUS = ./bonus/so_long_bonus.c ./bonus/get_next_line_utilis.c ./bonus/get_next_line.c ./bonus/utilis_1.c ./bonus/utilis_2.c  ./bonus/check_map.c \
./bonus/move_player.c ./bonus/print_map.c ./bonus/ft_putnbr.c ./bonus/utilis_3.c ./bonus/utilis_4.c ./bonus/utilis_5.c

OBJE = ${SRC:.c=.o}

OBJE_bonus = ${SRC_BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJE}
	${CC} ${FLAGC} ${OBJE} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

${BONUS} : ${OBJE_bonus}
	${CC} ${FLAGC} ${OBJE_bonus} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(BONUS)

bonus : ${BONUS}

%.o: %.c
	${CC} ${FLAGC} -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean :
	rm -f ${OBJE} ${OBJE_bonus}

fclean : clean
	rm -f $(NAME) ${BONUS}

re: fclean all bonus
