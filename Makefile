TARGET = ./main.out
HDRS_DIR = project/include

# XXX: Don't forget backslash at the end of any line except the last one
SRCS = \
       project/src/main.c \
       project/src/countingsort.c \
	   project/src/quicksort.c 

.PHONY: all build test clean

all: clean build test

$(TARGET): $(SRCS) 
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)

build: $(TARGET)

test: $(TARGET)
	$(TARGET)

clean:
	rm -rf $(TARGET)