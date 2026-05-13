#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// this stuff is done only to secondary branch i suppose ! 

void fun(FILE *p, int r, int x , char namee[30], char *name[20], int *Quantity, long double *price);
struct Item
{
  long double price;
  int Quantity;
  long long ID;
  char name[20];

};
struct Customer
{

  char name[20];
  long long ID;
  int money;
  struct Cart
  {
    char item1[20],item2[20],item3[20],item4[20],item5[20],item6[20],item7[20],item8[20],item9[20],item10[20];
  }cart;



}; // this is made because every single customer has his own profile , hence we need a file to store the data of customers
void fillData(); // this creates the inventory.txt for only one time at the beginning of the program
void whichMode(char d,  bool *customerMode , bool *storageMode, bool *cashierMode);
void displayMenu(); // this draws a table in the screen
void makeTable(); // this creates a table in the inventory.txt


int main()
{

  fillData();
  printf("Enter s to manage the storage , c if you are a customer,  r for managing the register\n");
  char d ;

  while ((scanf("%c" , &d)) && !( (d== 'c') || (d == 'C') || (d == 'S') || (d== 's') || (d=='r') || (d == 'R')))
  {
    printf("You entered a wrong letter, please try again\n");

  }



  bool  customerMode = 0, storageMode = 0 , cashierMode = 0;
  whichMode(d,  &customerMode, &storageMode, &cashierMode);


  // the whole program is running within an infinite loop and this loop n times which n
  // is the number of customers
  // we assume that in our customer.txt we only can store up to 10 customers as maximum
   if (customerMode)
  {
     // part 1 : how many customers are there ?

     int numberOfCustomers;

     while (scanf("%i" , &numberOfCustomers) && (!((numberOfCustomers >=1)  && (numberOfCustomers<=10))) )
     {
       printf("Invalid number, please try again");
     }

     // part 2: take each customer details and store it in the customer.txt properly
     for (int T= 1; T<= numberOfCustomers; T++)
     {
       struct Customer customer;




       printf("Hello customer %i , please enter your details bellow\n"
              "Name: " , T);
       scanf("%s" , customer.name);
       printf("\nID: ");
       scanf("%llu", &customer.ID);

       //part 3 : the customer starts picking items and puts them in his cart
       // we assume that the cart can take no more than 10 units


       printf("\n");
       displayMenu();
       printf("\n");
       // how many product = n
       int distinctItems;
       printf("How many distinct items you want to buy: ");

       bool doNotWantToBuy = 0 ;
       while (scanf("%i" , &distinctItems) && (!((distinctItems>=1) && (distinctItems<=10))) )
       {
         if (distinctItems==0)
         {
           printf("Thank you for you visit, we wish to see you soon!\n");
           doNotWantToBuy = 1;
           break;
         }
         printf("Invalid number, please try again");
       }

       if (doNotWantToBuy)
       {
         continue;
       }


       printf("Please enter only the number of the item\n");


       // for each item , we will go take it from the inventory and do logic concerning that
       for (int i=1; i<=distinctItems; i++)
       {
         char x;
         printf("Item %i: ", i);
         scanf("%c" , &x);
         char name[30];
         struct Item item;

         fun(,20,x,"inventory.txt", &item.name, &item.Quantity, &item.price);





         //what will happen after we get the price and quantity and name?
         item.Quantity = 3330;










       }


     }




  }
  else if (storageMode)
  {

    // part 1: security checking , we assume that there is only one storage employee in larry cool
    char password[20] ;
    long long ID;
    printf("Enter your ID and password\n");
    printf("ID: ");
    scanf("%lld", &ID);
    printf("\nPassword: ");
    scanf("%s", password);

  }
  else if (cashierMode)
  {

  };












}
void whichMode(char d,  bool *customerMode , bool *storageMode, bool *cashierMode)
{

    if (d == 'r' || d == 'R')
  {
    *cashierMode = 1;
  }

  else if (d == 'c' || d == 'C')
  {
  *customerMode = 1;
  }
  else if (d == 's' || d == 'S')
  {
    *storageMode = 1;
  }


};
void fillData()
{

};

void fun(FILE *p, int row, int x , char namee[30] , char *name[20], int *Quantity, long double *price )
{

};


