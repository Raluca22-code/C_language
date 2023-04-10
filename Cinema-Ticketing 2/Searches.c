/**********************************************************/
/* Searches.c - See Searches.h for copyright and info     */
/**********************************************************/
#include <stdbool.h>
#include "Searches.h"

void type_file(Concert concert_list[100], int n)
{
   printf("What type of concert would you like to attend?\n");
   char type[5] = "\0";
   scanf("%s", type);
   for(int cnt = 0; cnt <= strlen(type); cnt++)
        type[cnt] = toupper(type[cnt]);
   while (!((strcmp(type, "VIP") == 0) || (strcmp(type, "C") == 0) || (strcmp(type, "L") == 0)))
   {
            printf("The entered string is not a ticket type! Please try again!\n");
            scanf("%s", type);
   }
   bool exist_concert = 0;
   printf("\nName \t\t");
   printf("| Genre\t");
   printf("| Date \t\t");
   printf("| Room \t\n");
   for(int i = 0; i <= n; i++)
   {
        if (strcmp(concert_list[i].type, type) == 0)
        {
            exist_concert = 1;
            printf("%s\t", concert_list[i].name);
            printf("| %s\t", concert_list[i].genre);
            printf("| %s\t", concert_list[i].date);
            printf("| room %s\t", concert_list[i].room);

        }
   }
  if(exist_concert!=1)
    {printf("Right now there are no tickets of type %s, please search for another type!", type);
   display_prices();}
   choose_concert(concert_list, n);
}


void date_file(Concert concert_list[100], int n)
{
    bool exist_concert = 0;
    char date[20] = "\0";
    printf("Tell us the date you would like to see the movie (yyyy/mm/dd)\n");
    label:
    scanf("%s", date);
    for(int i = 0; i <= n; i++)
        if(strcmp(concert_list[i].date, date) == 0)
            exist_concert = 1;
    if(exist_concert)
    {
        printf("\nName \t\t\t");
        printf("| Genre\t\t");
        printf("| Type \t");
        printf("| Room   ");
    }
    exist_concert = 0;
       for(int i = 0; i <= n; i++)
       {
           if(strcmp(concert_list[i].date, date) == 0)
           {
                exist_concert = 1;
                printf("%s\t", concert_list[i].name);
                printf("| %s\t", concert_list[i].genre);
                printf("| %s\t", concert_list[i].type);
                printf("| room %s ", concert_list[i].room);
           }
       }
       if(!exist_concert)
       {
           printf("Right now there are no concerts on %s available, please enter another date!\n", date);
           goto label;
       }
       display_prices();
       choose_concert(concert_list, n);
}

void genre_file(Concert concert_list[100], int n)
{

    printf("The genre of the concert you would like to see (Hip Hop, Country, Rock, Jazz, Music for Kids, Pop, Disco, Classical)\n");
    char genre[20] = "\0";
    scanf("%s", genre);
    genre[0] = toupper(genre[0]);
    while (!((strcmp(genre, "Hip Hop") == 0) || (strcmp(genre, "Country") == 0) || (strcmp(genre, "Rock") == 0) || (strcmp(genre, "Jazz") == 0) || (strcmp(genre, "ChildrenMusic") == 0) || (strcmp(genre, "Pop") == 0) || (strcmp(genre, "Disco") == 0) || (strcmp(genre, "Classical") == 0)))
     {
         printf("The genre is not correct. Please try again\n");
         scanf("%s", genre);
     }
   printf("The %s concerts are:\n", genre);
   bool exist_concert = 0;
   printf("\nName\t\t\t");
   printf("| Type\t");
   printf("| Date\t\t");
   printf("| Room\t\t\n");

   for(int i = 0; i <= n; i++)
   {
       if((strcmp(concert_list[i].genre, genre) == 0))
       {
            exist_concert = 1;
            printf("%s\t", concert_list[i].name);
            printf("| %s\t", concert_list[i].type);
            printf("| %s\t", concert_list[i].date);
            printf("| room %s\t", concert_list[i].room);

       }

   }
   if(!exist_concert)
     printf("Right now there are no concerts of genre %s available, please enter another genre!", genre);
   display_prices();
   choose_concert(concert_list, n);
}



