##
## Makefile for zada in /home/debrau_c/bin/new_repo_cpp
##
## Made by debrau_c
## Login   <debrau_c@epitech.net>
##
## Started on  Mon May  2 11:14:22 2016 debrau_c
## Last update Fri May 26 00:39:40 2017 debrau_c
##

NAME_LIB	= Gui.a

NAME_EX		= a.out

CC = g++

SRC_LIB	= src/Bank.cpp	\
					src/Object.cpp		\
					src/Box.cpp				\
					src/BoxClosable.cpp				\
					src/BoxScrollable.cpp				\
					src/Label.cpp			\
					src/LabelImg.cpp			\
					src/LabelTxt.cpp			\
					src/Button.cpp			\
					src/Input.cpp


SRC_EX	= example/main.cpp

CXXFLAGS	= -Iinc/ -Wall -std=gnu++11


OBJ_EX	= $(SRC_EX:.cpp=.o)

OBJ_LIB	= $(SRC_LIB:.cpp=.o)

LIB     = -lsfml-graphics       \
          -lsfml-window         \
          -lsfml-system

AR	= ar

$(NAME_LIB):	$(OBJ_LIB)
	$(AR) rvs $(NAME_LIB) $(OBJ_LIB)

$(NAME_EX): $(OBJ_EX)
	$(CC) -g -o $(NAME_EX) $(OBJ_EX) $(NAME_LIB) $(LIB)

all:	lib ex

lib:	$(NAME_LIB)

ex:	$(NAME_EX)

clean:
	$(RM) $(OBJ_LIB)
	$(RM) $(OBJ_EX)

fclean:	clean
	$(RM) $(NAME_LIB)
	$(RM) $(NAME_EX)

re:	fclean all

.PHONY: all fclean re clean
