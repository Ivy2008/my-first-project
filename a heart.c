#include <stdio.h>

int main() {
   
    printf("\033[1;31m");

    float y, x, a;

    for (y = 1.5f; y > -1.5f; y -= 0.09f) {
        for (x = -1.5f; x < 1.5f; x += 0.05f) {
            a = x * x + y * y - 1;
           
            putchar(a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ');
        }
        putchar('\n');
    }

    printf("\033[0m");
    
    return 0;
}