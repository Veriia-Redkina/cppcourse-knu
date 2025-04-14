#include <algorithm>
#include <iostream>

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void reverse(int* v, unsigned int len)
{
    for (unsigned int i = 0; i < (len + 1) / 2; i++) {
        const int a = i;
        const int b = len - 1 - i;

        swap(v + a, v + b);
    }
}

int* createAndFillVector(unsigned int len)
{
    auto v = new int[len];
    for (unsigned int i = 0; i < len; i++) {
        v[i] = i;
    }
    return v;
}

int main()
{
    constexpr auto arraySize = 100;
    int* v = nullptr;
    // create and reverse the vector of LEN numbers
    v = createAndFillVector(arraySize);
    reverse(v, arraySize);

    // check if the revert worked:
    const bool isReversed = std::is_sorted(v, v + arraySize, std::greater {});
    std::cout << "Vector reversed successfully: " << std::boolalpha
              << isReversed << "\n";

    return isReversed ? 0 : 1;
}

/*
Було виконано компіляцію (g++ -g -o debug debug.cpp) та запуск програми (./debug).
В результаті в терміналі було записано про помилку Помилка адресування (збережено знімок оперативної пам’яті)
Для перевірки помилки було запущено gdb ./debug

Reading symbols from ./debug...
(gdb) run
Program received signal SIGSEGV, Segmentation fault.
0x000055555555523d in swap (a=0x0, b=0xf9c) at debug.cpp:6
6           int c = *a;
(gdb) backtrace
#0  0x000055555555523d in swap (a=0x0, b=0xf9c) at debug.cpp:6
#1  0x00005555555552bb in reverse (v=0x0, len=1000) at debug.cpp:17
#2  0x0000555555555364 in main () at debug.cpp:35

Виклик функції reverse(v, 1000) призведе до аварійного завершення програми, оскільки звертається до пам'яті через вказівник, який не вказує на жодну область пам'яті
Виклик функції reverse до того, як ініціалізується v, є помилкою, бо немає значення в векторі, щоб його перевертати

Після виправленьмаємо (./debug):
Reading symbols from ./debug...
(gdb) run
Vector reversed successfully: true
[Inferior 1 (process 167255) exited normally]
(gdb) backtrace
No stack.
*/