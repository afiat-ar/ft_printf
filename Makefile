NAME = libftprintf.a
CC = clang
CFLAGS += -Wall -Werror -Wextra
OBJDIR = obj
SRCDIR = srcs
FLAGDIR = flags
LIBDIR	= libft
INCDIR	= $(LIBDIR)
HEAD	= $(SRCDIR)/ft_printf.h

SRCS =	$(LIBDIR)/ft_atoi.c					\
		$(LIBDIR)/ft_itoa.c					\
		$(LIBDIR)/ft_bzero.c				\
		$(LIBDIR)/ft_itoa.c					\
		$(LIBDIR)/ft_memset.c				\
		$(LIBDIR)/ft_putchar_fd.c			\
		$(LIBDIR)/ft_strchr.c				\
		$(LIBDIR)/ft_strdup.c				\
		$(LIBDIR)/ft_strjoin.c				\
		$(LIBDIR)/ft_strlen.c				\
		$(LIBDIR)/ft_tolower.c				\
		$(LIBDIR)/ft_isalpha.c				\
		$(LIBDIR)/ft_toupper.c				\
		$(LIBDIR)/ft_putnbr_fd.c			\
		$(LIBDIR)/ft_isdigit.c				\
		$(LIBDIR)/ft_putstr_fd.c			\
		ft_printf.c							\
		ft_check_flags.c					\
		ft_type_out.c						\
		ft_putchar_tab.c					\
		ft_putstr_tab.c						\
		ft_putnbr_tab.c						\
		ft_puthexa_tab.c					\
		ft_utils.c							\
		
CFLAGS += -I$(INCDIR)
OBJ = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
LIB		= $(LIBDIR)/libft.a

_GREEN=\e[32m
_YELLOW=\e[33m
_CYAN=\e[36m
_END=\e[0m

all: $(NAME)

$(NAME): $(OBJ)
	@printf "Compilation OK! "
	@ar rcs $@ $^
	@printf "[$(_GREEN)✓$(_END)]\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
	@printf "Sources : "
	@$(CC) -c $< -o $@
	@printf "$(_CYAN)$<\n$(_END)"
$(OBJDIR)/$(LIBDIR)/%.o: $(LIBDIR)/%.c $(HEAD)
	@printf "Libft : "
	@$(CC) -c $< -o $@
	@printf "$(_YELLOW)$<\n$(_END)"

$(OBJDIR) :
	@mkdir $@ $@/$(LIBDIR)

$(OBJ) : | $(OBJDIR)

clean:
	@printf "clean... "
	@rm -rf $(OBJDIR)
	@printf "[$(_YELLOW)✓$(_END)]\n"

fclean: clean
	@printf "fclean... "
	@rm -rf $(NAME)
	@printf "[$(_BLUE)✓$(_END)]\n"

re: fclean all clean

.PHONY: clean fclean all re