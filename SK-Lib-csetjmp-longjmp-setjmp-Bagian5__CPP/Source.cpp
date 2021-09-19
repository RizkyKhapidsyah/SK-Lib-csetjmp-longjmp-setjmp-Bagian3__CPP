#include <iostream>
#include <csetjmp>
#include <conio.h>

std::jmp_buf jump_buffer;

/*
    Source by CPPReference
    Modified For Learn by RK
    I.D.E : VS2019
*/

[[noreturn]] void a(int count) {
    std::cout << "a(" << count << ") called\n";
    std::longjmp(jump_buffer, count + 1);  // setjmp() will return count+1
}

int main() {
    volatile int count = 0; // local variables must be volatile for setjmp

    if (setjmp(jump_buffer) != 9) {
        a(count++);  // This will cause setjmp() to exit
    }

    _getch();
    return 0;
}