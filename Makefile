TARGET = ./main.out
HDRS_DIR = project/include

SRCS = \
       project/src/main.c \
       project/src/countingsort.c \
       project/src/quicksort.c 

.PHONY: all build test clean

all: clean build

$(TARGET): $(SRCS) 
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(SRCS)

build: $(TARGET)

test: $(TARGET)
	$(TARGET)

clean:
	rm -rf $(TARGET)
