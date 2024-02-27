#include<stdio.h>
#include<stdlib.h>

#pragma region tools
void printFirst8Bits(int integer, char *buffer)
{
    int mask = 1 << 7; // 10000000
    // get first 8 bits from integer
    for(int i = 0; i < 8; i++)
    {
        buffer[i] = ((integer & mask) > 0)? '1' : '0';
        mask = mask >> 1;
    }
    // insert a null terminator at the end of the string
    buffer[8] = '\0';
}
#pragma endregion tools

// bit operations
void bitOperations(int x, int y)
{
    // the size of the string array should be the same as the number of characters plus one
    // the last space of the string array should be inserted a null terminator
    char buffer_x[9] = " ", buffer_y[9] = " ", buffer_result[9] = " ";
    printFirst8Bits(x, buffer_x);
    printFirst8Bits(y, buffer_y);
    printf("x = %s, y = %s\n", buffer_x, buffer_y);

    // bit AND
    int x_and_y = x & y;
    printFirst8Bits(x_and_y, buffer_result);
    printf("x & y = %s\n", buffer_result);

    // bit OR
    int x_or_y = x | y;
    printFirst8Bits(x_or_y, buffer_result);
    printf("x | y = %s\n", buffer_result);

    // bit NOT
    int x_not = ~x;
    printFirst8Bits(x_not, buffer_result);
    printf("x_not = %s \n", buffer_result);

    // bit XOR
    int x_xor_y = x ^ y;
    printFirst8Bits(x_xor_y, buffer_result);
    printf("x xor y = %s\n", buffer_result);

    // bit shift
    int x_left_shift_1 = x << 1;
    printFirst8Bits(x_left_shift_1, buffer_result);
    printf("x left shift 1 = %s\n", buffer_result);
    int x_right_shift_1 = x >> 1;
    printFirst8Bits(x_right_shift_1, buffer_result);
    printf("x right right 1 = %s\n", buffer_result);
}
int main(int argc, char **argv)
{
    if(argc < 3)
    {
        fprintf(stderr, "not enough input parameters\n");
        return 1;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    bitOperations(x,y);
    return 0;
}