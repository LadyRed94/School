#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_names(){

   char f_name[256];
	printf("Enter your first name:\n");
	scanf("%s",f_name);
   
   size_t length = strlen(f_name);
   f_name[length] = ' ';
   f_name[length+1] = '\0';
   
   char l_name[256];
	printf("Enter your last name:\n");
	scanf(" %s",l_name);
   
   char *full_name;
   
   int f, l;
   
   f = strlen(f_name);
   l = strlen(l_name);
   
   full_name = malloc(sizeof(char)*f+sizeof(char)*l);
   full_name = strcat(f_name, l_name);
	
	printf("%s\n", full_name);
}

void main(){
	get_names();
}