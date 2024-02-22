#include"search.h"

/*Function Definition for insert last*/

int insert_last(Search **head, char *filename)
{
	Search *new = malloc(sizeof(Search));	
	
	if( new == NULL )
	{
		return FAILURE;
	}
	
	//Update the filename
    strcpy(new->filename, filename);	
       
	new->link = NULL;
	
	if(*head == NULL)
	{
		*head = new;
		return SUCCESS;	
	}

	Search *temp = *head;	
	Search *prev=NULL;
	while(temp)
	{
		//Check for the duplicates
		if(strcmp(temp->filename, filename) == 0)
		{
			free(new);
			return FAILURE;
		}
		prev=temp;
		temp = temp->link;
	}
	
	prev->link = new;

	return SUCCESS;
}

