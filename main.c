#include<stdio.h>
#include <stdlib.h>
#include<string.h>
int main(int argc,char *argv[]){
    char *input_filename=argv[1];
    printf("%s\n",input_filename);
    FILE *file = fopen(input_filename, "r");
   char line[256];
   while (fgets(line, sizeof(line), file)) {
   line[strcspn(line, "\n")] = 0;

    //    if(strcmp(line,"hi")==0)
    //    {
    //     printf(":)\n");
    //    }
    //    else{
    //     printf(":( \n");
    //    }

    if(strcmp(line,"# add students")){

    }
    else if(strcmp(line,"# initial addition of database")){
        
    }
    else if(strcmp(line,"# add course")){

    }
    else if(strcmp(line,"# modify student")){

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