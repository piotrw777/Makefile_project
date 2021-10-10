TARGET = libperson.so
DEPS = ../libstars/libstars.so ../libbase/libbase.a
CC = gcc
INC = -I./
CFLAGS = -g -Wall -Wextra -std=c11 -DCONFIG=$(CONFIG) 
LDFLAGS =
CONFIG = DEFAULT
END_ACTION = add_lib_to_system

include ../build.mk

add_lib_to_system: $(TARGET)
	sudo cp $(TARGET) /usr/lib/
	sudo ldconfig
