#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include "Complex.hpp"

template<typename T>
void compute(int len, T initial, T step) {
    //  Створення вектора значень та вектора різниць
    std::vector<T> v(len + 1), diffs(len);
    // Заповнення v рівномірною послідовністю: v[i] = initial + i * step
    std::generate(v.begin(), v.end(), [i = 0, initial, step]() mutable {
        return initial + step * i++;
    });

    // Перемішування вектора
    std::shuffle(v.begin(), v.end(), std::default_random_engine{});

    // Обчислення різниць між сусідніми елементами
    std::adjacent_difference(v.begin(), v.end(), diffs.begin());
    diffs.erase(diffs.begin());  // перше значення — просто копія v[0], тому видаляємо

    // Обчислення суми різниць
    const T sum = std::reduce(diffs.begin(), diffs.end());

    // Обчислення суми квадратів різниць (для дисперсії)
    const T sumsq = std::accumulate(diffs.begin(), diffs.end(), T{}, [](const T& acc, const T& x) {
        return acc + x * x;
    });
//Середнє значення і дисперсія
    const T mean = sum / len;
    const T variance = sumsq / len - mean * mean;

    //  Виведення результатів
    std::cout << "Range = [" << initial << ", " << step * len << "]\n"
              << "Mean = " << mean << '\n'
              << "Variance = " << variance << "\n\n";
}


int main() {
    compute(1000, 0.0f, 7.0f);
    // call compute here with Complex
    compute(1000, Complex{0.0, 0.0}, Complex{7.0, 0.0});
}

/*
Працює:
Range = [0, 7000]
Mean = -2.478
Variance = 8.14289e+06

Range = [(0, 0), (7000, 0)]
Mean = (-2.478, 0)
Variance = (8.14289e+06, 0)
*/