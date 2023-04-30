#include <stdio.h>
int main() {
   int num1 = 10, num2 = 20;
   int *ptr1 = &num1;
   int *ptr2 = &num2;
   printf("Value of num1 = %d\n", num1); //Print the value of num1 before swap
   printf("Value of num2 = %d\n", num2); //Print the value of num2 before swap
   //Use 2 pointers to swap the values of 2 variables num1 and num2
   int *temp;
   temp = ptr1;
   ptr1 = ptr2;
   ptr2 = temp;
   printf("Value of num1 = %d\n", *ptr1); //Print value of num1 after swap 
   printf("Value of num2 = %d\n", *ptr2); //print value of num2 after swap
   return 0;
}