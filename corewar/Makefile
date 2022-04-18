##
## EPITECH PROJECT,
## Makefile
## File description:
## Makefile
##

FPERR = src/errors/

SRC	= 	src/main.c					\
		src/error.c 				\
		src/fill_champion.c 		\
		src/fill_champion_struct.c 	\
		src/endian_gestion.c 		\
		src/commande_case.c 		\
		src/argument_gestion.c 		\
		src/special_case.c 			\
		src/memory/init_memory.c	\
		src/corewar.c				\
		src/fill_adress.c 			\
		src/fill_champ_param.c 		\


OBJ	= $(SRC:.c=.o)

NAME = corewar

CC = gcc -g3

CFLAGS = -I./../include/ -L./../lib/ -lmy # -Wall -Wextra

FLAG_T = --coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./../lib/
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		make clean -C ./../lib/
		rm -f $(OBJ)

fclean:		clean
		make fclean -C ./../lib/
		rm -f $(NAME)


re:		fclean all
