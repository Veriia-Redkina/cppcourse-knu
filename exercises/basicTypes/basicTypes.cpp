#include "PrintHelper.h"

/* *************************************
 * * Fundamental types and expressions *
 * *************************************
 *
 * Tasks:
 * ------
 * - Compile the program and analyse the output of the different expressions
 * - Discuss with other students or your tutor in case the result of an expression is a surprise
 * - Fix the marked expressions by changing types such that they produce meaningful results
 * - Answer the questions in the code
 */

int main() {
  std::cout << "Using literals of different number types:\n";
  print(5);
  print(5./2);           //FIXME 5 -> 5. (int -> double)
  print(100/2ull);
  print(2 + 4ull);
  print(2.f + 4ull);
  print(0 - 1);       // FIXME 0u - 1u -> 0 - 1 (При відніманні 0u - 1u ми отримаємо UINT_MAX, тобто максимальне значення unsigned int через переповнення.)
  print(1.0000000001L); // FIXME Why is this number not represented correctly? 1.0000000001f -> 1.0000000001L (1.0000000001f має 10 знаків після коми, але float зберігає менше значущих цифр; long double не може ідеально представити 1.0000000001 через обмеження двійкової системи)
  print(1.l + 1.E-18);   // FIXME 1. + 1.E-18 -> 1.l + 1.E-18 (1.E-18 є занадто малим у порівнянні з 1.0, і через обмежену точність double ця додаткова частина втрачається)

  std::cout << "\nUsing increment and decrement operators:\n";
  int a = 1;
  int b;
  int c;
  print(b = a++);       // Q: What is the difference between a++ and ++a? (`a++` повернуло старе значення `1`, але потім `a` стало `2`)
  print(c = ++a);                                                      // (`++a` спочатку збільшило `a` до `3`, а потім повернуло `3`)
  print(a);
  print(b);
  print(c);

  std::cout << "\nCompound assignment operators:\n";
  int n = 1;
  print(n *= 2);        // Q: Is there a difference between this and the next line? (Для розрахунку використовує int та виводить int)
  print(n *= 2.9);                                                               // (Для розрахунку n перетворюється на double але виводить int)    
  print(n -= 1.1f);
  print(n /= 4);        // Q: Based on the results of these expressions, is there a better type to be used for n? (Краще використати float)

  std::cout << "\nLogic expressions:\n";
  const bool alwaysTrue = true;
  bool condition1 = false;
  bool condition2 = true;
  print( alwaysTrue && condition1 && condition2 );
  print( alwaysTrue || condition1 && condition2 );  // Q: Why does operator precedence render this expression useless? (Оскільки alwaysTrue вже true, вираз завжди буде true, незалежно від condition1 та condition2)
  print( alwaysTrue && condition1 || condition2 );
  print(condition1 != condition1);                  // Q: What is the difference between this and the following expression? (Логічне порівняння (завжди false))
  print(condition2 = !condition2);                                                                                       // (Присвоєння інверсії змінній)
  print( alwaysTrue && condition1 && condition2 );
  print( alwaysTrue || condition1 && condition2 );
  print( alwaysTrue && condition1 || condition2 );

  std::cout << '\n';
  print( false || 0b10 );     // Q: What is the difference between || and | ? (Використовується для булевих виразів; true або false)
  print( false | 0b10 );                                                  //  (Виконує побітову операцію між числами)
  printBinary( 0b1 & 0b10 );
  printBinary( 0b1 | 0b10 );
  printBinary( 0b1 && 0b10 ); // Q: Are the operators && and || appropriate for integer types? (Ні. && і || працюють з цілими числами, але вони не виконують побітові операції)
  printBinary( 0b1 || 0b10 );

  std::cout << "\nPlay with characters and strings:\n";
  print("a");                 // Q: Why is this expression two bytes at run time, the next only one? ("a" — це рядок, що містить два байти: один для символа і один для термінатора)
  print('a');                                                                                     // ('a' — це один символ і займає лише один байт)

  char charArray[20];
  std::fill(std::begin(charArray), std::end(charArray), '\0');
  char* charPtr = charArray;
  // charArray[19] = 0; // Make sure that our string is terminated with the null byte (рядок 69)

  print(charArray);
  print(charArray[0] = 'a');
  print(charArray);
  print(charArray[1] = 98);
  print(charArray);
  print(charPtr);
  // FIXME: Ensure that no unexpected garbage is printed above (Щоб уникнути виводу "сміття", потрібно гарантувати, що рядок завершується термінатором '\0' перед його друком як в рядку 69)
}
