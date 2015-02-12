#
# Makefile
#

CC = x86_64-w64-mingw32-gcc
PROGRAM = test2.exe
CFLAGS = -Wall -O3 -std=c99 -mwindows
SOURCE = test2.c
TARGET = test2_sjis.c
.PHONY: clean

$(PROGRAM): $(TARGET)
	$(CC) $(CFLAGS) -o $(PROGRAM) $^
	#gcc -Wall -O2 -std=c99 -o $@ $^

clean:
	rm $(PROGRAM)

ls:
	ls -l $(PROGRAM) $(SOURCE)

conv:
	nkf -s $(SOURCE) > $(TARGET)

