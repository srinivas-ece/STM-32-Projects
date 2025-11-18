CC      := gcc
CFLAGS  := -Wall -g

output  := out

source  := factorial.c main.c
object  := $(source:.c=.o)


$(output): $(object)
	$(CC) $(CFLAGS) -o $(output) $(object)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(output)
	./$(output)

clean:
	rm -f $(output) $(object)

