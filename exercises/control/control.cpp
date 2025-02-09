#include <iostream>

const unsigned int numbers[]{1000001, 1000002, 1000003, 1000004, 1000005, 1000006, 1000007, 1000008, 1000009};

bool isodd(unsigned int i) { return i % 2 == 1; }

void part1() {
  unsigned int sum_odd = 0;
  unsigned int sum_eve = 0;
//  for (int i = 0; i < 9; ++i) {      
//    unsigned int num = numbers[i];   // Заміняємо C++98-стиль 
  for (unsigned int num : numbers) {   // на range-based for-цикл
//    if (isodd(num)) {
//      sum_odd += num;
//    } else {
//      sum_eve += num;
//    }
    isodd(num) ? sum_odd += num : sum_eve += num;  // Заміняємо на функцію isodd та оператор (?:)
  }
  std::cout << "Sums: odd = " << sum_odd << ", even = " << sum_eve << "\n";
}

void part2() {
  // print smallest n for which 1 + 2 + ... + n > 10000
  int sum = 0;
//  for (int i = 1; ; i++) {
//    sum += i;
//    if (sum > 10000) {
//      std::cout << i << "\n";
//      break;
//    }
//  }
  int i = 1;
  while (sum <= 10000) {
    sum += i;
    i++;
  }
  std::cout << i - 1 << "\n";
}

void part2do() {
  // print smallest n for which 1 + 2 + ... + n > 10000
  int sum = 0;
  int i = 1;
  do {
    sum += i;
    i++;
  } while (sum <= 10000);
  std::cout << i - 1 << "\n";
}

enum class Language { English, French, German, Italian, Other };

void part3(Language l) {
//  if (l == Language::English) {
//    std::cout << "Hello\n";
//  } else if (l == Language::French) {
//    std::cout << "Salut\n";
//  } else if (l == Language::German) {
//    std::cout << "Hallo\n";
//  } else if (l == Language::Italian) {
//    std::cout << "Ciao\n";
//  } else {
//    std::cout << "I don't speak your language\n";
//  }

  switch (l) {
    case Language::English: std::cout << "Hello\n"; break;
    case Language::French:  std::cout << "Salut\n"; break;
    case Language::German:  std::cout << "Hallo\n"; break;
    case Language::Italian: std::cout << "Ciao\n"; break;
    default: std::cout << "I don't speak your language\n";
  }  
}

int main() {
  part1();
  part2();
  part2do();
  part3(Language::English);
  return 0;
}
