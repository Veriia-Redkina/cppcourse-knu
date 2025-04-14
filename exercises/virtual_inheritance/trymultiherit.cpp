#include "TextBox.hpp"
#include <iostream>

int main() {
    // create a TextBox and call draw
    TextBox textbox("Hello, World!", 100, 50);
    //textbox.draw();

    /*В результаті маємо:
   error: ld returned 1 exit status
    */
    // Fix the code to call both draws by using types
    // try with virtual inheritance

    Rectangle &r = textbox;
    r.draw();
    Text &t = textbox;
    t.draw();

}
/*результат
valeriia@valeriia-HP:~/5k/OOP/cppcourse-knu/exercises/virtual_inheritance$ ./trymultiherit
Drawing 3
Drawing 3
*/