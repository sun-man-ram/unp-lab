#include<stdio.h>
#include <stdlib.h>
#include<string.h>

int main(int argc,char *argv[]){
    char *input_filename=argv[1];
    printf("%s\n",input_filename);
    FILE *file = fopen(input_filename, "r");
   char line[256];
   int commas=0;
   while (fgets(line, sizeof(line), file)) {
   line[strcspn(line, "\n")] = 0;
   printf("%s\n",line);

    if(strcmp(line,"# add students/n")==0){

    }
    else if(strcmp(line,"# initial addition of database")==0){
        fgets(line, sizeof(line), file);
        while(1){
     //check no of commas 
     //accordingly select the student name row or course and mark row
     
     for(int i=0;i<sizeof(line)/sizeof(char);i++){
        if(line[i]==','){
            commas++;
        }
     }
     
      if(commas>1){
        // stduent name data base row
        // 1) i need to add this guy in linked list and 
        //check whether he is nique or not 
        // create a course linked list for his name under roll no
        printf("hello chintu this is name");
         
       
       
         
        
         








      }
      else{
        //course code and marks 
        // add the course in the linekd list and check whether it is unique or not
      printf("hello mani this course part");
      }
      fgets(line, sizeof(line), file);
      if(line[0] == '#')
      {
        break;
      }
  }

    }
    else if(strcmp(line,"# add course")){
        //printf("%s","Add the course");
    }
    else if(strcmp(line,"# modify student")){
        //printf("%s","Add the course");
    }
    else if(strcmp(line,"# modify course")){

    }
    else if(strcmp(line,"# delete student")){

    }
    else if(strcmp(line,"# delete course")){

    }
    }
     

  // we are reading the file that mam gave 
  // process the data 
    
   


    return 0;
}