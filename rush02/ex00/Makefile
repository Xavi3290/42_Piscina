# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfontenl <pfontenl@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 18:13:35 by pfontenl          #+#    #+#              #
#    Updated: 2023/08/27 18:14:52 by pfontenl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
SOURCES = main.c dict_utils.c file_utils.c num_utils.c trim_utils.c
FLAGS = -Wall -Wextra -Werror
OBJECTS = ${SOURCES:.c=.o}
all: ${NAME}
${NAME}: ${OBJECTS}
	cc ${FLAGS} -o ${NAME} ${OBJECTS}
%.o: %.c
	cc ${FLAGS} -c $< -o $@
clean:
	rm -f ${OBJECTS}
fclean: clean
	rm -f ${NAME}
.PHONY: all clean fclean
