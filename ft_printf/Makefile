NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT = libft.a

GCCF = gcc -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -rf

SRCS =		ft_printf.c

BONUS =ft_printf_bonus.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(OBJSB)
	@$(LIB) $(NAME) $(OBJS) $(OBJSB)

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) $(NAME)

bonus: ${OBJSB}
		@${LIB} ${NAME} ${OBJSB}

.c.o:
	$(GCCF) -c $< -o $(<:.c=.o)

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(LIBFT_DIR)/$(LIBFT)
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY = all clean fclean re test norm