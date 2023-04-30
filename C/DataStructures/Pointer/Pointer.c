#include <stdio.h>
int main() {
   int var = 20;   /*Declare variable*/
   int *ip;        /*Declare pointer of type int*/
   ip = &var;      /*Store the address of the variable in the pointer*/
   printf("Giá trị của biến: %d\n", var);
   printf("Địa chỉ lưu trữ của biến: %x\n", &var);
   printf("Địa chỉ lưu trữ được lưu trữ trong con trỏ: %x\n", ip);
   printf("Giá trị của biến được truy xuất thông qua con trỏ: %d\n", *ip);
   return 0;
}
