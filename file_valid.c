#include"search.h"

/* Function Defintion to Validate the file*/

int file_validation(char *argv[], int argc, Search **head)
{
	
	int i,size = 0;				

	for(i = 1; i < argc ; i++)
    {

		if(strstr(argv[i],".txt") == NULL)
		{
			printf("Error : File %s should be in <.txt> format\n",argv[i]);
			return FAILURE;
		}
		
		else
		{
			FILE *fp = fopen(argv[i],"r");

			//Checks if the file exists or not
			
			if(fp == NULL)
			{	
				printf("Error : %s is doesn't exist\n",argv[i]);
				return FAILURE ;
			}
			
			fseek(fp, 0 , SEEK_END);	
			size = ftell(fp);
			rewind(fp);
			
			//Checks if the file has any content

			if(size == 0)
			{
				printf("Error : %s  has No Content\n",argv[i]);
			//	free(argv[i]);
				//return FAILURE ;
				continue;
			}
			
			fclose(fp);

            //checks if the filename is inserted

			if(insert_last(head, argv[i]) ==  FAILURE)
			{
				printf("Error : Unable to Insert, Duplicate found\n");	
				//return FAILURE;
			}
			
		}
	}
	return SUCCESS;
}

