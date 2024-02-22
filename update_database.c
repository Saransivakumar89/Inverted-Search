#include"search.h"

/*Function definition to Update database*/

int update_database(char *file,main_node **HT)        
{
	FILE *fp=fopen(file,"r");      

	if(fp == NULL)                          
	{
		printf("Info : Only saved database file that should be existed to Entered\n");
		return FAILURE;
	}

	if(strstr(file,".txt"))              
	{
		char a,b;
		fscanf(fp,"%c",&a);               

		fseek(fp,-2,SEEK_END);
		fscanf(fp,"%c",&b);              

		rewind(fp);

		if(a=='#' && b=='#')                
		{

			char line[100];
			char *ind=malloc(20*sizeof(char));

			while(fscanf(fp,"%s",line)>0)   
			{

				ind=strtok(line,"#;");        

				int index=atoi(ind);         

				main_node *temp = malloc(sizeof(main_node));

				if(temp==NULL)
				{
					return FAILURE;
				}

				temp->main_link=NULL;


				if(HT[index]==NULL)
				{

					HT[index]=temp;
				}
				else
				{

					main_node *m_temp = HT[index];

					while( m_temp->main_link!=NULL)             
					{
						m_temp =m_temp->main_link;
					}
					m_temp->main_link=temp;           


				}
				char *word=malloc(30);

				word=strtok(NULL,"#;");       

				strcpy(temp->word,word);      


				char *fcount,*fname,*wcount;
				fcount=malloc(20);
				fname=malloc(20);
				wcount=malloc(20);

				fcount=strtok(NULL,"#;");         
				int fc=atoi(fcount);  			 

				temp->file_count=fc;               

				int i;
				sub_node *sprev=NULL;
				for(i=0;i<fc;i++)                  
				{

					sub_node *subnode=malloc(sizeof(sub_node));
					if(subnode==NULL)
					{
						return FAILURE;
					}
					subnode->sub_link=NULL;



					fname=strtok(NULL,"#;");         
					strcpy(subnode->filename,fname);       

					wcount=strtok(NULL,"#;");       
					int wc=atoi(wcount);                

					subnode->word_count=wc;                
					if (i==0)              
					{
						temp->sub_link=subnode;         
					}
					else
					{
						sprev->sub_link=subnode;         
					}

					sprev=subnode;              


				}

			}

			fclose(fp);
			printf("````Updated Successfully````\n");          

			return SUCCESS;
		}

		else
		{   
			printf("Info : Enter the  valid file\n");
			return FAILURE;
		}


	}

	else
	{
		printf("Info : Enter the valid file \n");
		return FAILURE;
	}
}
