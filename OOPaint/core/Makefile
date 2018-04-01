# Shell commands
CP		= cp
CPP		= g++
MKDIR		= mkdir -p
RMDIR		= rm -rf

# Directories and names
TARGET 		= OOPaint
ROOT_DIR	= ../
SRC_DIRS 	= .
INSTALL_DIR	= $(ROOT_DIR)/install

# Sources and artefacts
SRCS		= $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS		= $(addsuffix .o,$(basename $(SRCS)))

# Flags
INCFLAGS	= -I../inc
CPPFLAGS	= -std=c++11 -g -o0 -Wall -Wextra -Weffc++ -pedantic $(INCFLAGS) -rdynamic
LDLIBS		= -ldl -lrt -lSDL2

# Recipies
$(TARGET): $(SRCS)
	$(CPP) $(CPPFLAGS) $(SRCS) -o $@ $(LDLIBS)

.PHONY: clean all install run
clean:
	$(RM) $(TARGET) $(OBJS)

all:		$(TARGET)

install:	all
	$(MKDIR) $(INSTALL_DIR)
	$(CP) $(TARGET) $(INSTALL_DIR)

uninstall:
	$(RMDIR) $(INSTALL_DIR)

run:		install
	$(INSTALL_DIR)/$(TARGET)

