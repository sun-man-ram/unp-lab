#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
void parseFile(char *input_filename){
   int student_no = -1;
    
    FILE *file = fopen(input_filename, "r");
    char line[256];
    int commas = 0;
    char str[50];
    int roll_no, course_no;
    char name[50];
    float cgpa;
    int row = 0;
  
    while(fgets(line,sizeof(line),file))
    {
        
 
        line[strcspn(line, "\n")] = 0;
                // printf("%s\n",line);

        if (strcmp(str, "# add student") == 0){
             FILE *add = fopen("add_student", "w");

      while (1)
            {
                line[strcspn(line, "\n")] = 0;
                sscanf(line, "%d, %49[^,], %f, %d", &roll_no, name, &cgpa, &course_no);

                int(*course_marks)[2] = malloc(course_no * sizeof(int[2]));
             
                // Open the file for writing
  
   
    fprintf(add, "%s\n", line); // Write the string to the file
                fgets(line , sizeof(line), file);
                line[strcspn(line, "\n")] = 0;
                // add_course("add_student");
                // add_student("add_student");
                if (line[0] == '#' || feof(file))
                {
                        // fclose("add_student"); // Close the file
             fclose(add);
                         add_student("add_student");
                    strcpy(str, line);
                    break;
                }
            }
















             }
        else if (strcmp(line, "# initial database") == 0){
            // printf("in initial database");
             FILE *initial = fopen("initial_datbase", "w");
                line[strcspn(line, "\n")] = 0;
 fprintf(initial, "%s\n", line);
fgets(line, sizeof(line), file);
            line[strcspn(line, "\n")] = 0;

 while (1)
            {
 fprintf(initial, "%s\n", line);
               
          
                fgets(line, sizeof(line), file);
                line[strcspn(line, "\n")] = 0;
                // initialDatabase("initial_datbase");
                if (line[0] == '#' || feof(file))
                {
                    fclose(initial);
                    initialDatabase("initial_datbase");
                    strcpy(str, line);
                    // printf("%s is my lover\n",str);
                    break;
                }
            }




































                     }
        else if (strcmp(str, "# add course") == 0){








       FILE *add = fopen("add_course", "w");

   
      while (1)
            {
                line[strcspn(line, "\n")] = 0;
            
  
   
    fprintf(add, "%s\n", line); // Write the string to the file
                fgets(line , sizeof(line), file);
                line[strcspn(line, "\n")] = 0;
                if (line[0] == '#' || feof(file))
                {
                    fclose(add);
                    add_course("add_course");
                    strcpy(str, line);
                    break;
                }
            }











        }
        else if (strcmp(str, "# modify student") == 0){







       FILE *add = fopen("modifyStudent", "w");
     
   
      while (1)
            {
                line[strcspn(line, "\n")] = 0;
       
  
   
    fprintf(add, "%s\n", line); // Write the string to the file
                fgets(line , sizeof(line), file);
                line[strcspn(line, "\n")] = 0;
                if (line[0] == '#' || feof(file))
                {
                                        fclose(add);

                    modifyStudent("modifyStudent");
                    strcpy(str, line);
                    break;
                }
            }










          }
        else if (strcmp(str, "# modify course") == 0){


   



         FILE *add = fopen("ModifyCourse", "w");
 
   
      while (1)
            {
                line[strcspn(line, "\n")] = 0;
         
             
                // Open the file for writing
  
   
    fprintf(add, "%s\n", line); // Write the string to the file
                fgets(line , sizeof(line), file);
                line[strcspn(line, "\n")] = 0;
                if (line[0] == '#' || feof(file))
                {
                                        fclose(add);

                    modifyCourse("ModifyCourse");
                    strcpy(str, line);
                    break;
                }
            }













        }
        else if (strcmp(str, "# delete student") == 0){




       FILE *add = fopen("DeleteStudent", "w");

   
      while (1)
            {
                line[strcspn(line, "\n")] = 0;
                sscanf(line, "%d, %49[^,], %f, %d", &roll_no, name, &cgpa, &course_no);

                int(*course_marks)[2] = malloc(course_no * sizeof(int[2]));
             
                // Open the file for writing
  
   
    fprintf(add, "%s\n", line); // Write the string to the file
                fgets(line , sizeof(line), file);
                line[strcspn(line, "\n")] = 0;
                if (line[0] == '#' || feof(file))
                {
                fclose(add);

                    deleteStudent("DeleteStudent");
                    strcpy(str, line);
                    break;
                }
            }








        }
        else if (strcmp(str, "# delete course") == 0){

                   FILE *add = fopen("DeleteCourse", "w");
  
   
      while (1)
            {
                line[strcspn(line, "\n")] = 0;
                sscanf(line, "%d, %49[^,], %f, %d", &roll_no, name, &cgpa, &course_no);

                int(*course_marks)[2] = malloc(course_no * sizeof(int[2]));
             
                // Open the file for writing
  
   
    fprintf(add, "%s\n", line); // Write the string to the file
                fgets(line , sizeof(line), file);
                line[strcspn(line, "\n")] = 0;
                if (line[0] == '#' || feof(file))
                {
                fclose(add);
                    deleteCourse("DeleteCourse");
                    strcpy(str, line);
                    break;
                }
            }
            
        }


     

    }   




}