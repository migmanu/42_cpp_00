OBJS = main.cpp Contact.cpp PhoneBook.cpp utils.cpp

CC = c++

COMPILER_FLAGS = -Werror -Wextra -Wall -std=c++98 -g

LINKER_FLAGS = 

OBJ_NAME = phonebook

$(OBJ_NAME) : $(OBJS)
	@$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean : 
	@rm $(OBJ_NAME)
