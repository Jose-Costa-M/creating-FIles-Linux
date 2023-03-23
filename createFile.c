#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>

int main()
{

    errno = 0;
    int filec, cdir; //create directories
    char fileName[255], dirName[255], path[255]; //save name
    char array[] = "hi good afternoon"; //char inside file

    /*printf("type directory to save the files: ");
    scanf("%s", path);*/

    srand(time(0));
    int r = (rand()%10)+1; //random number 
    printf("\n%d", r);

    //creating directory
    
    printf("\ntype directory name: "); //create new directory
    scanf("%s", dirName);
    
    cdir = mkdir(dirName, 0777); //directory permissions & name
    if(cdir != 0 && errno == EEXIST) //check whether directory exists
        printf("directory already exists");
    else{
        printf("directory created!");
        
    }

    //creating file

    for(int i=1; i <= r; i++){
        
        printf("\ntype file name with its extension: "); //name for new file
        scanf("%s", fileName);

        filec = open(fileName, O_CREAT| O_RDWR, 0777); //file creates; read & write permissions
            
        if(filec == -1) //if file isn't created
            printf("file not found\n");
        else
            printf("file created successfully\n");
        
        int content = write(filec, array, strlen(array)); //inside file goes array

        if(content == -1) //whether there's an error writing array
            printf("error!\n");
    }
         
    close(filec);
        
    return 0;
}