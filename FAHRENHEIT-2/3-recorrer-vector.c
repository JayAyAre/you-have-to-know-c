#include <stdio.h>

int main(void)
{
    float temperatura[5] = {112.2, 94.8, 18.9, 100.8, 64.3};

    for (int i = 0; i < 5; i++)
    {
        printf("Temperatura: %.2f\n", temperatura[i]);
    }
}