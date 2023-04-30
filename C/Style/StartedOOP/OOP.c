//C doesn't have the powerful object-oriented features of C++ or Java. To implement object-oriented in C, programmers need to use structs and pointers to replace classes and objects.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Person {
    char name[50];
    int age;
    float height;
};
void print_person(struct Person* p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %.2f\n", p->height);
}
int main() {
    struct Person person1;
    strcpy(person1.name, "John");
    person1.age = 25;
    person1.height = 1.75;
    print_person(&person1);
    return 0;
}