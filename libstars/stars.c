#include <stdio.h>

#define WIN11 "WIN11"

void draw_stars(int n)
{
    printf("%s", CONFIG);
    for (int i = 0; i < n; i++)
    {
        printf("*");
        
    }
    printf("%s\n", CONFIG);
}