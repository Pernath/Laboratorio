CXX?=clang++
EXE=compiler
CXXDEBUG= -g -Wall
CXXSTD=-std=c++17
CXXFLAGS= -Wno-deprecated-register -O0 $(CXXDEBUG) $(CXXSTD)

CPPOBJ= main Lexer

FILES= $(addsuffix .cpp, $(CPPOBJ))
OBJS = $(addsuffix .o, $(CPPOBJ))

CLEANLIST = $(OBJS) $(EXE)


.PHONY: all
all: wc

wc: $(FILES)
	$(MAKE) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS)

.PHONY: test
test:
	cd test && ./compler grammar

.PHONY: clean
clean:
	rm -rf $(CLEANLIST)
