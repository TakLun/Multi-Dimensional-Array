#Configurations
GCC	= g++
FLAGS	= -g -std=c++14 
WRNG	= -Wall -Wextra -pedantic
OPTMZE	= -O2
HEADERS	= Array.hpp

#BUILD
all: test_Array_lite_warning

test_Array_warning: 
	$(GCC) $(WRNG) $(FLAGS) test_Array.cpp-o $@.exe

test_Array2_warning: 
	$(GCC) $(WRNG) $(FLAGS) test_Array2.cpp -o $@.exe

test_Array_lite_warning: 
	$(GCC) $(WRNG) $(FLAGS) test_Array_lite.cpp -o $@.exe

test_Array: 
	$(GCC) $(FLAGS) $@.cpp -o $@.exe

test_Array2: 
	$(GCC) $(FLAGS) $@.cpp -o $@.exe

test_Array_lite: 
	$(GCC) $(FLAGS) $@.cpp -o $@.exe

clean:
	rm -f *.o *~ *.exe