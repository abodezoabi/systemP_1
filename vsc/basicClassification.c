#include "NumClass.h"

// Function to calculate the factorial of a number
int factorial (int num) {
    int result = 1;
    for (int i = num; i > 1; i--) {
        result *= i;
    }
    return result;
}

// Function to calculate 'a' raised to the power of 'b'
int PWR (int a, int b) {
    if (b < 0) return 0; // If the exponent is negative, return 0
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a;
    }
    return ans;
}

// Function to count the number of digits in an integer
int DigitCounter(int n) {
    if (n == 0) return 1; // If the number is 0, return 1 (since it has one digit)
    int count = 0;
    while (n != 0) {
        n /= 10; // Divide by 10 to remove the last digit
        count++;
    }
    return count;
}

// Function to check if a number is prime
int isPrime(int x) {
    if (x <= 1) {return 0;} // If the number is less than or equal to 1, it's not prime
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {return 0;} // If divisible by any number other than 1 and itself, not prime
    }
    return 1; // Otherwise, it is prime
}

// Function to check if a number is a strong number
int isStrong(int num) {
    int originalNum = num;
    int sum = 0;
    while (num > 0) {
        int digit = num % 10; // Extract the last digit
        sum += factorial(digit); // Add the factorial of the digit to the sum
        num /= 10; // Remove the last digit
    }
    if(sum == originalNum) return 1; // If the sum of factorials equals the original number, it's strong
    else return 0; // Otherwise, it's not strong
}
