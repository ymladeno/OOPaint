# Shell commands
CP		= cp
CPP		= g++
MKDIR	= mkdir -p
RM		= rm -f

# Directories and names
TARGET 		= basic_shapes.so
ROOT_DIR	= ../../
SRC_DIRS 	= .
INSTALL_DIR	= $(ROOT_DIR)/install/plugins

# Sources and artefacts
SRCS		= $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS		= $(addsuffix .o,$(basename $(SRCS)))

# Flags
INCFLAGS	= -I../../inc
CPPFLAGS	= -std=c++11 -c -g -Wall -Wextra -pedantic $(INCFLAGS) -fPIC
LDFLAGS		= -shared
LDLIBS		= -ldl -lrt -lSDL2

# Recipies
$(OBJS):	$(SRCS)
	$(CPP) $(CPPFLAGS) $(SRCS)
	
$(TARGET): $(OBJS)
	$(CPP) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

.PHONY: clean all install
clean:
	$(RM) $(TARGET) $(OBJS)

all:		$(TARGET)

install:	all
	$(MKDIR) $(INSTALL_DIR)
	$(CP) $(TARGET) $(INSTALL_DIR)

uninstall:
	$(RM) $(INSTALL_DIR)/$(TARGET)
