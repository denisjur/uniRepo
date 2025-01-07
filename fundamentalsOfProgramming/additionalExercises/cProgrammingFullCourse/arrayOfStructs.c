#include <stdio.h>
#include <string.h>

struct Student
{
    char name[12];
    float gpa;
};


int main() {
  
  struct Student student1 = {"Jerry", 3.0};
  struct Student student2 = {"Tom", 4.0};
  struct Student student3 = {"Simba", 1.0};
  struct Student student4 = {"Mufasa", 6.0};

  // Now we have 4 studnets, so we can create an array:

  struct Student students[] = {student1, student2, student3, student4};

  for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++)
{
    printf("%-12s\t", students[i].name);
    printf("%.2f\n", students[i].gpa);
};



    return 0;
};

