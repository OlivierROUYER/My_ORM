CXX	=	g++

CXXFLAGS =	-Wall -Wextra -Wpedantic -Werror -std=c++14

CONNFLAGS = -lmysqlcppconn

NAME	=	exec

SRC	=	MyORM.cpp			\
			usage.cpp

OBJ	= 	$(SRC:%.cpp=%.o)

RM	=	rm -f

$(NAME)	:	$(OBJ)
			$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) $(CONNFLAGS)

all		:	$(NAME)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
