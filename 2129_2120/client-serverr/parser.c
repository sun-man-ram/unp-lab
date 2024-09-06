#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"





#define MAX_LINE_LENGTH 1024

// Function to get the last line of the file
char* get_last_line(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    char *last_line = malloc(MAX_LINE_LENGTH);
    if (last_line == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    char current_line[MAX_LINE_LENGTH];
    last_line[0] = '\0';  // Initialize to an empty string

    // Read the file line by line and keep updating last_line
    while (fgets(current_line, MAX_LINE_LENGTH, file) != NULL) {
        strcpy(last_line, current_line);
    }

    fclose(file);

    // If the file is empty, return an empty string
    if (last_line[0] == '\0') {
        free(last_line);
        return NULL;
    }

    return last_line;
}







void parseFile(char *input_filename)
{
    //int student_no = -1;

    FILE *file = fopen(input_filename, "r");
    //FILE *sec = fopen(input_filename, "r");
    char line[256];
    //int commas = 0;
    char str[50];
    char last_line[100];
    int roll_no, course_no;
    char name[50];
    float cgpa;
    //int row = 0;
    char *heading;








char *last_line1 = get_last_line(input_filename);
printf("%s\n",last_line1);

while (fgets(line, sizeof(line), file))
{
    line[strcspn(line, "\n")] = 0;
    if (strcmp(str, "# add student") == 0)
    {
        FILE *add = fopen("add_student", "w");
        heading = "# add student";
        fprintf(add, "%s\n", heading);
        while (1)
        {
            line[strcspn(line, "\n")] = 0;
            sscanf(line, "%d, %49[^,], %f, %d", &roll_no, name, &cgpa, &course_no);
            // int(*course_marks)[2] = malloc(course_no * sizeof(int[2]));

            fprintf(add, "%s\n", line);
            fgets(line, sizeof(line), file);
            line[strcspn(line, "\n")] = 0;
            if (line[0] == '#' || feof(file))
            {

                fclose(add);
                add_student("add_student");
                strcpy(str, line);
                break;
            }
        }
    }
    else if (strcmp(line, "# initial database") == 0)
    {
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
            if (line[0] == '#' || feof(file))
            {
                
                fclose(initial);
                initialDatabase("initial_datbase");
                strcpy(str, line);
                break;
            }
        }
    }
    else if (strcmp(str, "# add course") == 0)
    {
        FILE *add = fopen("add_course", "w");
        heading = "# add course";
        fprintf(add, "%s\n", heading);

        while (1)
        {
            line[strcspn(line, "\n")] = 0;

            fprintf(add, "%s\n", line);
            fgets(line, sizeof(line), file);
            line[strcspn(line, "\n")] = 0;
            if (line[0] == '#' || feof(file))
            {
                  if (feof(file))
                {
                    printf("end of the file is encountered\n");
                    printf("%s\n", last_line1);
                     fprintf(add, "%s\n",last_line1);
                }
                fclose(add);
                add_course("add_course");
                strcpy(str, line);
                break;
            }
        }
    }
    else if (strcmp(str, "# modify student") == 0)
    {

        FILE *add = fopen("modifyStudent", "w");
        heading = "# modify student";
        fprintf(add, "%s\n", heading);

        while (1)
        {
            line[strcspn(line, "\n")] = 0;

            fprintf(add, "%s\n", line);
            fgets(line, sizeof(line), file);
            line[strcspn(line, "\n")] = 0;
            if (line[0] == '#' || feof(file))
            {
                  if (feof(file))
                {
                    printf("end of the file is encountered\n");
                    printf("%s\n", last_line1);
                     fprintf(add, "%s\n",last_line1);
                }
                fclose(add);

                modifyStudent("modifyStudent");
                strcpy(str, line);
                break;
            }
        }
    }
    else if (strcmp(str, "# modify course") == 0)
    {

        FILE *add = fopen("ModifyCourse", "w");
        heading = "# modify course";
        fprintf(add, "%s\n", heading);

        while (1)
        {
            line[strcspn(line, "\n")] = 0;

            fprintf(add, "%s\n", line);
            fgets(line, sizeof(line), file);
            line[strcspn(line, "\n")] = 0;
            if (line[0] == '#' || feof(file))
            {
                  if (feof(file))
                {
                    printf("end of the file is encountered\n");
                    printf("%s\n", last_line1);
                     fprintf(add, "%s\n",last_line1);
                }
                fclose(add);

                modifyCourse("ModifyCourse");
                strcpy(str, line);
                break;
            }
        }
    }
    else if (strcmp(str, "# delete student") == 0)
    {

        FILE *add = fopen("DeleteStudent", "w");
        heading = "# delete student";
        fprintf(add, "%s\n", heading);

        while (1)
        {
            line[strcspn(line, "\n")] = 0;
            sscanf(line, "%d, %49[^,], %f, %d", &roll_no, name, &cgpa, &course_no);

            // int(*course_marks)[2] = malloc(course_no * sizeof(int[2]));

            fprintf(add, "%s\n", line);
            strcpy(last_line, line);
            fgets(line, sizeof(line), file);
            line[strcspn(line, "\n")] = 0;
            if (line[0] == '#' || feof(file))
            {
               
              if (feof(file))
                {
                    printf("end of the file is encountered\n");
                    printf("%s\n", last_line1);
                     fprintf(add, "%s\n",last_line1);
                }
                   fclose(add);
                deleteStudent("DeleteStudent");
                strcpy(str, line);
               
              
                break;
            }
        }
    }
    else if (strcmp(str, "# delete course") == 0)
    {

        FILE *add = fopen("DeleteCourse", "w");
        heading = "# delete course";
        fprintf(add, "%s\n", heading);

        while (1)
        {
            line[strcspn(line, "\n")] = 0;
            sscanf(line, "%d, %49[^,], %f, %d", &roll_no, name, &cgpa, &course_no);

            // int(*course_marks)[2] = malloc(course_no * sizeof(int[2]));
            printf("hello world %s\n", line);
            fprintf(add, "%s\n", line);
            fgets(line, sizeof(line), file);
            line[strcspn(line, "\n")] = 0;
            printf("%s\n", line);
            if (line[0] == '#' || feof(file))
            {
                  if (feof(file))
                {
                    printf("end of the file is encountered\n");
                    printf("%s\n", last_line1);
                     fprintf(add, "%s\n",last_line1);
                }
                fclose(add);
                deleteCourse("DeleteCourse");

                strcpy(str, line);
                break;
            }
        }
    }
    }
}