#include "NumClass.h"

// Declaration of functions
int factorial(int num);
int PWR(int a, int b);
int DigitCounter(int n);
int RecursiveHelperPalindrome(int num, int original, int reversed);
int RECUR(int num, int digits, int sum);

// Function to check if a number is an Armstrong number
int isArmstrong(int num) {
    int digits = DigitCounter(num); // Count the number of digits
    int recur = RECUR(num, digits, 0); // Calculate the Armstrong sum recursively
    if(num == recur) {
        return 1; // If the number equals its Armstrong sum, it's an Armstrong number
    }
    else {
        return 0; // Otherwise, it's not
    }
}

// Recursive function to calculate the Armstrong sum
int RECUR(int num, int digits, int sum) {
    if (num == 0) return sum; // Base case: if num is reduced to 0, return the sum
    sum += PWR(num % 10, digits); // Add the power of the last digit to the sum
    return RECUR(num / 10, digits, sum); // Recursive call with the remaining number
}

// Function to check if a number is a palindrome
int isPalindrome(int num) {
    return RecursiveHelperPalindrome(num, num, 0); // Helper function to check palindrome recursively
}

// Recursive helper function for checking palindrome
int RecursiveHelperPalindrome(int num, int original, int reversed) {
    if (num == 0) {
        if (original == reversed) {
            return 1; // If the reversed number equals the original, it's a palindrome
        } else {
            return 0; // Otherwise, it's not
        }
    }
    // Recursive call: strip off the last digit of num and add it to the reversed number
    return RecursiveHelperPalindrome(num / 10, original, reversed * 10 + num % 10);
}
