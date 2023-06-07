# Отчёт по ДЗ №3.
## Старцев Евгений Борисович, БПИ219

### Задание:

Разработать программу, в которой родительский процесс вычисляет число Фибоначчи, а процесс-ребенок вычисляет значение факториала. В качестве исходного значения используется аргумент из командной строки. Процессы создаются при помощи fork() внутри программы.

### Инструкция по запуску:

Скомпилируйте программу с помощью следующей команды:

```
gcc -o fib_fact fib_fact.c
```
Запустите программу с помощью следующей команды:

```
./fib_fact 10
```

Здесь число 10 - это аргумент командной строки, который будет использоваться для вычисления факториала и числа Фибоначчи. Вы можете заменить его на любое другое целое число.

### Описание работы программы:

Программа получает целое число в качестве аргумента командной строки и производит две операции над этим числом: вычисление факториала и числа Фибоначчи.

Функция factorial() вычисляет факториал данного числа, используя простой цикл for. Функция fibonacci() вычисляет число Фибоначчи, используя рекурсивный подход.

В главной функции main() сначала проверяется наличие аргумента командной строки. Если аргумент не предоставлен, программа выводит сообщение об ошибке и завершает работу.

После получения аргумента командной строки программа создает дочерний процесс с помощью функции fork(). Если функция fork() возвращает отрицательное значение, это означает, что произошла ошибка, и программа выводит сообщение об ошибке и завершает работу.

Если значение pid, возвращаемое функцией fork(), равно нулю, программа находится в дочернем процессе и вызывает функцию factorial() для вычисления факториала числа.

Если значение pid больше нуля, программа находится в родительском процессе и вызывает функцию fibonacci() для вычисления числа Фибоначчи.
