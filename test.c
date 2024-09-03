#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <bits/stdc++.h>

int main() {
    char line[] = "1, aa, 8.2, 5";
    int roll_no, course_no;
    char name[50];
    float cgpa;

    // Parse the line and store the values in variables
    sscanf(line, "%d, %49[^,], %f, %d", &roll_no, name, &cgpa, &course_no);

    // Print the values to verify they have been parsed correctly
    printf("Roll No: %d\n", roll_no);
    printf("Name: %s\n", name);
    printf("CGPA: %.2f\n", cgpa);
    printf("Course No: %d\n", course_no);
    FILE *Files ;
    Files= fopen("tokens.txt", "a");
	fputs(line, Files);
    fputs("\n", Files);
	fclose(Files);

    return 0;
}
