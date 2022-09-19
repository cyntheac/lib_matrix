CC =gcc
FLAG_C = -c
FLAG_O = -o
CFLAGS =-Wall -Werror -Wextra -pedantic -std=c11
GCOVF =-fprofile-arcs -ftest-coverage

all: s21_gcov_matrix.a test gcov_report
# all: gcov_report

clean:
	rm -rf *.o *.a test *.out *.gcda *.gcno *.html *.css tests_s21_matrix.c

rebuild: clean all

test: s21_gcov_matrix.a tests_s21_matrix.c
	$(CC) $(CFLAGS) $(GCOVF) -lcheck $? $(FLAG_O) $@

tests_s21_matrix.c:
	checkmk tests_s21_matrix > $@

s21_gcov_matrix.a: s21_*.c
	$(CC) $(CFLAGS) $(GCOVF) $(FLAG_C) $?
	ar -rcs $@ *.o
	rm -f *.o

s21_matrix.a: s21_*.c
	$(CC) $(FLAG_C) $(CFLAGS) $?
	ar -rcs $@ *.o
	rm -f *.o

gcov_report: test
	./$?
	gcovr -r . --html --html-details $(FLAG_O) coverage_report.html
	rm -f *.gcda *.gcno
	open coverage_report.html

# Предусмотреть Makefile для сборки библиотеки и тестов
# (с целями all, clean, test, s21_matrix.a, gcov_report)
# В цели gcov_report должен формироваться отчёт gcov в виде html страницы. Для этого unit-тесты должны запускаться с флагами gcov
# Проверяемая точность дробной части - максимум 6 знаков после запятой.