FLAGS = -Wall -Wextra -Werror -Wuninitialized -std=c11 #-fsanitize=address
TESTFLAGS = -lcheck --coverage
# TESTFLAGS = -lcheck --coverage -rpath '/usr/local/lib'
SOURCES_FUN:=$(wildcard s21_*.c)

ifeq ($(shell uname), Linux)
TESTFLAGS += -lm -lsubunit
else
TESTFLAGS += -fprofile-arcs -ftest-coverage
endif

all: s21_matrix.a
	rm -rf *.o

s21_matrix.a:
	gcc $(FLAGS) -c $(SOURCES_FUN)
	ar rcs s21_matrix.a *.o


test: s21_matrix.a
	gcc *.c s21_matrix.a $(TESTFLAGS) -o test
	./test
	

gcov_report: clean s21_matrix.a
	gcc *.c s21_matrix.a $(TESTFLAGS) -o test
	./test
	lcov -t "gcov_report" -o gcov_report.info -c -d ./
	genhtml -o report gcov_report.info
	open report/index.html
	rm -rf *.o *.a  *.gch *.gcno test *.gcda

clang_fix:
	@clang-format --style=Google -i *.c *.h #test/*.c test/*.h

clang_check:
	@clang-format --style=Google -n *.c *.h #test/*.c test/*.h

clean:
	@rm -rf *.o testing.c testing *.a *.gcno *.gcda *.gcov *.info
	@rm -rf html_report s21_matrix.a s21_lib_test html_report
	@rm -rf report test