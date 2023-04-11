CC = g++ -std=c++17 -Wall -Werror -Wextra -Wuninitialized -Wsign-conversion -Wshadow -Weffc++ -pedantic -g -I .
DELETE = rm -rf
TEST_FLAGS =  -lgtest

FIND_VALGRIND_ERRORS = grep --color=always -n "ERROR SUMMARY" $(VALGRIND_OUTPUT) | grep -v "0 errors from 0 contexts" || true
FIND_VALGRIND_LEAKS = grep --color=always -n "definitely lost:" $(VALGRIND_OUTPUT) | grep -v "0 bytes in 0 blocks" || true
VALGRIND = valgrind --log-file="$(VALGRIND_OUTPUT)" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med

VALGRIND_OUTPUT = valgrind.txt
LIB = s21_matrix_oop.a

TEST_TARGET  = s21_tests

SRC_LIB = ./lib/
BUILD_PATH = ./build/

SRC_LIB_FILES = $(wildcard $(SRC_LIB)*.cc)
TEST_FILES = s21_tests.cc

SRC_LIB_OBJ = $(patsubst $(SRC_LIB)%.cc, $(BUILD_PATH)%.o, $(SRC_LIB_FILES))
TEST_OBJ = $(BUILD_PATH)s21_tests.o

all: test

$(BUILD_PATH):
	mkdir $(BUILD_PATH)

$(TEST_TARGET): $(LIB) $(TEST_OBJ)
	$(CC) $(TEST_OBJ) $(LIB) -o $(TEST_TARGET) $(TEST_FLAGS)

$(BUILD_PATH)%.o: $(SRC_LIB)%.cc
	$(CC) -c $< -o $@

$(TEST_OBJ) : $(TEST_FILES)
	$(CC) -c $(TEST_FILES) -o $(TEST_OBJ)

$(LIB): $(BUILD_PATH) style $(SRC_LIB_OBJ)
	ar rcv $(LIB) $(SRC_LIB_OBJ)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	$(DELETE) $(TEST_TARGET) *.o $(BUILD_PATH) $(VALGRIND_OUTPUT) $(LIB)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem .

style:
	clang-format --style=Google -i $(wildcard */*.cc *.cc */*.h *.h)

valgrind: $(TEST_TARGET)
	$(VALGRIND) ./$(TEST_TARGET) || true
	$(FIND_VALGRIND_ERRORS)
	$(FIND_VALGRIND_LEAKS)
