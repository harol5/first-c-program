#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char name()
{
     return 'w';
}

void userInput() 
{
     //==========User Input.
     int userAge;
     printf("Please enter your age: ");
     scanf("%d", &userAge);
     printf("you are %d years old \n", userAge);

     double userGpa;
     printf("please enter your gpa: ");
     scanf("%lf", &userGpa);
     printf("your gpa is %f \n", userGpa);

     char userGrade;
     printf("please enter your grade: ");
     scanf("%c", &userGrade);
     printf("your grade is %c \n", userGrade);

     char userName[20];
     printf("please enter your name: ");
     fgets(userName, 20, stdin);
     printf("your name is %s", userName);
}

void variablesAndPrinting()
{
     //=========Creating a variables.
     
     //primitive data types.
     int age = 28;
     double gpa = 3.6;
     char grade = 'A';

     //this is a char but by using [] im telling
     //c to create and array of characters.
     char characterName[] = "harol";

     //re-assignning int var.
     age = 29;

     // constants
     const int CRR_YEAR = 2024;
     
     //=========Printing to console. format expecifiers (placeholders).

     //integers "%d".
     printf("%d\n",age);

     //string of chars "%s".
     printf("My name is %s, Im %d\n",characterName,age);

     //doubles or floats "%f".
     printf("My %s is %f\n","gpa",gpa);
     
     //chars "%c".
     printf("My fav %s is %c\n","character",grade);
}

void mathFunc()
{    
     //==========Number operations (C math functions).
     /**
      * You can google this to learn more math functions
      */

     //2^3
     printf("%f\n", pow(2, 3) );

     //square root.
     printf("%f\n", sqrt(4) );
     
     printf("%c\n",name());

}

void workingWithStructs()
{
     //========= Structs in C. (kind of like Objects in js)
     struct Student{
          int id;
          char name[20];
          char major[20];
          int age;
          double gpa;
     };
     
     struct Student studentOne;
     studentOne.age = 23;
     studentOne.gpa = 3.7;
     studentOne.id = 23456;
     strcpy( studentOne.major, "music");
     strcpy( studentOne.name, "harol");
}

// basics.
void pointers() 
{
     //========= Pointers
     int age = 23;

     // pointer variable (memory address);
     int *p_age = &age;

     // Dereferencing (access the value at given addrees and change value);
     *p_age = 29;
     printf("%d\n", age); // prints '29'.

     // pointer variable that hold the memory address of another pointer variable.
     int **p_p_age = &p_age;
     
}

// pass by reference.
void increment(int *number)
{
     // pass value by reference.
     *number = (*number) + 1;
}

void arrays()
{
     int ages[] = {23,45,67,67,89};
     int *p_ages = ages;

     char grades[] = {'h','a','r','o','l','\0'};

     char name[] = "harol";

     // "ages" is a reference to the first int in the array. (not "&" required).
     printf("%p\n", ages);
     printf("%lu\n", sizeof(ages));
     printf("%p\n", p_ages);
     printf("%lu\n", sizeof(p_ages));

     // I can access the values of the array by Dereferencing and pointer arithmethic.
     printf("%d\n", *ages); // first int in array.
     printf("%d\n", ages[0]);
     printf("%d\n", *p_ages);

     printf("%d\n", *(ages + 1)); // second int in array. (using pointer arithmethic).
     printf("%d\n", ages[1]);
}

/*
Only the address of the first element will be pass.
so basically "int arr[]" = "int *arr",
for that reason we must pass the size as well.
*/ 
int sumOfArrayValues(int arr[], int size)
{
     int i, sum;

     for (i = 0; i < size; i++) {
          sum += arr[i];
     }

     return sum;
}

int main()
{              
     arrays();
     return 0;
}