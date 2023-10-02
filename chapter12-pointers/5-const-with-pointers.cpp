#include <iostream>

using namespace std;

int main() {
    int num1 = 1;
    int num2 = 2;
    const int* num1Ptr {&num1};

    // *num1Ptr = 2; Not allowed by const
    num1Ptr = &num2;

    int* const num2Ptr {&num2};
    *num2Ptr = 3;
    // num2Ptr = &num1; Not allowed by const

    const int* const num3Ptr {&num1};
    // *num3Ptr = 1; Both not allowed by const
    // num3Ptr = &num2; Both not allowed by const

    return 0;
}