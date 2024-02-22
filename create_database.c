#include"search.h"

/*Function Definition for the Create database*/

int create_database(main_node **HT,Search *head) 
{

	if(head==NULL)
	{

		return FAILURE;
	
	}
	
	while(head)
	{
			

		FILE *fp = fopen(head->filename, "r");
		if (fp == NULL) 
		{
			printf("Error: Unable to open the file\n");
			return FAILURE;
		}

		char buff[50];
		int index;
		char ch;
		while (fscanf(fp, "%s", buff) >0) 
		{	
			ch=buff[0];
			if((ch >= 97 && ch  <= 122) || (ch>=65 && ch<=90))
			{
				index = tolower(ch) - 97;
			}

			else
			{
				index =26;	
			}


			if(HT[index]==NULL)
			{
				//printf("4");
				
				/*Create a main & sub node update the content*/
				
				main_node *Mnode=malloc(sizeof(main_node));
				sub_node *Snode=malloc(sizeof(sub_node));
				strcpy(Mnode->word,buff);
				Mnode->file_count=1;
				Mnode->main_link=NULL;
				Snode->word_count=1;
				strcpy(Snode->filename,head->filename);
				Snode->sub_link=NULL;
				Mnode->sub_link=Snode;
				HT[index]=Mnode;

			}
			else
			{
				main_node *m=HT[index];
				main_node *mp=NULL;
				while(m)
				{
		
					if(strcmp(m->word,buff)==0)
					{
						if(strcmp(m->sub_link->filename,head->filename)==0)
						{
							m->sub_link->word_count++;
						}
						else
						{
							sub_node *s=m->sub_link;
							sub_node *sp=NULL;
							while(s)
							{
			
								if(strcmp(s->filename,head->filename)==0)
								{
									s->word_count++;
									break;
								}
								else
								{
									sp=s;
									s=s->sub_link;
								}


							}


							/*Create a Sub node*/
							if(s==NULL)
							{
								sub_node *n=malloc(sizeof(sub_node));
								n->word_count=1;
								strcpy(n->filename,head->filename);
								n->sub_link=NULL;
								sp->sub_link=n;
								m->file_count++;
							}
						}
						break;

					}


					else
					{
						mp=m;
						m=m->main_link;

					}
				}
				
				/*Create a main node*/
				if(m==NULL)
				{
					main_node *mn=malloc(sizeof(main_node));
					sub_node *sn=malloc(sizeof(sub_node));
					strcpy(mn->word,buff);
					mn->file_count=1;
					mn->main_link=NULL;
					sn->word_count=1;
					strcpy(sn->filename,head->filename);
					sn->sub_link=NULL;
					mn->sub_link=sn;
					mp->main_link=mn;	

				}
			}
		}
		fclose(fp);
		head=head->link;


	
	}
	printf("<<<<<<<<Database created Successfully>>>>>>>>\n");
	return SUCCESS;
}



