/*
Name : Saran
Date : 18 Nov 2023
Project Title : Inverted Search
Project Objective : The main objective of this project is to a create database perform the display,search,save & update operations
Module : Data Structures 

*/

#include "search.h"

int main(int argc , char *argv[])
{

	int option;
	Search *head = NULL;
	char choice;

	main_node *HT[SIZE] = {NULL};

	/*Check if the Command-Line Argument passed*/

	if (argc < 2)
	{
		printf("Error: Pass ./a.out <file_1>..\n");
		return FAILURE;
	}
	else
	{

		if (file_validation(argv, argc, &head) == SUCCESS)
		{
			printf("Info: File Validation is successful\n");
			print_list(head);
			do
			{	/*Menu for the Operations*/
				
				printf("Enter the option:\n1.Create database\n2.Display database\n3.Search database\n4.Save database\n5.Update database\n6.Exit\n");
				scanf("%d", &option);

				switch (option)
				{
					case 1:
						{	//Create Database

							printf("Creating database...\n");

							if (create_database(HT,head) == SUCCESS) 
							{
								printf("Info: Database created successfully.\n");
							} 

							else 
							{
								printf("Error: Failed to create the database.\n");
							}
						}
						break;

					case 2:
						//Print Database

						printf("Displaying database...\n");

						if(display_database(HT)==SUCCESS);
						
						break;

					case 3:
						 // Search Database

						printf("Searching database...\n");

						printf("Enter the word to be searched : ");
						char search_word[20];
						scanf("%s", search_word);

						if(search_database(HT, search_word)==FAILURE)
						{
							printf("Info : Word is not present\n");
						}

						break;

					case 4:
						// save
						printf("Saving database...\n");
						
						if(save_database(HT)==SUCCESS)
						{	
							printf("INFO : Data Saved Successfully\n");
						}
						
						else
						{	
							printf("INFO : Unable to save the data to the database\n");
						}
						break;

					case 5:
						// update
						printf("Enter the valid file : \n");
						char file[20];
						scanf("%s",file);
						if(update_database(file,HT)==SUCCESS)
						{
							printf("Info : Updated Successfully\n");
						}
						else
						{
							printf("Info : Failed to Update\n");
						}
						break;

					case 6:
						printf("Exiting...\n");
						exit(0);
						break;

					default:
						printf("Enter the proper option!\n");
						break;
				}
				printf("Do you want to continue? (y/n): ");
				scanf(" %c", &choice);

			} while (choice != 'n' && choice != 'N');
		}
	}
	//	printf("\n");
	return 0;
}
