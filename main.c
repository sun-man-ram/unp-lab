#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student
{
  // one is represnting node 
  // name 
  //cgpa
  //number of subjects
};



// double linkedlist here 
















int main(int argc, char *argv[])
{
  char *input_filename = argv[1];
  printf("%s\n", input_filename);
  FILE *file = fopen(input_filename, "r");
  char line[256];
  int commas = 0;
  char str[50];
  while (fgets(line, sizeof(line), file))
  {

    line[strcspn(line, "\n")] = 0;
    printf("%s\n", line);

    if (strcmp(str, "# add students/n") == 0)
    {
      printf("in add students\n");
    }
    else if (strcmp(line, "# initial addition of database") == 0)
    {

      fgets(line, sizeof(line), file);
       line[strcspn(line, "\n")] = 0;

      while(1)
      {
        commas = 0;
        // check no of commas
        // accordingly select the student name row or course and mark row

        for (int i = 0; i < strlen(line); i++)
        {
          if (line[i] == ',')
          {
            commas++;
          }
        }
        printf("%d\n", commas);
        if (commas > 1)
        {

          // printf("%s",line);
          // stduent name data base row
          // 1) i need to add this guy in linked list and
          // check whether he is nique or not
          // create a course linked list for his name under roll no
          

          // accessing student name and roll no cgpa courseNo
          int comm = 0;

          commas = 0;
        }
        else if (commas == 1)
        {
          // course code and marks
          //  add the course in the linekd list and check whether it is unique or not
          
          commas = 0;
        }

        fgets(line, sizeof(line), file);
        line[strcspn(line, "\n")] = 0;

        if (line[0] == '#')
        {
          printf("is this coming\n");
          printf("%s",line);
         
          strcpy(str,line);
           printf("%s",str);
          break;
        }
      }
    }
    else if (strcmp(str, "# add course"))
    {

      printf("%s", "Add the course guys ");
      //  printf("tony");
    }
    else if (strcmp(str, "# modify student"))
    {
      printf("%s", "Add the course");
    }
    else if (strcmp(str, "# modify course"))
    {
      printf("%s", "modify course");
    }
    else if (strcmp(str, "# delete student"))
    {
      printf("%s", "delete student");
    }
    else if (strcmp(str, "# delete course"))
    {
      printf("%s", "delete course");
    }
  }

  // we are reading the file that mam gave
  // process the data

  return 0;
}