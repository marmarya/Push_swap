NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= ${shell find "./Srcs" -name "*.c"}
OBJS	= ${SRCS:.c=.o}
RM		= rm -rf
AR		= ar csr
LIBFT	= ./Libft/libft.a


.c.o :
	@${CC} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	@$(MAKE) -C ./Libft
	@cp $(LIBFT) ${NAME}
	@${CC} libft.a ${OBJS} -o ${NAME}

all : ${NAME}

compile : all 
	@${CC} ${NAME} libft.a -o ${NAME}

clean : 
	@$(MAKE) clean -C ./Libft
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME} a.out

re : fclean all

.PHONY: all clean fclean re .c.o