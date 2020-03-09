# set suffix list, to prevent confusion between different make programs
# line 3 clears an implied suffix list, and line 4 sets a new one
.SUFFIXES:
.SUFFIXES: .cpp .h .o

PROJECT_ROOT = $(subst /,\, $(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
# project set up and directories
BINDIR	= bin
SRC=src
TGT=obj
INCLUDES = -Iinclude
CXXFLAGS = -Wall -std=c++11 $(INCLUDES)

SOURCES = $(wildcard $(SRC)/*.cpp)
OBJS = $(addprefix $(TGT)/, $(notdir $(SOURCES:.cpp=.o)))
WINOBJS = $(addprefix $(PROJECT_ROOT)$(TGT)\, $(notdir $(SOURCES:.cpp=.o)))
LIBS =
LDFLAGS =
# final executable name
_BIN = fractions_demo.exe
BIN	= $(addprefix $(BINDIR)/, $(_BIN))
WINBIN	= $(addprefix $(PROJECT_ROOT)$(BINDIR)\, $(_BIN))
# compile binary and object files
.PHONY: all
all: $(BIN)

$(BIN): $(BINDIR) $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) $(LIBS) -o $@

$(BINDIR):
	mkdir $(BINDIR)

$(TGT)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)
	
clean:
	del $(WINOBJS) $(WINBIN)

