#ifndef SEARCH_Hi
#define SEARCH_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

#define SUCCESS 0
#define FAILURE -1
#define SIZE 27
#define SIZEOFFILE 30

typedef struct node
{
    char filename[30]; 
    struct node *link;
}Search;


typedef struct sub_node
{
	int word_count;
	char filename[20];
	struct sub_node *sub_link;	
}sub_node;


typedef struct main_node
{
	int file_count;
	char filename[20];
	char word[20];
	struct main_node *main_link;
	struct sub_node *sub_link;
}main_node;

//main_node *HT[SIZE];

void print_list(Search *head);
 
int file_validation(char *argv[], int argc, Search **head);
int insert_last(Search **head, char *filename);
//int create_main_node(main_node **HT, char buff, char *filename, int index);
//int create_sub_node(main_node *current, char *filename) ;
int create_database(main_node **HT,Search *head) ;
int display_database(main_node *HT[]);
int search_database(main_node *HT[], char *buff);
int save_database(main_node *HT[]);
int update_database(char *,main_node **);

#endif
