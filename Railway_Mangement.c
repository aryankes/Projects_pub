#include <stdio.h>


#include <stdlib.h>
#include <time.h>


int x=0;
int numPassengers;
int p=0;

// Structure to store passenger information
typedef struct {
    char name[100];
    int age;
    char class[20];
    int pnr;
    long int mob;
    int seat;
    char train[20];
    int a1;
    int b1;
    int fare;
} Passenger;

// Function to generate a unique PNR number
int generatePNR() {
    srand(time(NULL));
    return rand();
}

int seatCheck(int n)
{    

    if(n>32||n<1){
    printf(" ERROR...ENTER AGAIN\n");
    return 0;
    }
    else
    {
            if(n%8==1||n%8==4)
            {
            printf("booking is confirmed in Lower seat at %d\n",n);
            
            }
            if(n%8==2||n%8==5)
            {
                  printf("booking is confirmed in Middle seat at %d\n",n);
               
            }
            
             if(n%8==3||n%8==6)
            {
                  printf("booking is confirmed in Upper seat at %d\n",n);
             
            }
            
             if(n%8==7)
            {
                  printf("booking is confirmed in Side Lower seat at %d\n",n);
               
            }
            else if(n%8==0){
                  printf("booking is confirmed in Side Upper seat at %d\n",n);
            }
                  
            return 1;
     }
}

void routes()
{   printf("\tFollowing are the trains \n\n");
    printf("\t\tTrain A \t\t  Train B\n\n");
    printf("\t\tStation 1\t\t Station 4\n\n");
    printf("\t\tStation 2\t\t Station 5\n\n");
    printf("\t\tStation 3\t\t Station 6\n\n");
    
}

void Fare()
{
    printf("\tFollowing are the  fare\n\n");
    printf("\t\tTRAIN A \t\t DESTINATION \t\t AC \t\tSLEEPER\t\tGENERAL\n\n");
    printf("\t\tStation 1\t\t Station 2\t\t%d\t\t%d\t\t%d\n\n",200,150,80);
   // printf("\t\tStation 1\t\t Station 3\t\t%d\t\t%d\t\t%d\n\n",400,180,100);
    printf("\t\tStation 2\t\t Station 3\t\t%d\t\t%d\t\t%d\n\n",600,250,175);
    
     printf("\t\tTRAIN B \t\tDESTINATION \t\t AC \t\tSLEEPER\t\tGENERAL\n\n");
    printf("\t\tStation 4\t\t Station 5\t\t%d\t\t%d\t\t%d\n\n",300,150,80);
  //  printf("\t\tStation 4\t\t Station 6\t\t%d\t\t%d\t\t%d\n\n",400,180,100);
   printf("\t\tStation 5\t\t Station 6\t\t%d\t\t%d\t\t%d\n\n",500,250,175);
}

    
    
// Function to book a ticket
void bookTicket(Passenger *passenger,int fare[6][3]) {
    printf("\tEnter passenger name\t\t\t:\t ");
    scanf(" %[^\n]", passenger->name);
    printf("\tEnter passenger age\t\t\t:\t ");
    scanf(" %d", &(passenger->age));
    class:
    printf("\tEnter class (AC/Sleeper/General)\t:\t ");
    scanf(" %[^\n]", passenger->class); 
    int i=0;
    if(passenger->class[0]=='A'||passenger->class[0]=='a'){
      i=0;
    }
    else if(passenger->class[0]=='S'||passenger->class[0]=='s'){
      i=1;
    }
    else if(passenger->class[0]=='G'||passenger->class[0]=='g'){
      i=2;
    }
    else{
      printf("Wrong Input Enter Again\n");
      goto class;
    }
    printf("\tEnter your mobile number\t\t:\t ");
    scanf(" %ld",  &(passenger->mob)); 
    train:
    printf("\tEnter your train name (A/B)   \t\t:\t ");
    scanf(" %[^\n]", passenger->train);
    int k=0;
    if(passenger->train[0]=='A'){
      k=0;
    }
    else if(passenger->train[0]=='B'){
      k=1;
    }
    else{
      printf("Wrong Input Enter Again\n");
      goto train;
    }
    printf("\tBoarding From sation\t\t\t:\t");
    scanf(" %d",&passenger->a1);
    printf("\tTo station\t\t\t\t:\t");
     scanf(" %d",&passenger->b1);
    passenger->pnr = generatePNR();
    if(k==0){
      passenger->fare=fare[i][passenger->b1-1]-fare[i][passenger->a1-1];
    }
    else if(k==1){
      passenger->fare=fare[k*3+i][passenger->b1-4]-fare[k*3+i][passenger->a1-4];
    }
    
}

// Function to display ticket details
void displayTicket(Passenger passenger) {
    printf("Ticket Details:\n");
    printf("\t\tTrain Name(A/B))\t:\t %s\n", passenger.train);
    printf("\t\tPNR\t\t:\t %d\n", passenger.pnr);
    printf("\t\tName\t\t:\t %s\n", passenger.name);
    printf("\t\tAge\t\t:\t %d\n", passenger.age);
     printf("\t\tMobile\t\t:\t%ld\n",passenger.mob);
    printf("\t\tClass\t\t:\t %s\n", passenger.class);
    printf("\t\tSeat \t\t:  \t%d\n",passenger.seat);
    printf("\t\tBoarding\t:\t%d\n",passenger.a1);
    printf("\t\tDestination\t:\t%d\n",passenger.b1);
    printf("\t\tFare\t\t:\t%d\n",passenger.fare);
}

// Function to cancel a ticket based on PNR number
void cancelTicket(Passenger *passengers, int numPassengers, int pnr,int row,int coloumn ,int arr[][row][coloumn]) {
  Passenger del;
    for (int i = 0; i < numPassengers; i++) {
        if (passengers[i].pnr == pnr) {
            x=1;
            del=passengers[i];
            printf("\n\t\tTicket with PNR %d has been cancelled.\n", passengers[i].pnr);
            // Shift the remaining passengers to fill the gap
            for (int j = i; j < numPassengers - 1; j++) {
                passengers[j] = passengers[j + 1];
            }
            // return;
            break;
        }
    }
    int xx=0;
    if(del.class[0]=='A'||del.class[0]=='a'){
      if(del.train[0]=='A'){
        print(row,coloumn,arr[0]);
        xx=0;
      }
      else if(del.train[0]=='B'){
        print(row,coloumn,arr[3]);
        xx=3;
      }
    }
    else if(del.class[0]=='S'||del.class[0]=='s'){
      if(del.train[0]=='A'){
        print(row,coloumn,arr[1]);
        xx=1;
      }
      else if(del.train[0]=='B'){
        print(row,coloumn,arr[4]);
        xx=4;
      }
    }
    else if(del.class[0]=='G'||del.class[0]=='g'){
      if(del.train[0]=='A'){
        print(row,coloumn,arr[2]);
        xx=2;
      }
      else if(del.train[0]=='B'){
        print(row,coloumn,arr[5]);
        xx=5;
      }
    }

    printf("\n\t\tTicket with PNR %d not found.\n", pnr);
}
void bogie_construction(int row,int coloumn ,int seats[row][coloumn]){
    for(int i=0;i<row;i++){
        for(int j=0;j<coloumn;j++){
            seats[i][j]=1000;
        }
    }
    int k=1;
    for(int i=0;i<(coloumn-1)/3;i++){
        int flag1=0,flag2=0,cnt=0;
        int col=i*3+1;
        while(cnt<3){
            seats[cnt][col]=k;
            cnt++;k++;
        }
        cnt=0;
        col=i*3+2;
        while(cnt<3){
            seats[cnt][col]=1000;
            cnt++;
        }
        col=i*3+3;
        cnt=0;
        while(cnt<3){
            seats[cnt][col]=k;
            cnt++;k++;
        }
        seats[4][i*3+1]=k++;
        seats[4][i*3+2]=1000;
       // seats[4][i*3+1][0]=(char)(k+'0'),seats[4][i*3+1][1]='*';
      
        char stri2[10]="&&";
        seats[4][i*3+3]=k++;
        //seats[4][i*3+3][0]=(char)(k+'0'),seats[4][i*3+3][1]='*';
    }
}
void print(int row,int coloumn,int seats[row][coloumn]){
    for(int i=0;i<row;i++){
        for(int j=0;j<coloumn;j++){
            if(j==0){
                if(i==0){
                    printf("Lower ");
                }
                else if(i==1){
                    printf("Middle");
                }
                else if(i==2){
                    printf("Upper ");
                }
                else if(i==4){
                    printf("      ");
                }
                continue;
            }
            if(seats[i][j]==1000){
                printf("   ");
            }
            else if(seats[i][j]/10>=1){
                printf("  %d  ",seats[i][j]);
            }
            else if(seats[i][j]/10<1){
                printf("   %d  ",seats[i][j]);
            }
            if(j%3==0){
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("      ");
    for(int i=0;i<(coloumn-1)/3;i++){
        printf("SLower  ");
        printf(" SUpper ");
    }
}
int main() {
    int fare[6][3]={{0,200,800},{0,150,400},{0,80,255},{0,300,800},{0,150,400},{0,80,255}};
    int cabin=4;
    int row=5,coloumn=cabin*3+1;
    int arr[6][row][coloumn];
    for(int i=0;i<6;i++){
      bogie_construction(row,coloumn,arr[i]);
      
    }
    printf("\n\n");
    printf("\t\t\t.............................. WELCOME TO TRAIN BOOKING SYSTEM......................\n\n");
    printf("\t\t\t----------------------------------- STARTING YOUR JOURNEY----------------------------\n\n");
    
   routes();
   Fare();
    printf("Enter the number of passengers: ");
    scanf(" %d", &numPassengers);
    int l=1;
    Passenger* passengers = (Passenger*) malloc(numPassengers * sizeof(Passenger));

    // Book tickets for each passenger
    for (int i = 0; i < numPassengers; i++) {
        printf("\nPassenger %d:\n", i + 1);
        bookTicket(&passengers[i],fare);
           
              
                //printf("\n\nTHERE ARE TOTAL 48 SEATS IN ONE COACH\n");
                printf("'(0)' indicate seat has been occupied\n\n");
              int xx=0;
              if(passengers[i].class[0]=='A'||passengers[i].class[0]=='a'){
                if(passengers[i].train[0]=='A'){
                  print(row,coloumn,arr[0]);
                  xx=0;
                }
                else if(passengers[i].train[0]=='B'){
                  print(row,coloumn,arr[3]);
                  xx=3;
                }
              }
              else if(passengers[i].class[0]=='S'||passengers[i].class[0]=='s'){
                if(passengers[i].train[0]=='A'){
                  print(row,coloumn,arr[1]);
                  xx=1;
                }
                else if(passengers[i].train[0]=='B'){
                  print(row,coloumn,arr[4]);
                  xx=4;
                }
              }
              else if(passengers[i].class[0]=='G'||passengers[i].class[0]=='g'){
                if(passengers[i].train[0]=='A'){
                  print(row,coloumn,arr[2]);
                  xx=2;
                }
                else if(passengers[i].train[0]=='B'){
                  print(row,coloumn,arr[5]);
                  xx=5;
                }
              }
              again:
                printf("\nEnter your choice of seat\n");
               int flag=1;
               scanf(" %d", &(passengers[i].seat));
              int k=(passengers[i].seat-1)/8;
              for(int j=k*3+1;j<=k*3+3;j++){
                  if(j==k*3+2){
                      continue;
                  }
                  for(int p=0;p<row;p++){
                      if(arr[xx][p][j]==passengers[i].seat){
                        flag=0;
                        arr[xx][p][j]=0;
                      }
                  }
              }
               if(flag==1){
                    printf("\nseat is already booked in %s..please  enter again\n",passengers[p].class);
                    goto again;
               }
       
                 int c= seatCheck(passengers[i].seat);
                 if(c==0)
                  goto again;
 
    }  
               printf("\n");
                printf("----------------------------------------------------------\n");
                printf("\t\tGENERATED TICKET DETAILS\n");
                  printf("----------------------------------------------------------\n");
              for (int i = 0; i < numPassengers; i++) {
      
                 printf("\n\t\t");
                  printf("Passenger %d:\n\n", i + 1);
                   printf("\t\t");
                  displayTicket(passengers[i]);
                  printf("\n");
                  printf("****");
                  }
     
    char ch;
    printf("\n\n\t\tPlease enter your choice\n");
    choice:
    printf("\t\tb for booking ticket\n\t\ts for show ticket\n\t\tc for cancel ticket\n\t\te for exit\n");
    scanf("  %c",&ch);
    cases:
    switch(ch)
    {
        case 'b':
        case 'B':
        printf("Enter The Number of Passengers :");
        int newPassengers;
        scanf("%d",&newPassengers);
        realloc(passengers,newPassengers*sizeof(Passenger));
        for (int i=numPassengers;i<newPassengers+numPassengers;i++) {
          printf("\nPassenger %d:\n", i + 1);
          bookTicket(&passengers[i],fare);
                  //printf("\n\nTHERE ARE TOTAL 48 SEATS IN ONE COACH\n");
                  printf("'(0)' indicate seat has been occupied\n\n");
                int xx=0;
                if(passengers[i].class[0]=='A'||passengers[i].class[0]=='a'){
                  if(passengers[i].train[0]=='A'){
                    print(row,coloumn,arr[0]);
                    xx=0;
                  }
                  else if(passengers[i].train[0]=='B'){
                    print(row,coloumn,arr[3]);
                    xx=3;
                  }
                }
                else if(passengers[i].class[0]=='S'||passengers[i].class[0]=='s'){
                  if(passengers[i].train[0]=='A'){
                    print(row,coloumn,arr[1]);
                    xx=1;
                  }
                  else if(passengers[i].train[0]=='B'){
                    print(row,coloumn,arr[4]);
                    xx=4;
                  }
                }
                else if(passengers[i].class[0]=='G'||passengers[i].class[0]=='g'){
                  if(passengers[i].train[0]=='A'){
                    print(row,coloumn,arr[2]);
                    xx=2;
                  }
                  else if(passengers[i].train[0]=='B'){
                    print(row,coloumn,arr[5]);
                    xx=5;
                  }
                }
                again1:
                  printf("\nEnter your choice of seat\n");
                 int flag=1;
                 scanf(" %d", &(passengers[i].seat));
                int k=(passengers[i].seat-1)/8;
                for(int j=k*3+1;j<=k*3+3;j++){
                    if(j==k*3+2){
                        continue;
                    }
                    for(int p=0;p<row;p++){
                        if(arr[xx][p][j]==passengers[i].seat){
                            flag=0;
                            arr[xx][p][j]=0;
                        }
                    }
                }
                 if(flag==1){
                      printf("\nseat is already booked in %s..please  enter again\n",passengers[p].class);
                      goto again1;
                 }
                   int c= seatCheck(passengers[i].seat);
                   if(c==0)
                    goto again1;
  
    }   
                 printf("\n");
                  printf("----------------------------------------------------------\n");
                  printf("\t\tGENERATED TICKET DETAILS\n");
                    printf("----------------------------------------------------------\n");
                for (int i = numPassengers; i <newPassengers+ numPassengers; i++) {

                   printf("\n\t\t");
                    printf("Passenger %d:\n\n", i + 1);
                     printf("\t\t");
                    displayTicket(passengers[i]);
                    printf("\n");
                    printf("****");
                    }
                  numPassengers+=newPassengers;
                  break;
        case 's':
        case 'S':
           printf("----------------------------------------------------------\n");
    printf("\t\tYOUR TICKET\n");
     printf("----------------------------------------------------------\n");
       
       
    printf("\t\tTO SHOW WE NEED YOUR MOBILE NUMBER AS WELL AS PNR NUMBER\n");
   long int mob2;
   int pnr2;
   show:
   printf("\n\t\tENTER YOUR MOBILE NUMBER\n");
    scanf(" %ld",&mob2);
     printf("\t\tENTER YOUR PNR NUMBER\n");
       scanf(" %d",&pnr2);
    int y=0;

     for (int i = 0; i < numPassengers; i++) {
        if (passengers[i].mob == mob2&&(passengers[i].pnr==pnr2)) {
            y=1;
              displayTicket(passengers[i]);}}
              if(y==0)
              {printf("\n\n\t\t$$$$$WRONG DATA..PLEASE ENTER CORRECT DATA$$$$$\n\n");
                printf("****");
              
              printf("\n\t\tSHOWING TICKET NEEDS YOUR MOBILE NUMBER AND PNR\n ");
              goto show;
              }
              
    break;
     
     case 'c':
     case 'C':
    // Cancel a ticket
    printf("\n\t\tEnter the PNR number to cancel a ticket: ");
    int pnrToCancel;
    scanf(" %d", &pnrToCancel);
    cancelTicket(passengers, numPassengers, pnrToCancel,row,coloumn,arr);
    
     if(x==1){
    numPassengers--;
    x=0;}
    break;
     
     case 'e':
     case'E':
     printf("\n\n");
      printf("\n----------------------------------------------------------------------------\n");
     printf("\t\t ....THANK YOU FOR USING OUR SERVICE......");
       printf("\n---------------------------------------------------------------------------\n");
     exit(0);
     break;
     
    default:
     
    printf("\t\tplease enter correct choice\n");
    goto choice;
    }
     printf("\n----------------------------------------------------------\n");
    printf("\t\tDo you again want to perform..enter\n");
    goto choice;
 
    return 0;

}