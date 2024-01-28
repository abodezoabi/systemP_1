#include "NumClass.h" 
#include <stdio.h>

int main() {
    int start,end;
    printf("Enter the start of the range: ");
    scanf("%d", &start);
    printf("Enter the end of the range: ");
    scanf("%d", &end);
    printf("The Armstrong numbers in the range %d to %d are: ", start, end);
    for (int i = start; i <= end; i++) {
        if(i<=0){continue;}
        if (isArmstrong(i)) {printf("%d ", i);}
    }
    printf("\nThe Palindromes in the range %d to %d are: ", start, end);
    for (int i = start; i <= end; i++) {
           if(i<=0){continue;}
        if (isPalindrome(i)) {printf("%d ", i);}
    }
    printf("\nThe Prime numbers in the range %d to %d are: ", start, end);
    for (int i = start; i <= end; i++) {
           if(i<=0){continue;}
        if (isPrime(i)) {printf("%d ", i);}
    }
    printf("\nThe Strong numbers in the range %d to %d are: ", start, end);
    for (int i = start; i <= end; i++) {
           if(i<=0){continue;}
        if (isStrong(i)) {printf("%d ", i);}
    }
    printf("\n");
    return 0;
}