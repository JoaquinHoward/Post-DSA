#include<stdio.h>
#include<stdlib.h>


int binaryToDecimal(int binaryNum);

int main(void){
    int n;
    printf("Enter binary number: ");
    scanf("%d", &n);
    printf("The decimal equivalent of the binary %d is %d.", n, binaryToDecimal(n));
}

int binaryToDecimal(int binaryNum){
    int n = binaryNum;
    int place = 1;
    int decimal = 0;
    int remainder;
    while(n>0){
        remainder = n % 10;
        n = n / 10;
        decimal = decimal + remainder * place;
        place = place * 2;
    }
    return decimal;
}