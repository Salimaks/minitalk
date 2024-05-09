SOURCES_SERVER = sources/server.c
SOURCES_CLIENT = sources/client.c

OBJECTS_SERVER = $(SOURCES_SERVER:.c=.o)
OBJECTS_CLIENT = $(SOURCES_CLIENT:.c=.o)


CC = cc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: $(OBJECTS_SERVER) 
	make -C libft
	make -C ft_printf
	$(CC) $(OBJECTS_SERVER) libft/libft.a ft_printf/libftprintf.a -o server


client: $(OBJECTS_CLIENT) 
	make -C libft
	make -C ft_printf
	$(CC) $(OBJECTS_CLIENT) libft/libft.a ft_printf/libftprintf.a -o client


.c.o:
	$(CC) $(FLAGS) -I ./include -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJECTS_SERVER)
	rm -f $(OBJECTS_CLIENT)
	make clean -C libft
	make clean -C ft_printf

	
fclean: clean
	rm -f server client libft/libft.a ft_printf/ft_printf.a

re: fclean all

.PHONY: all bonus clean fclean re