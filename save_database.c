#include"search.h"

/*Function definition to save database*/
int save_database(main_node *HT[])
{
	char file[SIZEOFFILE];
	printf("Enter the filename : ");

	scanf("%s",file);				/*Reads the file name*/
	
	if(strstr(file,".txt"))		
	{
		FILE *fptr = fopen(file,"w"); 
		
		if(fptr == NULL)
		{	
			printf("Info : Failed to open the file\n");
			return FAILURE;
		}	

		int i;
		
		for(i = 0;i < SIZE ; i++)
		{
			if(HT[i] != NULL)
			{
				main_node *m  = HT[i];
				
				while(m)		/*Traverse the main temp*/
				{	
					fprintf(fptr,"#%d;%s;%d",i,m->word,m->file_count);
					sub_node *s = m->sub_link;
					
					while(s)
					{	
						fprintf(fptr,";%s;%d",s->filename,s->word_count);
						s = s->sub_link;
					}
					
					fprintf(fptr,"#\n");
					m = m->main_link;
				}
			}
		}
	
		fclose(fptr);
	}
	
	else
	{	/*Prints the error Message*/
		printf("Error : Please Enter the <.txt> format file\n");
		return FAILURE;
	}
}
