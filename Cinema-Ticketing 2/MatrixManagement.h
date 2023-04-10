#ifndef MATRIXMANAGEMENT_H_INCLUDED
#define MATRIXMANAGEMENT_H_INCLUDED

void print_matrix(char[100]);
void allocate_seat(Concert concert_list[100], int i, int places_no);
void get_row_and_column(int a, int b, int j);
void check_title(Concert concert_list[100], char title[100], int n, int places_no, float *price);
int random_number();
void fill_matrix(int n, Concert concert_list[]);

#endif // MATRIXMANAGEMENT_H_INCLUDED
