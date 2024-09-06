#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include "course.h"
#include "student.h"
#include <signal.h>
void handle_sigint(int sig)
{
    printf("\nClosing FIFO and Exiting server\n");
    unlink("/tmp/fifo.1");
    unlink("/tmp/fifo.2");
    exit(0); 
}
void handle_sigpipe(int sig)
{
    printf("\nBroken pipe! Client disconnected\n");
}
int main()
{
    signal(SIGINT, handle_sigint);

    signal(SIGPIPE, handle_sigpipe);

    char s1[1000] = "";
    int student_no = -1;
    Node *head = NULL;
    int commas = 0;
    char str[500];
    int roll_no, course_no;
    char name[50];
    float cgpa;
    int row = 0;

    mkfifo("/tmp/fifo.1", 0600);
    mkfifo("/tmp/fifo.2", 0600);

    printf("Server initialized\n");

    while (1)
    {

        int fd = open("/tmp/fifo.1", O_RDONLY);

        int bytesRead;
        while ((bytesRead = read(fd, s1, sizeof(s1))) > 0)
        {

            char *line = strtok(s1, "\n");

            while (line != NULL)
            {

                if (strcmp(line, "# initial database") == 0)
                {

                    while ((line = strtok(NULL, "\n")) != NULL)
                    {

                        commas = 0;

                        for (int i = 0; i < strlen(line); i++)
                        {
                            if (line[i] == ',')
                            {
                                commas++;
                            }
                        }

                        if (commas > 1)
                        {
                            row = 0;
                            student_no++;
                            sscanf(line, "%d, %49[^,], %f, %d", &roll_no, name, &cgpa, &course_no);
                            int(*course_marks)[2] = malloc(course_no * sizeof(int[2]));
                            for (int i = 0; i < course_no; i++)
                            {
                                for (int j = 0; j < 2; j++)
                                {
                                    course_marks[i][j] = 0;
                                }
                            }
                            insertAtEnd(&head, roll_no, name, cgpa, course_no, course_marks);
                            commas = 0;
                        }

                        else if (commas == 1)
                        {
                            int course_code, marks;
                            sscanf(line, "%d, %d", &course_code, &marks);
                            Node *nodeAtIndex = getNodeAt(head, student_no);
                            nodeAtIndex->data.course_marks[row][0] = course_code;
                            nodeAtIndex->data.course_marks[row][1] = marks;
                            row++;
                            commas = 0;
                        }

                    }
                }

                else if (strcmp(line, "# add student") == 0)
                {

                    while ((line = strtok(NULL, "\n")) != NULL)
                    {

                        sscanf(line, "%d, %49[^,], %f, %d", &roll_no, name, &cgpa, &course_no);

                        int(*course_marks)[2] = malloc(course_no * sizeof(int[2]));
                        for (int i = 0; i < course_no; i++)
                        {
                            for (int j = 0; j < 2; j++)
                            {
                                course_marks[i][j] = 0;
                            }
                        }
                        insertAtEnd(&head, roll_no, name, cgpa, course_no, course_marks);

                    }
                }

                else if (strcmp(line, "# add course") == 0)
                {
                    while ((line = strtok(NULL, "\n")) != NULL)
                    {
                        int course_id;
                        int marks;

                        sscanf(line, "%d, %d, %d", &roll_no, &course_id, &marks);
                        addCourse(head, roll_no, course_id, marks);
                    }
                }

                else if (strcmp(line, "# modify student") == 0)
                {
                    while ((line = strtok(NULL, "\n")) != NULL)
                    {

                        int modify_studentid;
                        float cgpa;
                        sscanf(line, "%d, %f", &modify_studentid, &cgpa);
                        modifyCGPA(head, modify_studentid, cgpa);
                    }
                }

                else if (strcmp(line, "# modify course") == 0)
                {

                    while ((line = strtok(NULL, "\n")) != NULL)
                    {

                        int course_id;
                        int new_marks;
                        int id;

                        sscanf(line, "%d, %d, %d", &id, &course_id, &new_marks);
                        modifyCourse(head, id, course_id, new_marks);
                    }
                }

                else if (strcmp(line, "# delete student") == 0)
                {
                    printf("%s\n", line);
                    while ((line = strtok(NULL, "\n")) != NULL)
                    {
                        printf("hello");
                        printf("%s\n ny loveoe", line);
                        int student_id_to_be_deleted = atoi(line);
                        deleteNode(&head, student_id_to_be_deleted);
                        strcpy(str, line);
                    }
                    printf("%s\n uweweew", line);
                    printf("%s  uhuhfr", str);
                    int student_id_to_be_deleted = atoi(str);
                    deleteNode(&head, student_id_to_be_deleted);
                    // fileWriting(head);
                }

                else if (strcmp(line, "# delete course") == 0)
                {

                    while ((line = strtok(NULL, "\n")) != NULL)
                    {

                        int course_id;
                        int id;
                        sscanf(line, "%d, %d", &id, &course_id);
                        deleteCourse(head, id, course_id);
                    }
                }

                break;
            }

            memset(s1, 0, sizeof(s1)); 
        }

        close(fd);
        // displayList(head);
        fileWriting(head);
    }
    return 0;
}
