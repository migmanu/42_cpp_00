CFLAGS = -Werror -Wextra -Wall -std=c++98 -g
CC = c++
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = megaphone

# Default rule
all: $(EXEC)

# Rule to create the executable
$(EXEC): $(OBJS)
	@$(CC) -o $@ $^

# Rule to create object files
%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean object files
clean:
	@rm -f $(OBJS)

# Rule to clean everything
fclean: clean
	@rm -f $(EXEC)

# Rule to recompile everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
