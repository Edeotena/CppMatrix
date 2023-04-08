CC = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra -pedantic -g
VALGRIND_FLAGS = --log-file="$(VALGRIND_OUTPUT)" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med

DELETE = rm -rf

VALGRIND_OUTPUT = valgrind.txt
LIB = s21_matrix_oop.a

TEST_TARGET  = s21_test
EXECUTABLE = s21_main

SRC_FILES = lib/*.cc -I .
TEST_FILES = tests/*.cc

all: test clean $(LIB)

build_test: style
	$(CC) $(FLAGS) $(SRC_FILES) $(TEST_FILES) -o $(TEST_TARGET)

$(LIB): style
	$(CC) $(FLAGS) -c $(SRC_FILES)
	ar rcv $(LIB) *.o
	ranlib $(LIB)
	rm *.o

test: build_test
	./$(TEST_TARGET)

build: style
	$(CC) $(FLAGS) $(SRC_FILES) main.cc -o $(EXECUTABLE)

run: build
	./$(EXECUTABLE)

clean:
	$(DELETE) $(TEST_TARGET)
	$(DELETE) $(EXECUTABLE)
	$(DELETE) *.o
	$(DELETE) $(VALGRIND_OUTPUT)
	$(DELETE) .clang-format

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem .

style:
	cp ../materials/linters/.clang-format .
	clang-format -i $(wildcard */*.cc *.cc */*.h *.h);
	rm -f .clang-format

valgrind: style build
	valgrind $(VALGRIND_FLAGS) ./$(EXECUTABLE)
	grep --color=always -n "ERROR SUMMARY" $(VALGRIND_OUTPUT) | grep -v "0 errors from 0 contexts" || true
	grep --color=always -n "definitely lost:" $(VALGRIND_OUTPUT) | grep -v "0 bytes in 0 blocks" || true

valgrind_tests: style build_test
	valgrind $(VALGRIND_FLAGS) ./$(TEST_TARGET)
	grep --color=always -n "ERROR SUMMARY" $(VALGRIND_OUTPUT) | grep -v "0 errors from 0 contexts" || true
	grep --color=always -n "definitely lost:" $(VALGRIND_OUTPUT) | grep -v "0 bytes in 0 blocks" || true
