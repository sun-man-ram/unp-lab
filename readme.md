<h2>
  Creating a Student Parsing and storing in Double LinkedList
  <br>
  Applying crud application
</h2>
<h3>
  This is the Raw version while Creating.Complete modularisation and breaking into chunks is done in this 
  <br>
  https://github.com/cschauhan0304/NP_Lab_Modularized_Code.git
  <br>
  This repo :)
  
</h3>

<h4>
Problem Statement
</h4>
<h5>
The program must construct a student information base by reading data from an input file which is given as a command line argument. The initial part of the file is the initial database. The remaining sections of the input file contain further operations of the database. Finally, the program must write the output to a file whose name is of the form xx_yy.out where xx_yy is determined by the reg.no. of the student members of the group. The format of the file, hints on programming etc. are given below. the executable of your program should also be named xx_yy. STRICTLY ADHERE TO THE SUBMISSION POLICY, THE NAMES OF THE FILES AS SPECIFIED SO WE CAN CORRECT YOUR PROGRAMS USING SCRIPTS.

NOTE: You need to handle error conditions such as trying to add a duplicate record (primary key is Roll No. for students and Roll No., Course No. for courses), modify a non-existing record, delete a non-existing record for both students and courses.

Build a simple student database. The following are the fields that a student record contains:
1. Roll No. : Integer

2. Name : String

3. CGPA : Float

4. Number of subjects : Integer

NOTE: Roll no. and Name are primary keys and cannot be modified once entered. We do not allow modification of number of subjects either.

For every subject, it has the following:
1. Course Code

2. Marks

NOTE: Course Code is a primary key and only Marks can be modified.

The input file from which the student information is to be read is formatted in the following manner:
# Initial database information

Roll No., Name, CGPA, Number of Subjects

Course Code1, Marks

Course Code2, Marks

...

Course CodeN, Marks

Roll No., Name, CGPA, Number of Subjects

Course Code1, Marks

Course Code2, Marks

...

Course CodeM, Marks

... # Add Student

Roll No., Name, CGPA, Number of subjects

Roll No., Name, CGPA, Number of subjects

...

# Add course

Roll No., Course Code, Marks

Roll No., Course Code, Marks

...

# Modify Student

Roll No., CGPA

Roll No., CGPA

...

# Modify Course

Roll No., Course Code, Marks

Roll No., Course Code, Marks

...

# Delete Student

Roll No.

Roll No.

...

# Delete Course

Roll No., Course Code

Roll No., Course Code

...

Please note that the number of subjects can be different for different students. For e.g., an MCA student does a lot more courses than an M.Tech. student.
The first part of the file is the initial database population information. There is information of many students in this section. For each student, there is one line listing all the general details. Then, there are as many lines as the number of subjects for the marks. You may assume that there will be exactly as many lines as the number of subjects specified and so on. That there will not be errors in the input file such as inconsistencies between what is specified in "add student" versus what is specified in "add course". You need to parse the course code and marks for "Number of Subjects" lines for that student. Note that the format of the file is in CSV (comma space value) format.

NOTE: Any line starting with # is a comment line and should be discarded after parsing for information regarding whether the operation to follow is an Add student/Add course/Modify student/Modify course/Delete student/Delete course. Any blank lines should also be discarded. Please Note that Add student, Add course, etc. sections need not come in strict order and also can occur many times in the file. Please also note that you need to increment the number of subjects if you are adding subjects later from the Add Course section of the input file. Otherwise, your output will not match expected output.

Here is an Example file.
Once you have parsed the file, you need to use the APIs exported by the student information module to add the student record and/or the marks record for a student.
HINT: Use the C library call fgets for reading one line at a time from the file. Then use the call sscanf to parse individual items on the line - keep in mind that this is CSV format and set your sscanf string accordingly.

The data structure can be chosen from the following:
1. Doubly linked list

2. Hash table with open chaining


</h5>
