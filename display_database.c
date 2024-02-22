#include"search.h"

/*Function definition of display database*/

int display_database(main_node *HT[])
{
    printf("[index]		[word]  [Filecount] file/s: File: [name]  [wordcount] \n");

    int i;
    for (i = 0; i < SIZE; i++)
    {
        main_node *m_temp = HT[i];
        
        while (m_temp != NULL)
        {
         	/*Prints the details of file*/
            printf("[%d]	[%s]  %d file/s: ", i, m_temp->word, m_temp->file_count);
            sub_node *s_temp = m_temp->sub_link;

            while (s_temp != NULL)
            {
               
                printf("File : %s, %d ", s_temp->filename, s_temp->word_count);
                s_temp = s_temp->sub_link;
            }
            printf("\n");
            m_temp = m_temp->main_link;
        }
    }
    return SUCCESS;
}

