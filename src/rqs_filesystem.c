#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "rqs.h"

int rqs_listDataDir()
{
    struct dirent *de;  // Pointer for directory entry
	int dir_size = 0; 
	char** filenames;
    // opendir() returns a pointer of DIR type. 
    DIR *dr = opendir("./data");
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open data/ directory. Please execute from openRQS root." );
        return 0;
    }
  
    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    // for readdir()
    while ((de = readdir(dr)) != NULL)
	{
		if(strcmp(de->d_name, ".") && strcmp(de->d_name, "..")) {
			dir_size++;
			printf("%s\n", de->d_name);
		}
	}
     
	
  
    closedir(dr);    
    return 0;
}
