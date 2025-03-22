Cc = cc
Cflags = -Wall -Wextra -Werror
Name = libftprintf.a 

Src = ft_check_flag.c \
		ft_print_decimal.c \
		ft_print_number_hex.c \
		ft_print_pointer.c \
		ft_print_udecimal.c \
		ft_print_char.c \
		ft_printf.c \
		ft_print_percent.c \
		ft_print_string.c

Objc = $(Src:.c=.o)
Header = ft_printf.h

all: $(Name)

$(Name): $(Objc)
		ar rcs $(Name) $(Objc)

%.o: %.c $(Header)
	$(Cc) $(Cflags) -c $< -o $@

clean:
	rm -f $(Objc)

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re