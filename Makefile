####################################
#
#		GLOBAL INFORMATIONS
#
####################################

NAME		= lunar.a
CC			= @gcc
CFLAGS		= -Wall -Wextra -Werror -Iincludes -Iincludes -O3
SRC_C	 	= $(wildcard src/**/*.c)
OBJ_C	 	= $(SRC_C:.c=.o)
NUM_CF		= $(shell ls -l src/**/*.c | wc -l)
cnt			= 1

##################################
#
#			COLOR
#
##################################

GREEN 	= \033[38;5;82m
RED   	= \033[38;5;196m
YELLOW 	= \033[38;5;226m
ORANGE	= \033[38;5;202m
PURPLE	= \033[38;5;207m
LBLUE	= \033[38;5;45m
BLUE	= \033[38;5;26m
RESET 	= \033[00m

##################################
#
#			DEBUG MODE
#
##################################

ifdef DEBUG
CFLAGS += -g3
endif

define ascii_art

.____                               
|    |    __ __  ____ _____ _______ 
|    |   |  |  \\/    \\\\__  \\_  __  \\
|    |___|  |  /   |  \\/ __ \|  | \\/
|_______ \\____/|___|  (____  /__|   
        \\/          \\/     \\/      

			Version : 0.0.1
			Author  : Unam3dd aka (sam0verfl0w)   


endef
export ascii_art

all: BANNER $(LIBFT) $(NAME)

BANNER:
	@printf "$(LBLUE)$$ascii_art$(RESET)"

%.o: %.c
	@printf "$(LBLUE)[$(PURPLE)+$(LBLUE)] compile $(GREEN)$<$(LBLUE) [$(GREEN)$(cnt)$(YELLOW)/$(NUM_CF)$(LBLUE)]     \r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval cnt=$(shell echo $$(($(cnt)+1))))

$(NAME): $(OBJ_C)
	@printf "\n"
	@ar rcs $(NAME) $(OBJ_C)

clean:
	@rm -rf $(OBJ_C)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean test re
