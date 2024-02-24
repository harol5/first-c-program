#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
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
     
     //=========Printing to console. format expecifiers (placeholders).

     //integers "%d".
     printf("%d\n",age);

     //string of chars "%s".
     printf("My name is %s, Im %d\n",characterName,age);

     //doubles or floats "%f".
     printf("My %s is %f\n","gpa",gpa);
     
     //chars "%c".
     printf("My fav %s is %c\n","character",grade);

     //==========Number operations.

     printf("%f", pow(2, 3) );

     return 0;
}