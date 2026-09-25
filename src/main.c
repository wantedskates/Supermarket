#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void getItemData(FILE *p, int r, int x , char namee[30], char *name[20], int *Quantity, long double *price);

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
  int ID;
  int money;
  struct Cart
  {
    char item1[20],item2[20],item3[20],item4[20],item5[20],item6[20],item7[20],item8[20],item9[20],item10[20];
  }cart;



}; 
void whichMode(char d,  bool *customerMode , bool *storageMode, bool *cashierMode);

int nDigits (int a);
void makeInventory(FILE *p );
void makeCustomerDataSet( FILE *p , int row);
void displayMenu();
void jumpAddName( char name[20] , int NO , char fileName[20]);


int main()
{



  makeInventory();
 


  printf("Enter s to manage the storage , c if you are a customer,  r for managing the register\n");
  char d ;

  while ((scanf("%c" , &d)) && !( (d== 'c') || (d == 'C') || (d == 'S') || (d== 's') || (d=='r') || (d == 'R')))
  {
    printf("You entered a wrong letter, please try again\n");

  }



  bool  customerMode = 0, storageMode = 0 , cashierMode = 0;
  whichMode(d,  &customerMode, &storageMode, &cashierMode);


 
   if (customerMode)
  {
     // part 1 : how many customers are there ?
    // the purpose of this question is to determine how many rows are there in the customer.txt
     int numberOfCustomers;
     printf("How many customers are there: ");
     while (scanf("%i" , &numberOfCustomers) && (!((numberOfCustomers >=1)  && (numberOfCustomers<=100))) )
     {
       printf("Invalid number, please try again");
     }

     FILE *ptrCustomerDataSet = fopen("customer.txt" , "w");
     makeCustomerDataSet(ptrCustomerDataSet, numberOfCustomers);
     fclose(ptrCustomerDataSet);

     // part 2: do all the rest logic within each iteration of the bellow loop for each customer independently
     for (int T= 1; T<= numberOfCustomers; T++)
     {
       struct Customer customer;




       printf("Hello customer %i , please enter your name: \n"
              "Name: " , T);
       scanf("%s" , customer.name);
       
       
       // part 2a:  taking the name of the customer and adding it to the customer.txt properly
        // no customer name is allowed to be more than 16
       char cleaner;

       long long l;
  
       for (;scanf("%19s" , customer.name);)
  {
    l = strlen(name);
    if (!((l>=1) && (l<=16)))
    {
      printf("Invalid name length please try again\n");

      while ((cleaner = getchar()) != '\n'  && cleaner != EOF); // the purpose of this line is to clean the buffer 
    }
    else
    {
    
      while ((cleaner = getchar()) != '\n' && cleaner != EOF);
      break;
    }


    jumpAddName(customer.name,T,"customer.txt");

  // part 3a : what are the departments that the customer is interested in ?
    // when displaying the menu, the customer might not be interested in all
       // departments in the inventory, so frist discover which department he is interested in. 
    // the purpose of this question is to just determine which part from the inventory.txt will be printed with displayMenu(); 
       // Beverages or Meat or Bakery or Snacks or Fruit or Vegetables or Dairy






        //part 2b: the customer starts picking items and puts them in his cart
       // we assume that the cart can take no more than 10 items
       

    

     

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

         //fun(,20,x,"inventory.txt", &item.name, &item.Quantity, &item.price);
         // this part of the code is supposed to jump into the inventory.txt, grap some data and get it back
         // so we can do other logic with it, because function only return one thing at a time, this
         // jumping function work by call by reference





         //what will happen after we get the price and quantity and name?
         










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
void makeInventory()
{

};

void getItemData(FILE *p, int row, int x , char namee[30] , char *name[20], int *Quantity, long double *price )
{

};
int nDigits (int a)
{
  int q,b=0;
  do
  {
    q = a / 10;
    a = q;
    b++;


  } while (q!=0);

  return b;
};
void makeCustomerDataSet(FILE *p , int row )
{


  row++;
  fprintf(p,"\n");
  for (int i=0 , NO =i; i<row; i++ , NO++)
  {

    for (int j=0 ; j<3; j++)
    {
      fprintf(p,"----------");
    }
    fprintf(p,"\n");
    if (i==0)
    {
      for (int j=1; j<=3; j++)
      {
        if (j==1)
        {
          fprintf(p ,"|  NO ");
        }
        else if (j==2)
        {
          fprintf(p, "|     Name      ");
        }
        else if (j==3)
        {
          fprintf(p, "| Spend |");
        }
      }
    }
    else

      for (int j=1; j<=3; j++ )
      {
        if (j==1)
        {
          if (nDigits(NO) == 1)
          {
            fprintf(p,"|  %i  ",NO);
          }
          else if (nDigits(NO) == 2)
          {
            fprintf(p,"|  %i ", NO);
          }
          else if (nDigits(NO) == 3)
          {
            fprintf(p,"|  %i",NO);
          }

        }
        else if (j==2)
        {
          fprintf(p,"|               ");
        }

        else if (j==3)
        {
          fprintf(p,"|       |");
        }


      }
    if (i== (row-1))
    {
      fprintf(p,"\n");
      for (int j=0; j<3; j++)
      {
        fprintf(p,"----------");
      }


    }
    fprintf(p,"\n");
  }



};
void jumpAddName( char name[20] , int NO , char fileName[20])
{
  int k = 63;
  k *=NO;

  FILE *p = fopen( fileName , "r+");
  fseek(p,38 + k + 1,SEEK_SET);
  fprintf(p, "%s" , name);
  fseek(p,38 +63 +1,SEEK_SET);
  fclose(p);


};
int nDigits (int a)
{
  int q,b=0;
  do
  {
    q = a / 10;
    a = q;
    b++;


  } while (q!=0);

  return b;
};
void makeInventory(FILE *p)
{


  int y=0, x =0;
  char arr[5] = {'D' , 'B' , 'I' , 'M' , 'S'};
  int row=26; // this makes till NO 25
  fprintf(p,"\n");
  for (int i=0 , NO =0; i<row; i++ , NO++)
  {


    for (int j=0 ; j<5; j++)
    {
      if ((j==0) && (i >1) && (i!=6) && (i!=11) && (i!=16) && (i!=21))
      {fprintf(p, "          ");}

      else if (i==6)
      {
        fprintf(p,"----------");
      }
      else if (i==11)
      {
        fprintf(p,"----------");
      }
      else if (i==16)
      {
        fprintf(p,"----------");
      }
      else if (i==21)
      {
        fprintf(p,"----------");
      }
      else
      {
        fprintf(p,"----------");
      }
    }


    fprintf(p,"\n");
    if (i==0)
    {
      for (int j=1; j<=5; j++)
      {
        if (j==1)
        {
          fprintf(p, "|  Kind   ");
        }
        if (j==2)
        {
          fprintf(p ,"|  NO ");
        }
        else if (j==3)
        {
          fprintf(p, "|     Name      ");
        }
        else if (j==4)
        {
          fprintf(p, "| Price ");
        }
        else if (j==5)
        {
          fprintf(p, "| Amount |");
        }
      }
    }
    else

      for (int j=1; j<=5; j++ )
      {
        if (j==1)
        {
          if ((j==1) && (i==3))
          {
            fprintf(p,"| Drinks  ");
          }
          else if ((j==1) && (i==8))
          {
            fprintf(p,"| Bakery  ");
          }
          else if ((j==1) && (i==13))
          {
            fprintf(p,"| Diary   ");
          }
          else if ((j==1) && (i==18))
          {
            fprintf(p,"| Meat    ");
          }
          else if ((j==1) && (i==23))
          {
            fprintf(p,"| Snacks  ");
          }
          else if (j==1)
          {
            fprintf(p,"|         ");
          }
        }

        else if (j==2)
        {

           char c = arr[y];
          fprintf(p,"|  %c%i ", c, NO);
          x++;
          if (x==5)
          {
            y++;
            x=0;
          }


        }
        else if (j==3)
        {
          // from 1 to 5 Drinks
          if (i==1)
          {
            fprintf(p,"| Pepsi         ");
          }
          else if (i==2)
          {
            fprintf(p,"| Water         ");
          }
          else if (i==3)
          {
            fprintf(p,"| Fruit Juice   ");
          }
          else if (i==4)
          {
            fprintf(p,"| Miranda       ");
          } else if (i==5)
          {
            fprintf(p,"| Roman         ");
          } else if (i==6)
          {
            fprintf(p,"| Croissant     ");
          } else if (i==7)
          {
            fprintf(p,"| Muffin        ");

          } else if (i==8)
          {
            fprintf(p,"| White toast   ");
          } else if (i==9)
          {
            fprintf(p,"| Cheesecake    ");
          } else if (i==10)
          {
            fprintf(p,"| Fresh Bread   ");
          } else if (i==11)
          {
            fprintf(p,"| Milk          ");
          } else if (i==12)
          {
            fprintf(p,"| Yogurt        ");

          } else if (i==13)
          {
            fprintf(p,"| White Cheese  ");
          } else if (i==14)
          {
            fprintf(p,"| Butter        ");
          } else if (i==15)
          {
            fprintf(p,"| Greek Yogurt  ");
          } else if (i==16)
          {
            fprintf(p,"| Chicken       ");
          } else if (i==17)
          {
            fprintf(p,"| Beef          ");
          } else if (i==18)
          {
            fprintf(p,"| Turkey        ");
          } else if (i==19)
          {
            fprintf(p,"| Sausages      ");
          } else if (i==20)
          {
            fprintf(p,"| Kofta         ");
          } else if (i==21)
          {
            fprintf(p,"| KitKat        ");
          } else if (i==22)
          {
            fprintf(p,"| Lays          ");
          } else if (i==23)
          {
            fprintf(p,"| Kinder Beuno  ");
          } else if (i==24)
          {
            fprintf(p,"| Kinder Joy    ");
          } else if (i==25)
          {
            fprintf(p,"| Indomee       ");
          }


        }

        else if (j==4)
        {
          fprintf(p,"| 30    ");
        }
        else if (j==5)
        {
          fprintf(p, "| 50     |");
        }


      }
    if (i== (row-1))
    {
      fprintf(p,"\n");
      for (int j=0; j<5; j++)
      {
        fprintf(p,"----------");

      }


    }
    fprintf(p,"\n");

    if (NO ==5)
    {
      NO =0;
    }
  }



};



};
