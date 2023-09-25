CC = gcc
CFLAGS = -Wall

TARGET = Lab_5
SRC = Lab_5.c

all: $(TARGET)

$(TARGET): $(SRC)
  $(CC) $(CFLAGS) -O $(TARGET) $(SRC)

clean:
  rm -f $(TARGET)
