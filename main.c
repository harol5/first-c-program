#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>
#include "linked-list.c"
#include "algorithm.c"

#define ACTIVE 0x01
#define BANNED 0x02
#define ADMIN 0x04
#define USER_FLAGS 0X05

#define IS_ACTIVE(A,B) (A & B)
#define GET_BOOL(STATUS) ((STATUS) == 1 ? "true" : "false")

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  ((byte) & 0x80 ? '1' : '0'), \
  ((byte) & 0x40 ? '1' : '0'), \
  ((byte) & 0x20 ? '1' : '0'), \
  ((byte) & 0x10 ? '1' : '0'), \
  ((byte) & 0x08 ? '1' : '0'), \
  ((byte) & 0x04 ? '1' : '0'), \
  ((byte) & 0x02 ? '1' : '0'), \
  ((byte) & 0x01 ? '1' : '0') 


int xArrLength;
int yArrLength;
int zArrLength;

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

// == basics ==.
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

// == pass by reference ==.
void increment(int *number)
{
     // pass value by reference.
     *number = (*number) + 1;
}

// ========= ARRAYS ===============|.

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

void printMultiDimentionalArray(char matrix[xArrLength][yArrLength])
{
     printf("==== printMultiDimentionalArray func ====\n");     
     printf("%lu\n", sizeof(*matrix));
     printf("%d\n", **matrix);

     char letter;
     char letterTwo;
     for (int i = 0; i < xArrLength; i++){

          if (i != 0 && i % 2 != 0) {
               letter = ' ';
               letterTwo = '.';
          }else {
               letter = '.';
               letterTwo = ' ';
          }      

          for (int j = 0; j < yArrLength; j++) {
               if (j != 0 && j % 2 != 0) {  // even.                  
                    *(*matrix + j) = letterTwo;
               }else {                    // odd.
                    *(*matrix + j) = letter;
               }
               
               printf("%c",*(*matrix + j));               
          }
          
          matrix++;
          printf("\n");
     }
     
}

void testingMultiArray()
{
     xArrLength = 30;
     yArrLength = 150;          
     char letterMatrix[xArrLength][yArrLength];
     char (*p_letterMatrix)[yArrLength] = letterMatrix;

     printMultiDimentionalArray(letterMatrix);
}

// ========== MEMORY ALLOCATION ==========|.

void memoryHeap()
{
     // ============= malloc() =================== //
     // allocation of memory in heap.
     int *p_ages = (int*)malloc(10 * sizeof(int));

     *p_ages = 23;
     *(p_ages + 1) = 65;
     
     printf("==== malloc() =====\n");
     printf("%p\n",p_ages);
     for (int i = 0; i < 10; i++){
          if (i < 2) continue;
          p_ages[i] = *(p_ages + 1) - i;
          printf("%d\n",p_ages[i]);
     }

     // ============= calloc() =================== //
     // similar to malloc but initialize values to 0;
     char *p_grades = (char*)calloc(10, sizeof(char));

     printf("==== calloc() =====\n");
     printf("%p\n",p_grades);
     for (int i = 0; i < 10; i++){
          *(p_grades + i) = 'A' + i;          
          printf("%c\n", *(p_grades + i));
     }

     // ============= realloc() =================== //
     // modifies the size of an existing block of memory.
     // might keep the same address of the previous pointer
     // or get a new one, copy the elements and freed previous pointer. 
     int *p_agesTwo = (int*)realloc(p_ages, 20 * sizeof(int));

     printf("==== realloc() =====\n");
     printf("original pointer location: %p\n",p_ages);
     printf("relocated pointer location: %p\n",p_agesTwo);
     printf("pointer to block is %s\n", p_ages == p_agesTwo ? "the same location" : "diferent location");

     for (int i = 0; i < 20; i++){
          printf("%d\n",p_agesTwo[i]);
     }

     // ============= free() =================== //
     // after you are done using mempry block, you MUST FREE IT.
     // free(p_ages);
     free(p_grades);
     free(p_agesTwo);
     
     // also, make sure to assign NULL to pointer variable to delete refrence.
     p_ages = NULL;
     p_grades = NULL;
     p_agesTwo = NULL;
}

void concatStrToBuffer(char firtName[], char lastName[], char buffer[])
{
     while (*firtName != '\0') {
          *buffer = *firtName;
          firtName++;
          buffer++;          
     }

     *buffer++ = ' ';

     while (*lastName != '\0') {
          *buffer = *lastName;
          lastName++;
          buffer++;          
     }

     *buffer = '\0';
}

// returning pointer from a function.
char *concatStrToHeap(char firstName[], char lastName[], int strLength)
{
     // allocate memory.
     char *str = (char*)malloc(sizeof(char) * strLength);

     /*
     because the pointer variable used to get the memory address returned by "malloc"
     will be incremented by the "while" loop, I should store the initial address of the allocated block
     in a separate pointer variable.
     */
     char *p_str = str;
     
     while (*firstName != '\0')
     {          
          *str = *firstName;          
          firstName++;
          str++;
     }     
     *str++ = ' ';

     while (*lastName != '\0')
     {          
          *str = *lastName;
          lastName++;
          str++;
     }     
     *str = '\0';
     
     return p_str;
}

// ========== FUNCTION POINTERS ==========|.
int sumCallBack(int a, int b){
     return a + b;
}

// higher order function. (func as param)
int doSum(int (*p_sumFunc)(int,int), int numOne, int numTwo)
{
     return p_sumFunc(numOne,numTwo);
}

void pointerToFunc()
{
     // This is how we create pointer varible to a function.
     int (*p_func)(int,int) = &sumCallBack;

     // Dereferencing
     int sum = (*p_func)(2,2);
     printf("%d\n",sum);

     // OR!! - you can do it without "&".
     int (*p_funcTwo)(int,int) = sumCallBack;

     // Dereferencing
     int sumTwo = p_funcTwo(sum, sum);
     printf("%d\n",sumTwo);

     // using higher order func.
     int sumThree = doSum(sumCallBack, sumTwo, sumTwo);
     printf("%d\n",sumThree);
}

// =========== LINKEDLIST ==============|.
void testLinkedList()
{
     unsigned dataSize = sizeof(int);
     struct LinkedList *ages = createLinkedList(dataSize);
     
     int arrIntLength = 5;
     int nums[] = {1,2,4,8,16};
     for (int i = 0; i < arrIntLength; i++) {
          addAtLast(ages, nums + i);     
     }          
     printLinkedList(ages,printIntLinkedList);
     printf("=== current size of linked list: %d\n", ages->length);

     int newAge = 32;
     addAtHead(ages,&newAge);
     printLinkedList(ages,printIntLinkedList);
     printf("=== current size of linked list: %d\n", ages->length);
}

void testLinkedListOperations()
{
     // Always initialize pointer to NULL if actual initialization of 
     // of pointer must be done later or after using free() function.
     struct LinkedList *linkedList = NULL;

     linkedList = createLinkedList(sizeof(char));
     char name[] = "harld";
     char *letter = name;
     while (*letter != '\0')
     {
          addAtLast(linkedList,letter);
          letter++;
     }
          
     printf("============ PRINTING YOUR LINKEDLIST =============\n");
     printLinkedList(linkedList,printCharLinkedList);
     printf("current length: %d\n",linkedList->length);

     char missingLetter = 'o';
     addAt(4,&missingLetter,linkedList);
     printf("============ PRINTING YOUR LINKEDLIST =============\n");
     printLinkedList(linkedList,printCharLinkedList);
     printf("current length: %d\n",linkedList->length);

     missingLetter = 'g';
     int addAtStatus = addAt(15, &missingLetter, linkedList);
     printf("============ PRINTING YOUR LINKEDLIST =============\n");
     printLinkedList(linkedList,printCharLinkedList);
     printf("was node added? %s\n", GET_BOOL(addAtStatus));
     printf("current length: %d\n",linkedList->length);

     missingLetter = 'z';
     int addAtStatus2 = addAt(1, &missingLetter, linkedList);
     printf("============ PRINTING YOUR LINKEDLIST =============\n");
     printLinkedList(linkedList,printCharLinkedList);
     printf("was node added? %s\n", GET_BOOL(addAtStatus2));
     printf("current length: %d\n",linkedList->length);

     int status = removeAt(1,linkedList);     
     printf("============ PRINTING YOUR LINKEDLIST =============\n");     
     printLinkedList(linkedList,printCharLinkedList);
     printf("was node remove? %s\n", GET_BOOL(status));
     printf("current length: %d\n",linkedList->length);

     int secondStatus = removeAt(7,linkedList);     
     printf("============ PRINTING YOUR LINKEDLIST =============\n");     
     printLinkedList(linkedList,printCharLinkedList);
     printf("was node remove? %s\n", GET_BOOL(secondStatus));
     printf("current length: %d\n",linkedList->length);

     
     printf("============ PRINTING YOUR LINKEDLIST =============\n");     
     printf("this is the head node data before emptying it: %c\n",*((char*)linkedList->head->data));
     int emptyStatus = emptyLinkedList(linkedList);   
     printf("was linked list emptied? %s\n", GET_BOOL(emptyStatus));  
     printLinkedList(linkedList,printCharLinkedList);
     printf("current length: %d\n",linkedList->length);

     int emptyStatus2 = emptyLinkedList(linkedList);   
     printf("was linked list emptied? %s\n", GET_BOOL(emptyStatus2));  


     int deleteLinkedListStatus = deleteLinkedList(&linkedList); 
     printf("was linked list deleted? %s\n",GET_BOOL(deleteLinkedListStatus));

     // another call to delete the same linked list will return 0 (false).
     int deleteLinkedListStatus2 = deleteLinkedList(&linkedList);     
     printf("was linked list deleted? %s\n",GET_BOOL(deleteLinkedListStatus2));

}

// ===== WORKING WITH BITS =====

void practicingBitWiseOperators()
{
     u_int8_t harolStatus = 12;

     // -- BITWISE OPERATORS -|

     // OR "|" -> Good for combining.
     printf("banned user: %d\n", BANNED | USER_FLAGS );
     /**
      *     0010  -> BANNED(2)
      *   | 0101  -> USER_FLAGS(5)
      *   -------
      *     0111  -> updated USER_FLAGS(7)      
      */

     // AND "&" -> Good for checking if flags are on in another set of bits.
     printf("is user active? %d\n", IS_ACTIVE(ACTIVE, USER_FLAGS) );
     /**
      *     0001  -> is ACTIVE(1) flag on in user flags?
      *   & 0101  -> crr user flags: USER_FLAGS(5)
      *   -------
      *     0001  -> return ACTIVE(1) flag, meaning is true.      
      */

     // XOR "^" -> Good for turn off a flag.
     printf("ADMIN flag turned off. updated USER_FLAGS: %d\n", ADMIN ^ USER_FLAGS );
     /**
      *     0100  -> turn off ADMIN(4) flag,
      *   ^ 0101  -> from crr user flags: USER_FLAGS(5)
      *   -------
      *     0001  -> return updated USER_FLAGS.
      */

     // SHIFT RIGHT ">>" -> shift bits to the right n times.
     printf("SHIFT RIGHT '>>' -> is ADMIN flag turned on?: %d\n", USER_FLAGS >> 2 );
     /**
      *     0101  -> from crr user flags: USER_FLAGS(5)
      *  >>    2  -> shift bits to the right 2 times.
      *   -------
      *     0001  -> return value of 3 flag.
      */

     // SHIFT LEFT ">>" -> shift bits to the right n times.
     printf("SHIFT LEFT '<<' -> : %d\n", USER_FLAGS << 1 );
     /**
      *     0101  -> from crr user flags: USER_FLAGS(5)
      *  <<    1  -> shift bits to the right 2 times.
      *   -------
      *     1010  -> (10) return value of 3 flag.
      */

}

void practicingBitFields()
{
     // the underlaying type used in this struct bit field is 1 byte(8 bits).
     // meaning, even though Im only using 5 bits on this bit field struct,
     // its size is still 8 bits (byte).
     struct UserFLags {
          u_int8_t ACTIVE_FLAG: 1;
          u_int8_t BANNED_FLAG: 1;
          u_int8_t ADMIN_FLAG: 1;
          u_int8_t OWNER_FLAG: 1;
          u_int8_t PREMIUM_FLAG: 1;                    
     };

     struct UserFLags flags = {1,0,1,0,1};

     printf("%d\n", flags.OWNER_FLAG);
     printf("%lu\n", sizeof(flags));
}

// =========== raw binary data ==============|.
char *binaryToAscii(void *data, size_t size)
{
     unsigned char *byteData = (unsigned char*)data;
     unsigned const char MAX_LETTER = 126;
     unsigned const char MIN_LETTER = 32;
     char *phrase = (char*)malloc(size + (size_t)1);

     size_t i;
     for ( i = 0; i < size; i++ )
     {
          unsigned char letter = (unsigned char)byteData[i];
          printf("==== byte number: %lu ====\n", i + 1);
          printf("byte decimal value: %d\n", letter);
          
     
          if( letter > MAX_LETTER) letter = letter - MAX_LETTER;

          if( letter < MIN_LETTER) letter = letter + MIN_LETTER + i;

          printf("true decimal char value: %d\n", letter);
          printf("byte char value: %c\n", letter);

          phrase[i] = letter;
     }

     phrase[i + (size_t)1] = '\0';

     return phrase;
}

void practicingBinaryToAscii()
{
     u_int32_t num = 4023323328;
     struct LinkedList ll;
     char *phrase = binaryToAscii(&ll,sizeof(struct LinkedList));
     printString(phrase);
     free(phrase);
}

int main()
{        
     char arr[] ={'a','c','f','j','l','z'};        
     printf("the char 'z' is located at %d\n", binarySearch(arr,'z',(int)(sizeof(arr) / sizeof(char))));
     printf("the char 'f' is located at %d\n", binarySearch(arr,'f',(int)(sizeof(arr) / sizeof(char))));     
     printf("the char 'q' is located at %d\n", binarySearch(arr,'q',(int)(sizeof(arr) / sizeof(char))));     
     return 0;
}