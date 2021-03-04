##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.cpp				\
		src/Tas.cpp					\
		src/Card.cpp				\
		src/Tile.cpp				\
		src/Sound.cpp				\
		src/Klondike.cpp			\
		src/KlondikeEvents.cpp		\

OBJ = 	$(SRC:.cpp=.o)

NAME = 	Klondike

CXXFLAGS = -std=c++11 -Wall -Wextra

CPPFLAGS = -iquote include

CXX = g++

LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all :	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDLIBS)
	rm src/*.o

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all