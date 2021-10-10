TARGET = libstars.so
DEPS =
CC = gcc
INC = -I./
CONFIG = WIN11
CFLAGS = -g -Wall -Wextra -std=c11 -DCONFIG=$(CONFIG) 
LDFLAGS =
END_ACTION = add_lib_to_system

include ../build.mk

add_lib_to_system: $(TARGET)
	sudo cp $(TARGET) /usr/lib/
	sudo ldconfig
