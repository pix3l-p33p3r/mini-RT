# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 15:50:18 by elel-yak          #+#    #+#              #
#    Updated: 2023/12/27 16:44:15 by elel-yak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

BNAME = miniRTbonus

all: $(NAME)

$(NAME):
	make -C mandatory/
	cp mandatory/miniRT .

bonus: $(BNAME)

$(BNAME):
	make -C bonus/
	cp bonus/miniRTbonus .


clean:
	make clean -C mandatory/
	make clean -C bonus/

fclean : clean
	make fclean -C mandatory/
	make fclean -C bonus/
	rm -rf $(NAME)
	rm -rf $(BNAME)

re: fclean all

.PHONY: clean fclean all re
