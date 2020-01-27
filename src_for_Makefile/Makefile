# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/30 19:50:43 by jchiang-          #+#    #+#              #
#    Updated: 2020/01/26 21:56:04 by mbutt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC:=\033[0m
GREEN:=\033[1;32m

NAME = ft_gkrellm

CFLAG = -std=c++98 -Wall -Wextra -Werror -lncurses 

INC = -I includes -I ./SFML/include

SRC =  src/src_class/*.cpp

FRAMEWORK = -lncurses -framework sfml-graphics -framework sfml-window -framework sfml-system -F SFML/Frameworks

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(CFLAG) $(INC) $(SRC) $(FRAMEWORK) -o $(NAME)
	touch ft_gkrellmT
	touch ft_gkrellmG
	echo "DYLD_FRAMEWORK_PATH=`pwd`"/SFML/Frameworks" ./ft_gkrellm Text" >> ft_gkrellmT
	echo "DYLD_FRAMEWORK_PATH=`pwd`"/SFML/Frameworks" ./ft_gkrellm Graph" >> ft_gkrellmG
	chmod 777 ft_gkrellmT
	chmod 777 ft_gkrellmG
	@echo "${GREEN}Generated program ft_gkrellmT & ft_gkrellmG succesfully.${NC}"


$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	mkdir -p obj
	clang++ -c $(CFLAG) $(INC) $< -o $@

clean:
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf ft_gkrellmT
	/bin/rm -rf ft_gkrellmG

re: fclean all

.PHONY: all, clean, fclean, re
