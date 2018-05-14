#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <grp.h>
#include <pwd.h>
#include <fcntl.h>


struct stat stat1,stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
   filestat1();
   filestat2();
   filetime1();
   filetime2();
   sizecmp();
   blockcmp();
   datecmp();
   timecmp();
}

// load file info (file name : test1, test2)
void filestat1(void)
{
	stat("text1",&stat1);
}

// load file update time(file name : test1, test2)
void filestat2(void)
{
	stat("text2",&stat2);
}
void filetime1(void)
{}
void filetime2(void)
{}
void sizecmp(void)
{
	struct stat buf1,buf2; 
 	struct tm* time; 
 
 
 	int size1,size2; 
 
 
 	stat("text1",&buf1); 
 	stat("text2",&buf2); 
 	//get text1,text2 data 
 	//printf("size : %d\n", (int)buf1.st_size); 
 	//printf("size : %d\n", (int)buf2.st_size); 
 	size1=(int)buf1.st_size; 
 	size2=(int)buf2.st_size; 
 	//get size of text1,text2 
 
 
 	if(size1>size2) 
 	{ 
 		printf("%s is bigger\n","test1"); 
 	} 
 	else 
 	{ 
 		printf("%s is bigger\n","test2"); 
 	} 
 	//size compare 

}
void blockcmp(void)
{
   long long int file1 = (long long)stat1.st_blocks;
   long long int file2 = (long long)stat2.st_blocks;

   if(file1>file2) printf("text1 is bigger\n");
   else if(file1<file2) printf("text2 is bigger\n");
   else printf("same blocksize\n");
}
void datecmp(void)
{}
void timecmp(void)
{}

