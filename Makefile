#
# Makefile
#

CC = x86_64-w64-mingw32-gcc
MENU = windres
CFLAGS = -Wall -O3 -std=c99 -pedantic-errors
#CFLAGS = -v -Wall -O3 -ansi -pedantic-errors
LDFLAGS = -mwindows
SRC = test2_sjis.c
BSRC = test2.c
OBJS = $(SRC:.c=.o)
RC = menu_sjis.rc
BRC = menu.rc
OBJS += $(RC:.rc=.o)
PROGRAM = test2.exe
RM = rm
NKF = nkf


%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.o: %.rc
	$(MENU) $(RC) $*.o

.PHONY: all
all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@


.PHONY: clean conv
clean:
	$(RM) $(OBJS)

conv:
	$(NKF) -s $(BSRC) > $(SRC)
	$(NKF) -s $(BRC) > $(RC)


