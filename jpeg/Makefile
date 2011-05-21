# 2010.2.22

#DIR = ./out/
#TAR_DIR = ./out/

src = $(wildcard *.c)
obj = $(patsubst %.c, $(DIR)%.o, $(src))
target = $(TAR_DIR)main

CC = gcc
#CC = arm-linux-gcc
CFLAGS = -Wall -g -c -I../jpeg-8/
LDFLAGS = -L../jpeg-8/.libs/ -ljpeg 

all: $(target)

$(target): $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)
$(DIR)%.o:%.c
	$(CC) -o $@ $(CFLAGS) $< 

clean:
	-rm -f $(target)
	-rm -f $(obj)
	-rm -f *~

.PHONY: clean
test:
	@echo $(src)
	@echo $(obj)
