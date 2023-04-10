#include "MatrixManagement.h"


//****************************************************
/* This function prints the places available in a room
//****************************************************/
void print_seats(char matrix[100])
{
    printf("\n   1 2 3 4 5 6 7 8 9\n");
    for(int i = 0; i < 9; i++)
    {
        printf("%d: ", i+1);
        for(int j = 0; j < 9; j++)
        {
            printf("%d ", matrix[i*9+j]);
        }
        printf("\n");
    }
    printf("\n");
}

//*****************************************************************
/* This function allocates a seat for the client in the concert hall
//*****************************************************************/
void allocate_seat(Concert concert_list[100], int i, int places_no)
{
    int a = 0, b = 0;
    printf("\nThe concert you chose is: %s\n", concert_list[i].name);
    printf("The available seats for that concert are listed below (1 - occupied, 0 - free):\nPlease enter the row and the column of the selected seats!\n");
    print_seats(concert_list[i].room_places);
    for(int j = 1; j <= places_no; j++)
    {
        get_row_and_column(&a,&b,j);
        if (concert_list[i].room_places[(a-1)*9+(b-1)] == 0)
            concert_list[i].room_places[(a-1)*9+(b-1)] = 1;
        else
        {
            printf("\nThis seat is already taken! Please choose another one!\n");
            j--;
        }
    }
    printf("The updated seats are:\n");
    print_seats(concert_list[i].room_places);
}

//********************************************************
/* This function gets the input for the row and the column
//********************************************************/
void get_row_and_column(int a, int b, int j)
{
    printf("Row of seat %d:", j); scanf("%d", a);
    printf("Column of seat %d:", j); scanf("%d", b);
}

//*************************************************************************
/* This function checks if the entered title can be found in the concert list
/* Adds the correct amount of money to price variable
//**************************************************************************/
void check_title(Concert concert_list[100], char title[100], int n, int seats_no, float *price)
{
    char buffer[100] = "\0";
    bool breaak = 0;
    for(int i = 0; i < n && breaak == 0; i++)
    {
        strcpy(buffer, concert_list[i].name);
        for(int cnt = 0; cnt <= strlen(buffer); cnt++)
            buffer[cnt] = toupper(buffer[cnt]);
        buffer[strlen(title)] = '\0';
        if(strcmp(title, buffer) == 0)
        {
            allocate_seat(concert_list, i, seats_no);
            for(int g = 1; g <= seats_no; g++)
            {
                if (strcmp(concert_list[i].type, "VIP") == 0)
                    (*price) = (*price) + 100.0;
                if (strcmp(concert_list[i].type, "C") == 0)
                    (*price) = (*price) + 75.0;
                if (strcmp(concert_list[i].type, "L") == 0)
                    (*price) = (*price) + 55.0;
            }
            breaak = 1;
        }
    }
    if(!breaak)
        printf("\nThe entered title is not correct! Please try again.\n");
}

//*****************************************
/* This function generates a random number
//*****************************************/
int random_number()
{
    srand(time(NULL));
    int r = rand();
    return r;
}

//********************************************************************************
/* This function fills the matrix which contains the seats occupied for the concert
/* with random numbers between 1 and 0 (more 0`s than 1`s)
//********************************************************************************/
void fill_matrix(int n, Concert concert_list[])
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                int x = rand()%3;
                if(x == 1)
                    concert_list[k].room_places[i*9+j] = 1;
                else
                if(x == 0)
                    concert_list[k].room_places[i*9+j] = 0;
                else
                    concert_list[k].room_places[i*9+j] = 0;
            }
        }

    }
}
