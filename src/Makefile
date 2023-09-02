CC = g++ -std=c++17
CFLAGS = -Wall -Werror -Wextra
OS := $(shell uname)

ifeq ($(OS),Linux)
TEST_FLAGS = -lgtest -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
else
TEST_FLAGS = -lgtest -lm -lpthread -fprofile-arcs -ftest-coverage
endif

all: test

gcov_report: test
	lcov -t "./unit_test"  -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html
	rm -rf *.gcno *gcda *.gco

style:
	@ cp ../materials/linters/.clang-format ./
	clang-format -n */*.cc */*.h */*.tpp
	@ rm -rf .clang-format

leak:
	leaks -atExit -- ./unit_test

test: clean
	$(CC) $(CFLAGS) ./tests/*.cc $(TEST_FLAGS) -o unit_test
	./unit_test

clean:
	@rm -rf *.o *.a unit_test
	@rm -rf *.gcno *gcda *.gcov gcov
	@rm -rf */*.gcno */*gcda */*.gcov
	@rm -rf report report.info
	@rm -rf *.dSYM */*.dSYM
