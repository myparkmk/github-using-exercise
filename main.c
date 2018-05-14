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

int year1, month1, day1;
int year2, month2, day2;
int stat1_time;
int stat2_time;


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

// load file info (file name : text1, text2)
void filestat1(void)
{
	stat("text1",&stat1);
}

void filestat2(void)
{
	stat("text2",&stat2);
}

// get load files' modified time
void filetime1(void)
{
	time1 = localtime(&stat1.st_mtime);

	year1 = time1->tm_year+1900;
	month1 = time1->tm_mon + 1;
	day1 = time1->tm_mday;

	stat1_time = (time1->tm_hour*3600)+(time1->tm_min*60)+(time1->tm_sec);
}

void filetime2(void)
{
	time2 = localtime(&stat2.st_mtime);

	year2 = time2->tm_year+1900;
	month2 = time2->tm_mon + 1;
	day2 = time2->tm_mday;

	stat2_time = (time1->tm_hour*3600)+(time1->tm_min*60)+(time1->tm_sec);
}

// compare files' data size
void sizecmp(void)
{
	
 	int size1,size2;
 
 	//get text1,text2 data 

 	size1=(int)stat1.st_size; 
 	size2=(int)stat2.st_size; 
 	//get size of text1,text2 
 	
 	
 	//printf("=bigger %d,%d\n",size1,size2);
 	if(size1>size2) 
 	{ 
 		printf("%s is bigger \n\n","text1"); 
 	} 
 	else if(size1<size2)
 	{ 
 		printf("%s is bigger\n\n","text2"); 
 	} 
 	else
 	{
 		printf("filesize is same\n\n");
 	}
 	//size compare 

}

// compare files' block size
void blockcmp(void)
{
  	long long int file1 = (long long)stat1.st_blocks;
 	long long int file2 = (long long)stat2.st_blocks;
	printf("block compare\n");

	if(file1>file2) printf("text1 is bigger\n\n");
	else if(file1<file2) printf("text2 is bigger\n\n");
	else printf("same blocksize\n\n");
}

// compare files' modified date
void datecmp(void)
{
	printf("date compare\n");

	if(year1==year2){
		if(month1 == month2){
			if(day1 == day2){
				printf("same date.\n\n");
			}else{
				if(day1>day2){
					printf("%s is early.\n\n", "text2");
				}else{
					printf("%s is early.\n\n", "text1");
				}
			}
		}else{
			if(month1>month2){
				printf("%s is early.\n\n", "text2");
			}else{
				printf("%s is early.\n\n", "text1");
			}
		}
	}else{
		if(year1>year2){
			printf("%s is early.\n\n", "text2");
		}else{
			printf("%s is early.\n\n", "test1");
		}
	}		

}

// compare files' modified time
void timecmp(void)
{	
	printf("time compare\n");

	if(stat1_time == stat2_time){
		printf("same time\n");
	}else{
		if(stat1_time > stat2_time){
			printf("%s is early.\n\n", "text2");

		}else{
			printf("%s is early.\n\n", "text1");
		}
	}	
}

