CC       := gcc
CFLAGS   := -Wall -g

output   := out
lib      := libparn.a

source   := main.c parn.c
object   := $(source:.c=.o)

all: $(output)

$(lib): parn.o
	ar rcs $(lib) parn.o

$(output): main.o $(lib)
	$(CC) $(CFLAGS) -o $(output) main.o -L. libparn.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(output)
	./$(output)

clean:
	rm -f $(output) $(object) $(lib)

