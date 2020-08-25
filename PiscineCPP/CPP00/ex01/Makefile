NAME = PhoneBook

SRCS = ClassContact.cpp \
		ClassRepo.cpp \
		main.cpp
OBJS = $(SRCS:.pp=.o)

CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(NAME)

fclean : clean

re: fclean all

.PHONY: clean all fclean re
