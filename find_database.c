#include"search.h"

/*Function definition to search database*/

int search_database(main_node *HT[], char *buff)
{
	int index;
	char ch;

	/*Finding the index*/

	ch=buff[0];

	if((ch >= 97 && ch  <= 122) || (ch>=65 && ch<=90))
	{
		index = tolower(ch) - 97;		
	}

	else
	{
		index =26;	
	}

	if(HT[index] ==  NULL)
	{
		return FAILURE;
	}
	/*Initialize the index to main node*/
	main_node *m = HT[index];

	while(m)
	{	
		if(strcmp(m->word,buff) == 0)		/*COmpare the word and buff*/
		{
			
			printf("\n[%d] WORD \"%s\" is present %d files\n",index,buff,m->file_count);
			sub_node *s = m->sub_link;

			while(s)
			{

				printf("%s --> %d\n",s->filename,s->word_count);		/*Prints the filename and word count*/
				s=s->sub_link;
			}

			printf("<<<<<<<<<<<<<<<<<<<Details of the Word printed>>>>>>>>>>>>>>>>>>>>\n");
			return SUCCESS;
		}
		m = m->main_link;
	}
	return FAILURE;

}



