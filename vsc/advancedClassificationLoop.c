#include "NumClass.h"

// Function declarations
int factorial(int num);
int PWR(int a, int b);
int DigitCounter(int n);

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int original = num; // Store the original number for comparison
    int sum = 0;        // Initialize sum to 0
    int n = DigitCounter(num); // Count the number of digits in the number

    // Loop to calculate the sum of digits raised to the power of the number of digits
    while (num > 0) {
        int digit = num % 10;      // Extract the last digit
        sum += PWR(digit, n);      // Add the power of the digit to sum
        num /= 10;                 // Remove the last digit
    }

    // Check if the sum is equal to the original number
    if(sum == original) return 1; // If yes, it's an Armstrong number
    else return 0;                // Otherwise, it's not
}

// Function to check if a number is a palindrome
int isPalindrome(int n) {
    int number = n; // Store the original number for comparison
    int ans = 0;    // Initialize reversed number to 0

    // Loop to reverse the number
    while (n != 0) {
        ans = ans * 10 + n % 10; // Append the last digit to ans
        n /= 10;                 // Remove the last digit
    }

    // Check if the reversed number is equal to the original number
    if (ans == number) return 1; // If yes, it's a palindrome
    else return 0;               // Otherwise, it's not
}
