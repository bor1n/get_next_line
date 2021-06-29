NAME 	= get_next_line

SRCS	=   get_next_line.c get_next_line_utils.c
SRCS_B	=

OBJS	= $(patsubst %.c,%.o,$(SRCS))
OBJS_B  = $(patsubst %.c,%.o,$(SRCS_B))

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

all:	$(NAME)

%.o : %.c 	get_next_line.h
	gcc $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	ar rcs $(NAME) $?

bonus:
	@make OBJS="$(OBJS_B)" all

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
