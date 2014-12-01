# the compiler: gcc for C program, define as g++ for C++
CC = gcc
# compiler flags:
  #  -g        adds debugging information to the executable file
  #  -Wall     turns on most, but not all, compiler warnings
  #  -std      Determine the language standard.  use 'c99' or 'c11' for C || use 'c++11' or 'c++14' for C++
  #  -O*       Optimization purposes: https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
  #  -Werror   Make all warnings into errors
  #  -pedantic Issue all the warnings demanded by strict ISO C and ISO C++; reject all programs that use forbidden extensions, and some other programs that do not follow ISO C and ISO C++
  #  -Wextra   This enables some extra warning flags that are not enabled by -Wall
  #  -Wshadow  Warn whenever a local variable or type declaration shadows another variable, parameter, type, class member (in C++), or instance variable (in Objective-C) or whenever a built-in function is shadowed
  #  -Weffc++  enables warnings for constructs that violate guidelines in Effective C++: http://cpptruths.blogspot.nl/2006/08/g-compiler-option-weffc.html
CFLAGS = -O0 -g -std=c99 -Wall -Wextra -Wshadow -pedantic -Werror
CXXFLAGS = -O0 -g -std=c++11 -Wall -Wextra -Wshadow -pedantic -Weffc++ -Werror
# define any directories containing header files other than /usr/include
#
INCLUDES = 

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = 

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = 

# define the C source files
SRCS = main.c helperFuncs.c stanfordProblems.c appendNode.c copyLinkedList.c buildAtTail.c

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

# define the executable file 
MAIN = linkedListExe

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all: $(MAIN)
	@echo  linkedListExe has been compiled

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it

# Tutorial: http://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html