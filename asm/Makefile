##
## EPITECH PROJECT,
## Makefile
## File description:
## Makefile
##

FPERR = src/errors/

SRC	=	src/main.c							\
		$(FPERR)error.c						\
		$(FPERR)error_name_comment.c		\
		$(FPERR)error_functions.c			\
		$(FPERR)error_content.c				\
		$(FPERR)or_content.c				\
		src/get_header.c					\
		src/rewrite_str.c 					\
		src/compiler/create_file.c			\
		src/compiler/compiler.c				\
		src/compiler/write_command.c		\
		src/compiler/arg_gestion.c 			\
		src/compiler/write_opcode.c			\
		src/compiler/bin_to_dec.c			\
		src/compiler/endian_gestion.c 		\
		src/parser/parser.c					\
		src/get_prog_size.c 				\
		src/decoupe_line.c 					\
		src/label_char_argument_gestion.c 	\
		src/compiler/write_argument.c 		\
		src/usage.c							\
		src/commande_case.c 				\

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

CC	=	gcc -g3

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
