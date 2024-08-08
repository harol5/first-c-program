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

     // size of a pointer variable is 8 bytes on my computer.
     printf("%lu\n", sizeof(p_age));

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
     printf("%p\n", p_ages);
     

     // I can access the values of the array by Dereferencing and pointer arithmethic.
     // first int in array.
     printf("%d\n", *ages); 
     printf("%d\n", ages[0]);
     printf("%d\n", *p_ages);

     // second int in array. (using pointer arithmethic).
     printf("%d\n", *(ages + 1)); 
     printf("%d\n", ages[1]);
     printf("%d\n", *(p_ages + 1));
     printf("%d\n", *(++p_ages));
     printf("%d\n", p_ages[0]);     
}

void multidimentionalArrays()
{
     int matrix[3][4] = {
          {10,11,12,13},
          {20,21,22,23},
          {30,31,32,33}
     };

     // Pointer to an integers array with size 3.
     // remenber that "matrix" is actually a pointer to 
     // a an integers array with size 3, that's why
     // we use the syntax "int *p_arrayInt[n]".
     int (*p_matrix)[4] = matrix;

     printf("---- first array ----\n");
     printf("%p\n", matrix); // address of first array.
     printf("Size of this array is %lu bytes\n", sizeof(*matrix));
     printf("Size of each element of array is %lu bytes\n", sizeof(*(*matrix)));
     printf("%d\n", *(*matrix)); // from right to left, first * gives me an int pointer to the first int of the first array.
     printf("%d\n", *(*matrix + 1));
     printf("%d\n", *(*matrix + 2));
     printf("%d\n", *(*matrix + 3));

     /*
      ========== output ==========
      ---- first array ----
      0x7ff7b9be01a0
      Size of this array is 16 bytes
      Size of each element of array is 4 bytes
      10
      11
      12
      13
     */

     printf("---- second array ----\n");
     printf("%p\n", matrix + 1); // address of second array.
     printf("%d\n", *(*(matrix + 1))); // from right to left, first * gives me an int pointer to the first int of the first array.
     printf("%d\n", *(*(matrix + 1) + 1));
     printf("%d\n", *(*(matrix + 1) + 2));
     printf("%d\n", *(*(matrix + 1) + 3));

     /*
      ========== output ==========
      ---- second array ----
      0x7ff7b9be01b0
      20
      21
      22
      23
     */

     printf("---- third array ----\n");
     printf("%p\n", matrix + 2);
     printf("%d\n", *(*(matrix + 2)));
     printf("%d\n", *(*(matrix + 2) + 1));
     printf("%d\n", *(*(matrix + 2) + 2));
     printf("%d\n", *(*(matrix + 2) + 3));

     /*
      ========== output ==========
      ---- third array ----
      0x7ff7b9be01c0
      30
      31
      32
      33
     */
}

void cubeArray()
{
     int cube[4][4][4] = {
          { {111,112,113,114}, {121,122,123,124}, {131,132,133,134}, {141,142,143,144} },
          { {211,212,213,214}, {221,222,223,224}, {231,232,233,234}, {241,242,243,244} },
          { {311,312,313,314}, {321,322,323,324}, {331,332,333,334}, {341,342,343,344} },
          { {411,412,413,414}, {421,422,423,424}, {431,432,433,434}, {441,442,443,444} },
     };


     printf("this cude has a size of %lu bytes\n", sizeof(cube));
     printf("%d\n",*(*(*(cube + 3) + 3) + 3)); // prints "444".
}

/*
Only the address of the first element will be pass.
so basically "int arr[]" = "int *arr", or "char str[]" = "char *str"
for that reason, when dealing with int array we must pass the size as well.
for string is not required as long as we use string literals or
we terminate the string array with a null character "\0".
*/ 
int sumOfArrayValues(int arr[], int size)
{
     int i;
     int sum = 0;
     
     for (i = 0; i < size; i++) {
          sum += *(arr + i);
          // sum += arr[i];
     }

     return sum;
}

void printString(char str[])
{
     // This is one way to iterate, BUT...
     int i = 0;
     while (str[i] != '\0') {
          printf("%c",str[i]);
          i++;
     }
     printf("\n");

     // remenber, "str" is just really a pointer, so i can simplify the loop with pointer arithmetic
     while (*str != '\0') {
          printf("%c", *str);
          str++;
     }
     printf("\n");
}

void printMultiDimentionalArray(int matrix[3][4])
{
     printf("%lu\n", sizeof(*matrix));
     printf("%d\n", **matrix);
}

int main()
{              
     int matrix[3][4] = {
          {10,11,12,13},
          {20,21,22,23},
          {30,31,32,33}
     };

     printMultiDimentionalArray(matrix);
     
     return 0;
}