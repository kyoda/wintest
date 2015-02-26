#
# Makefile
#

CC = x86_64-w64-mingw32-gcc
MENU = windres
CFLAGS = -Wall -O3 -std=c99 -pedantic-errors -finput-charset=cp932 -fexec-charset=cp932
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
SED=sed 's/\\/\\\\/'



%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.o: %.rc
	$(SED) $(RC) | $(MENU) -o $*.o

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


