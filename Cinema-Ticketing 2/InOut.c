/**********************************************************/
/* InOut.c - See InOut.h for copyright and info           */
/**********************************************************/
#include <time.h>
#include <stdlib.h>

#include "InOut.h"
#include "Searches.c"
#include "MatrixManagement.h"

//**********************************************
/* This function displays the menu
//**********************************************/
void main_menu(Concert concert_list[100], int n)
{
     char c = '/0';
     printf("Welcome to the Concert hall!\n");
     label2:
     printf("\nWhat would you like to do? Press the correct key!\n(t) Select concerts by type (VIP, C - common ticket, L - low budget)\n(d) Select concerts by date\n(g) Select concerts by genre\n");
     printf("(s) Stop\n\n");
     c = getch();
     while(c != 's')
     {
         switch(c)
         {
             case 't': type_file(concert_list, n); goto label2;
                       break;
             case 'd': date_file(concert_list, n); goto label2;
                        break;
             case 'g': genre_file(concert_list, n); goto label2;
                        break;
             default: printf("Pressed the wrong key! Try again, please.\n\n"); c = getch(); goto label2;
                        break;
         }
     }
}

//**********************************************
/* This function reads data from Movies.txt
//**********************************************/
void read_file(Concert concert_list[100], int *n)
{
    int  i = 0;
    char c;
    char buffer[100];

    FILE *file_ptr;
    file_ptr = fopen("Concert.txt", "r");

    while((c = fgetc(file_ptr)) != EOF)
    {
        fgets(buffer, sizeof(buffer), file_ptr);
        sprintf(concert_list[i].name, "%c%s", c, buffer);                           //  CITIM NUMELE
        concert_list[i].name[strlen(concert_list[i].name) - 1] = '\0';

        fgets(buffer, sizeof(buffer), file_ptr);
        sprintf(concert_list[i].type, "%s", buffer);                                //  CITIM TYPE
        concert_list[i].type[strlen(concert_list[i].type) - 1] = '\0';

        fgets(buffer, sizeof(buffer), file_ptr);
        sprintf(concert_list[i].genre, "%s", buffer);                               //  CITIM GENUL
        concert_list[i].genre[strlen(concert_list[i].genre) - 1] = '\0';

        fgets(buffer, sizeof(buffer), file_ptr);
        sprintf(concert_list[i].date, "%s", buffer);                                //  CITIM DATA
        concert_list[i].date[strlen(concert_list[i].date) - 1] = '\0';

        fgets(buffer, sizeof(buffer), file_ptr);
        sprintf(concert_list[i].room, "%s", buffer);                                //  CITIM SALA
        concert_list[i].room[1] = '\0';

        i++;
    }

    (*n) = i;
    fclose(file_ptr);
   // printf("Files read succesfully!\n");
}

//********************************************************************************************
/* This function displays all of the elements from the file, to verify if it's read correctly
//********************************************************************************************/
void display_file(Concert concert_list[100], int n)
{
    printf("| Name \t\t\t");
    printf("| Type \t");
    printf("| Genre\t\t");
    printf("| Date \t\t");
    printf("| Room \t\n");
    printf("----------------------------------------------------------------------------------------\n");
    for(int i = 0; i < n; i++)
    {
        printf("%s\t", concert_list[i].name);
        printf("| %s\t", concert_list[i].type);
        printf("| %s\t", concert_list[i].genre);
        printf("| %s\t", concert_list[i].date);
        printf("| room %s\t\n", concert_list[i].room);
    }
}

//*******************************************************
/* This function is called after each search (Searches.c)
/* Gets the data for reserving a concert ticket
//*******************************************************/
void choose_concert(Concert concert_list[100], int n)
{
    char  c[10] = "\0", s = '\0', f = '\0';
    int   seats_no = 0;
    char  title[100] = "\0";
    float price = 0.0f;

    printf("\nWould you like to select and reserve seats for any of the concerts above? yes/no\n");
    scanf("%s", c);
    if(strcmp(c, "yes") == 0)
    {
        printf("Enter the title of the concert you would like to attend: ");
        scanf("%s", title);
        fflush(stdin);
        for(int cnt = 0; cnt <= strlen(title); cnt++)
            title[cnt] = toupper(title[cnt]);
        printf("How many seats would you like to reserve?\n");
        scanf("%d", &seats_no);
        fflush(stdin);
        while(seats_no < 1 || seats_no > 100)
        {
            printf("\nThe entered number is not correct!\nPlease try again!\n");
            scanf("%d", &seats_no);
            fflush(stdin);
        }
        check_title(concert_list, title, n, seats_no, &price);
        printf("\nWould you like to assure some food and drink for your concert? y/n");
        s = getch();
        if(s == 'y')
        {
            printf("\n\nPlease enter the number of the appetizers you wish to eat. When you are ready press 0. If you do not want any, just press 0.\n");
            appetizer_file(&price);
            printf("\nPlease enter the number of the drink/drinks you wish to eat. When you are ready press 0. If you do not want any, just press 0.\n");
            drinks_file(&price);
            printf("\nPlease enter the number of the main-course you wish to eat. When you are ready press 0. If you do not want any, just press 0.\n");
            maincourse_file(&price);
            printf("\nPlease enter the number of the salad you wish to eat. When you are ready press 0. If you do not want any, just press 0.\n");
            salads_file(&price);
            printf("\nPlease enter the number of the dessert/desserts you wish to eat. When you are ready press 0. If you do not want any, just press 0.\n");
            desserts_file(&price);
        }
        printf("\nThank you for reserving your seat! You will have to pay %.2f $. Your confirmation number is: %4.d.\nPlease go with your confirmation number, with 15 - 20 minutes before the movie to the cinema cashier and pay.\n", price, random_number()%4000);
        printf("Press any key to exit!\n");
        f = getch();
        exit(EXIT_SUCCESS);
    }
}

//*******************************************************
/* This function displays the prices of the concert tickets
//*******************************************************/
void display_prices()
{
    float price_list[10];

    price_list[1] = 100;
    price_list[2] = 75;
    price_list[3] = 55;

    printf("\nHere are the prices for the concert tickets:\n ~VIP  %.2f$\n ~C  %.2f$\n ~L %.2f$\n", price_list[1], price_list[2], price_list[3]);
}
