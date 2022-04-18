##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## My_Sokoban
##

all:
	make -C ./asm/
	make -C ./corewar/

clean:
	make clean -C ./asm/
	make clean -C ./corewar/

fclean:	clean
		make fclean -C ./asm
		make fclean -C ./corewar

re:	fclean all
	make re -C ./asm
	make re -C ./corewar
