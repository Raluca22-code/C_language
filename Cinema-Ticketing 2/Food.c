#include "InOut.h"
#include <stdio.h>

void appetizer_file(float *price)
{
    float price_list[20];
    int food = 0;

     price_list[1] = 8.95;
     price_list[2] = 7.50;
     price_list[3] = 10;
     price_list[4] = 6;
     price_list[5] = 8;

     printf("Here is the Appetizer menu:\n");

     printf("~1.Bruschetta\n Grilled country bread with Roma tomatoes, olive oil, garlic and basil. %.2f $\n", price_list[1]);
     printf("~2.Stuffed Mushrooms\n Mushrooms caps baked with a filling of three choice cheeses, breadcrumbs and clams. %.2f\n", price_list[2]);
     printf("~3.Shrimp Scampi\n Jumbo shrimp sauteed in white wine, butter and garlic.\n",price_list[3]);
     printf("~4.French Fries\n Hand cut wedges of Yukon Gold potatoes fried in canola oil and tossed with truffle sea salt.\n",price_list[4]);
     printf("~5.Fried Calamari\n Breaded calamari, lightly fried in canola oil. Served with a side of marinara.\n",price_list[5]);
     scanf("%d", &food);
    while(food != 0)
    {
        (*price) += price_list[food];
        scanf("%d", &food);
    }
}

void drinks_file(float *price)
{
     float price_list[20];
     int food = 0;

     price_list[1] = 3.50;
     price_list[2] = 3.50;
     price_list[3] = 4.00;
     price_list[4] = 5.75;
     price_list[5] = 9.00;
     price_list[6] = 15.80;

     printf("Here is the drinks menu:\n");

     printf("~1.Coca-Cola.\n",price_list[1]);
     printf("~2.Orange Soda.\n",price_list[2]);
     printf("~3.Esspresso.\n",price_list[3]);
     printf("~4.Latte.\n",price_list[4]);
     printf("~5.Wine(Rose/Red/White).\n",price_list[5]);
     printf("~6.Cocktails(Ask the bartender for more information).\n",price_list[6]);

    scanf("%d", &food);
    while(food != 0)
    {
        (*price) += price_list[food];
        scanf("%d", &food);
    }
}

void maincourse_file(float *price)
{
    float price_list[20];
    int food = 0;

    price_list[1] = 12.30;
    price_list[1] = 12.30;
    price_list[1] = 14.50;
    price_list[1] = 14;
    price_list[1] = 22;

     printf("Here is the Main-Course menu:\n");

     printf("Pasta:\n");
     printf("~1.Fettuccine Alfredo\n Fresh, house-made fettucine tossed in a thick and creamy Alfredo sauce. %.2f $\n", price_list[1]);
     printf("~2.Cheese Ravioli\n Delicious cheese-stuffed ravioli topped with marinara and a trio of melted cheeses. %.2f\n", price_list[2]);

     printf("Entrees:\n");
     printf("~3.Chicken Parmesan\n Tender chicken breasts, lightly breaded and baked with our signature cheese and marinara sauce.\n",price_list[3]);
     printf("~4.Chicken with Wild Mushrooms\n Tender roasted chicken, bathed in a rich cream sauce and served under a layer of wild mushrooms and garlic.\n",price_list[4]);
     printf("~5.Coho Salmon\n Wild-caught coho salmon stuffed with Bay Shrimp and Dungeness Crab.\n",price_list[5]);
     scanf("%d", &food);

    while(food != 0)
    {
        (*price) += price_list[food];
        scanf("%d", &food);
    }
}
void salads_file(float *price)
{
     float price_list[20];
     int food = 0;

     price_list[1] = 12;
     price_list[2] = 15.50;
     price_list[3] = 12;

     printf("Here is the salads menu:\n");

     printf("~1.Greek salad\n With fresh cucumbers, tomatoes and peppers, feta, olives and olive oil.\n",price_list[1]);
     printf("~2.Asian style salad\n With chicken, Chinese cabbage, red cabbage, molasses and spices.\n",price_list[2]);
     printf("~3.Caesar salad\n With romaine lettuce and croutons served with a dressing containing olive oil, lemon juice, raw egg, parmesan cheese, and seasonings.\n",price_list[3]);
     scanf("%d", &food);

    while(food != 0)
    {
        (*price) += price_list[food];
        scanf("%d", &food);
    }
}
void desserts_file(float *price)
{
     float price_list[20];
     int food = 0;

     price_list[1] = 10.35;
     price_list[2] = 7;
     price_list[3] = 5.50;

     printf("Here is the desserts menu:\n");

     printf("~1.Crepes\n Our special french crepes with cream cheese, roasted nuts and the best honey in the area.\n",price_list[1]);
     printf("~2.Apple strudel\n A delight, served with vanilla sauce and vanilla ice cream.\n",price_list[2]);
     printf("~3.The Dark Bite\n Donut glazed with a delicious dark chocolate and delicate lines of milk chocolate.\n",price_list[3]);


    scanf("%d", &food);
    while(food != 0)
    {
        (*price) += price_list[food];
        scanf("%d", &food);
    }
}


