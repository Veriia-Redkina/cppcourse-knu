#include <iostream>
#include <string>

/* This is a dummy function to demonstrate pass by value.
 * Since it doesn't do anything with the argument, we suppress
 * possible compiler warnings using `maybe_unused`.
 */
void copy(int a) {
    [[maybe_unused]] int val = a;
}

void copyConst(const int a) {
    [[maybe_unused]] int val = a;
}

void write(int* a) {
    *a = 42;
}
void write(int& a) {
    a = 42;
}

void read(const int* a) {
    [[maybe_unused]] int val = *a;
}
void read(int const & a) {
//    [[maybe_unused]] int val = a; // (= a = 2) змінюється const посилання!
}

struct Test {
    void hello(std::string &s) {
        std::cout << "Hello " << s << '\n';
    }
    void helloConst(std::string &s) const {
        std::cout << "Hello " << s << '\n';
    }
};

int main() {
    // try pointer to constant
    int a = 1, b = 2;
    int const *i = &a;
    // *i = 5;                    // не змінюється значення через pointer to const
    i = &b;

    // try constant pointer
    int * const j = &a;
    *j = 5;
    // j = &b;                   // не можна переназначити constant pointer

    // try constant pointer to constant
    int const * const k = &a;
    // *k = 5;                  // const value — не можна змінювати
    // k = &b;                  // const pointer — не можна переназначити

    // try constant arguments of functions
    int l = 0;
    const int m = 0;
    copy(l);
    copy(m);
    copyConst(l);
    copyConst(m);

    // try constant arguments of functions with pointers
    {
      int *p = &a;
      const int *r = &b;
      write(p);
      // write(r);              // неможна передати const int* в функцію write(int*)
      read(p);
      read(r);
    }

    // try constant arguments of functions with references
    {
      int p = 0;
      const int r = 0;
      // write(2);              // не можна передати як не const reference
      // write(r);              // не можна передати const int в функцію, що вимагає int&
      read(2);
      read(r);
    }

    // try constant method in a class
    Test t;
    const Test tc;
    std::string s("World");
    t.hello(s);
    // tc.hello(s);  //hello не є const-методом
    t.helloConst(s);
    tc.helloConst(s);

    return 0;
}

/*
В результаті при кумпіляції та запуску маємо:
valeriia@valeriia-HP:~/5k/OOP/cppcourse-knu/exercises/constness$ g++ -g -o constness constplay.cpp
valeriia@valeriia-HP:~/5k/OOP/cppcourse-knu/exercises/constness$ ./constness
Hello World
Hello World
Hello World
*/