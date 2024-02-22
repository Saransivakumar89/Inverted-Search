#include"search.h"

void print_list(Search *head)
{
	if (head == NULL)                         //Checks if list is empty 
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head)		                  //Traversing the loop
	    {
		    printf("%s -> ", head -> filename);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}
