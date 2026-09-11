#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main(void){
	DIR *dir = opendir("/proc");

	if(dir == NULL){
		perror("opendir");
		return 1;
	}

	struct dirent *entry;

	while((entry = readdir(dir)) != NULL){

		if(entry->d_name[0] >= '0' && entry->d_name[0] <= '9'){
			printf("%s\n", entry->d_name);
		}
	}

	closedir(dir);

	return 0;

}
