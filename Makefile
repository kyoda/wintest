#
# Makefile
#

CC = x86_64-w64-mingw32-gcc
PROGRAM = test2.exe
CFLAGS = -Wall -O3 -std=c99 -pedantic-errors -mwindows
#CFLAGS = -v -Wall -O3 -ansi -pedantic-errors -mwindows
SOURCE = test2.c
TARGET = test2_sjis.c
.PHONY: clean conv

$(PROGRAM): $(TARGET)
	$(CC) $(CFLAGS) -o $(PROGRAM) $^

clean:
	rm $(PROGRAM)

conv:
	nkf -s $(SOURCE) > $(TARGET)


