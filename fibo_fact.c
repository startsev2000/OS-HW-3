#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
      fact *= i;
    }
    return fact;
}

long long fibonacci(int n) {
    if (n <= 1) {
      return n;
    }
    else {
      return (fibonacci(n - 1) + fibonacci(n - 2));
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Введите число в качестве аргумента командной строки\n");
        return 1;
    }
    int n = atoi(argv[1]);
    pid_t pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Ошибка при вызове fork()\n");
        return 1;
    } else if (pid == 0) {
        // дочерний процесс
        printf("Факториал числа %d равен %lld\n", n, factorial(n));
    } else {
        // родительский процесс
        printf("Число Фибоначчи, соответствующее числу %d, равно %lld\n", n, fibonacci(n));
    }
    return 0;
}

