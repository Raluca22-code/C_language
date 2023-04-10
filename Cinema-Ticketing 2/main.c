
/**********************************************************/
/* Cinema Ticketing                                       */
/* Copyright:                                             */
/* License:                                               */
/* Authors: Nagy Timea, Nemes Raluca                      */
/* Version: 1                                             */
/* Updates:                                               */
/**********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "InOut.h"
#include "InOut.c"
#include "Searches.h"
#include "MatrixManagement.c"

int main()
{
    Concert concert_list[50];
    int n = 0 , nr = 0;
    char f = '\0';

    read_file(&concert_list, &n);

    srand(time(NULL));
    fill_matrix(n, concert_list);

   // display_file(movie_list, n);

    main_menu(concert_list, n);

    printf("\nPress any key to exit!\n");
    f = getch();
    exit(EXIT_SUCCESS);
    return 0;
}
