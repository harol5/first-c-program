int binarySearch(char arr[], char value, int length)
{
     int first = 0;
     int last = length - 1;

     while (first <= last)
     {
          int middle = (first + last) / 2;
          char charMedium = arr[middle];

          if (charMedium == value) return middle;
          else if (charMedium < value) first = middle + 1;
          else last = middle - 1;
     }

     return -1;
}