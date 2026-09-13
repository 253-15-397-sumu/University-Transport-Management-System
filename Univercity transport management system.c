#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct bus
{
    int busid;
    char route[60];
    char driver[50];
    int seats;
    struct bus*next;
};
struct bus*start=NULL;
struct payment
{
    char studentid[20];
    char name[50];
    int semester;
    int fee;
    int paid;
    struct payment *next;
};
struct payment*paymentstart = NULL;

char satDeparture[150]="8:00 AM and 4:00 PM";
char satArrival[150]="7:00 AM and 10:00 AM";

char sunDeparture[150]="1:30 PM and 4:00 PM";
char sunArrival[150]="8:30 AM and 10:00 AM";

char monDeparture[150]="10:00 AM and 4:00 PM";
char monArrival[150]="7:30 AM and 11:00 AM";

char tueDeparture[150]="11:30 AM and 6:00 PM";
char tueArrival[150]="7:30 AM and 12:00 PM";

char wedDeparture[150]="10:00 AM and 3:00 PM";
char wedArrival[150]="7:00 AM and 10:00 AM";

char thurDeparture[150]="1:00 PM and 6:00 PM";
char thurArrival[150]="8:30 AM and 10:00 AM";

char friDeparture[150]="Holiday!";
char friArrival[150]="Holiday!";
//Display Bus//
void displayBus()
{
    struct bus*i=start;
    if(start==NULL)
    {
        printf("NO Bus Found!\n");
        return;
    }
    while(i!=NULL)
    {
        printf("\nBus id       : %d\n",i->busid);
        printf("Route        : %s\n",i->route);
        printf("Driver Name  : %s\n",i->driver);
        printf("Seats        : %d\n",i->seats);
        i=i->next;
    }
}
//Add Bus//
void addbus()
{
    struct bus*newbus;
    newbus=(struct bus*)malloc(sizeof(struct bus));
    printf("Enter Bus Id: ");
    scanf("%d",&newbus->busid);

    printf("Enter Route: ");
    scanf(" %[^\n]",&newbus->route);

    printf("Enter Driver Name: ");
    scanf(" %[^\n]",&newbus->driver);

    printf("Enter Total Seats: ");
    scanf("%d",&newbus->seats);

    newbus->next=NULL;
    if(start==NULL)
    {
        start=newbus;
    }
    else
    {
       struct bus*i=start;
       while(i->next!=NULL)
       {
           i=i->next;
       }
       i->next=newbus;
    }
    printf("\nBus Successfully Added!\n");
}
//Delete Bus//
void deletebus()
{
    int search;
    printf("Enter Bus Id to delete: ");
    scanf("%d",&search);
    struct bus*i=start;

    if(start==NULL)
    {
        printf("Bus Not Found!\n");
        printf("Try Again!\n");
        return;
    }
    else if(start->busid==search&&start->next==NULL)
    {
      start=NULL;
    }
    else if(start->busid==search&&start->next!=NULL)
    {
        struct bus*temp;
        temp=start;
        start=start->next;
        free(temp);
    }
    else
    {
     struct bus*i=start;
     while(i->next->busid!=search)
     {
        if(i->next==NULL)
        {
            printf("Invalid!\n");
            printf("Try Again!\n");
        }
         i=i->next;
     }
     i->next=i->next->next;
    }
    printf("\nBus Deleted Successfully!\n");
}
//search Bus//
void searchbus()
{
    int id;
    printf("Enter Bus ID: ");
    scanf("%d",&id);

    struct bus*i=start;
    while(i!=NULL)
    {
     if(i->busid==id)
     {
         printf("\nBus Found-\n");
         printf("Bus Id  : %d\n",i->busid);
         printf("Route   : %s\n",i->route);
         printf("Driver  : %s\n",i->driver);
         printf("Seats   : %d\n",i->seats);
         return;
     }
     i=i->next;
    }
    printf("Bus Not Found!\n");
    printf("Try Again!\n");
}
//Update Bus//
void updatebus()
{
    int id;
    struct bus*i=start;
    printf("Enter Bus ID to Update: ");
    scanf("%d",&id);

    while(i!=NULL)
    {
        if(i->busid==id)
        {
            printf("\nNew Route: ");
            scanf(" %[^\n]",&i->route);

            printf("New Driver Name: ");
            scanf(" %[^\n]",&i->driver);

            printf("New Seats: ");
            scanf("%d",&i->seats);

            printf("Bus Updated Successfully!\n");
            return;
        }
        i=i->next;
    }
    printf("Bus Not Found!\n");
    printf("Try Again!\n");
}
//Total Bus Count//
void countbus()
{
    int count=0;
    struct bus*i=start;
    while(i!=NULL)
    {
        count++;
        i=i->next;
    }
    printf("Total Bus: %d\n",count);
}
//view bus schedule//
void viewSchedule()
{
    printf("=========================================================\n");
    printf("                   Weekly Bus Schedule                   \n");
    printf("=========================================================\n");

    printf("\nSaturday: \n");
    printf("DIU to Other Route : %s\n", satDeparture);
    printf("Other Route to DIU : %s\n", satArrival);

    printf("\nSunday\n");
    printf("DIU to Other Route : %s\n", sunDeparture);
    printf("Other Route to DIU : %s\n", sunArrival);

    printf("\nMonday\n");
    printf("DIU to Other Route : %s\n", monDeparture);
    printf("Other Route to DIU : %s\n", monArrival);

    printf("\nTuesday\n");
    printf("DIU to Other Route : %s\n", tueDeparture);
    printf("Other Route to DIU : %s\n", tueArrival);

    printf("\nWednesday\n");
    printf("DIU to Other Route : %s\n", wedDeparture);
    printf("Other Route to DIU : %s\n", wedArrival);

    printf("\nThursday\n");
    printf("DIU to Other Route : %s\n", thurDeparture);
    printf("Other Route to DIU : %s\n", thurArrival);

    printf("\nFriday\n");
    printf("DIU to Other Route : %s\n", friDeparture);
    printf("Other Route to DIU : %s\n", friArrival);

    printf("=========================================================\n");
}
//weekly schedule//
void manageweeklyschedule()
{
    int option,choice;
   while(1)
   {
    printf("=========================================================\n");
    printf("             Manage Weekly Bus Schedule                  \n");
    printf("=========================================================\n");
    printf("1. Saturday\n");
    printf("2. Sunday\n");
    printf("3. Monday\n");
    printf("4. Tuesday\n");
    printf("5. Wednesday\n");
    printf("6. Thursday\n");
    printf("7. Friday\n");
    printf("8. View Current Schedule\n");
    printf("9. Exit\n");
    printf("=========================================================\n");
    printf("Select Your Choice: ");
    scanf("%d",&option);
    if(option==1)
    {
        printf("=========================================================\n");
        printf("               Saturday Bus Schedule                     \n");
        printf("=========================================================\n");
        printf("1. Update Departure Time\n");
        printf("2. Update Arrival Time\n");
        printf("3. Back\n");
        printf("=========================================================\n");
        printf("Select Your Choice: \n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter New Departure Time: ");
            scanf(" %[^\n]", &satDeparture);
            printf("Saturday Schedule Updated Successfully!\n");
        }
        else if(choice==2)
        {
            printf("Enter New Arrival Time: ");
            scanf(" %[^\n]", &satArrival);
            printf("Saturday Schedule Updated Successfully!\n");
        }
        else if( choice==3)
        {
            printf("Exit to Menu!\n");
            continue;
        }
        else
        {
            printf("Invalid Choice!\n");
            printf("Try Again!\n");
        }
    }
    else if(option==2)
    {
        printf("=========================================================\n");
        printf("                 Sunday Bus Schedule                     \n");
        printf("=========================================================\n");
        printf("1. Update Departure Time\n");
        printf("2. Update Arrival Time\n");
        printf("3. Back\n");
        printf("=========================================================\n");
        printf("Select Your Choice: \n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter New Departure Time: ");
            scanf(" %[^\n]", &sunDeparture);
            printf("Sunday Schedule Updated Successfully!\n");
        }
        else if(choice==2)
        {
            printf("Enter New Arrival Time: ");
            scanf(" %[^\n]", &sunArrival);
            printf("Sunday Schedule Updated Successfully!\n");
        }
        else if( choice==3)
        {
            printf("Exit to Menu!\n");
            continue;
        }
        else
        {
            printf("Invalid Choice!\n");
            printf("Try Again!\n");
        }
    }
     else if(option==3)
    {
        printf("=========================================================\n");
        printf("                 Monday Bus Schedule                     \n");
        printf("=========================================================\n");
        printf("1. Update Departure Time\n");
        printf("2. Update Arrival Time\n");
        printf("3. Back\n");
        printf("=========================================================\n");
        printf("Select Your Choice: \n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter New Departure Time: ");
            scanf(" %[^\n]", &monDeparture);
            printf("Monday Schedule Updated Successfully!\n");
        }
        else if(choice==2)
        {
            printf("Enter New Arrival Time: ");
            scanf(" %[^\n]", &monArrival);
            printf("Monday Schedule Updated Successfully!\n");
        }
        else if( choice==3)
        {
            printf("Exit to Menu!\n");
            continue;
        }
        else
        {
            printf("Invalid Choice!\n");
            printf("Try Again!\n");
        }
    }
     else if(option==4)
    {
        printf("=========================================================\n");
        printf("                Tuesday Bus Schedule                     \n");
        printf("=========================================================\n");
        printf("1. Update Departure Time\n");
        printf("2. Update Arrival Time\n");
        printf("3. Back\n");
        printf("=========================================================\n");
        printf("Select Your Choice: \n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter New Departure Time: ");
            scanf(" %[^\n]", &tueDeparture);
            printf("Tuesday Schedule Updated Successfully!\n");
        }
        else if(choice==2)
        {
            printf("Enter New Arrival Time: ");
            scanf(" %[^\n]", &tueArrival);
            printf("Tuesday Schedule Updated Successfully!\n");
        }
        else if( choice==3)
        {
            printf("Exit to Menu!\n");
            continue;
        }
        else
        {
            printf("Invalid Choice!\n");
            printf("Try Again!\n");
        }
    }
     else if(option==5)
    {
        printf("=========================================================\n");
        printf("               Wednesday Bus Schedule                    \n");
        printf("=========================================================\n");
        printf("1. Update Departure Time\n");
        printf("2. Update Arrival Time\n");
        printf("3. Back\n");
        printf("=========================================================\n");
        printf("Select Your Choice: \n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter New Departure Time: ");
            scanf(" %[^\n]", &wedDeparture);
            printf("Wednesday Schedule Updated Successfully!\n");
        }
        else if(choice==2)
        {
            printf("Enter New Arrival Time: ");
            scanf(" %[^\n]", &wedArrival);
            printf("Wednesday Schedule Updated Successfully!\n");
        }
        else if( choice==3)
        {
            printf("Exit to Menu!\n");
            continue;
        }
        else
        {
            printf("Invalid Choice!\n");
            printf("Try Again!\n");
        }
    }
     else if(option==6)
    {
        printf("=========================================================\n");
        printf("               Thursday Bus Schedule                     \n");
        printf("=========================================================\n");
        printf("1. Update Departure Time\n");
        printf("2. Update Arrival Time\n");
        printf("3. Back\n");
        printf("=========================================================\n");
        printf("Select Your Choice: \n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter New Departure Time: ");
            scanf(" %[^\n]", &thurDeparture);
            printf("Thursday Schedule Updated Successfully!\n");
        }
        else if(choice==2)
        {
            printf("Enter New Arrival Time: ");
            scanf(" %[^\n]", &thurArrival);
            printf("Thursday Schedule Updated Successfully!\n");
        }
        else if( choice==3)
        {
            printf("Exit to Menu!\n");
            continue;
        }
        else
        {
            printf("Invalid Choice!\n");
            printf("Try Again!\n");
        }
    }
     else if(option==7)
    {
        printf("=========================================================\n");
        printf("                 Friday Bus Schedule                     \n");
        printf("=========================================================\n");
        printf("1. Update Departure Time\n");
        printf("2. Update Arrival Time\n");
        printf("3. Back\n");
        printf("=========================================================\n");
        printf("Select Your Choice: \n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Enter New Departure Time: ");
            scanf(" %[^\n]", &friDeparture);
            printf("Friday Schedule Updated Successfully!\n");
        }
        else if(choice==2)
        {
            printf("Enter New Arrival Time: ");
            scanf(" %[^\n]", &friArrival);
            printf("Friday Schedule Updated Successfully!\n");
        }
        else if( choice==3)
        {
            printf("Exit to Menu!\n");
            continue;
        }
        else
        {
            printf("Invalid Choice!\n");
            printf("Try Again!\n");
        }
    }
    else if(option==8)
    {
         viewSchedule();
    }
    else if(option==9)
    {
        printf("Exit to Menu!\n");
        return;
    }
    else
    {
        printf("Invalid Option!\n");
        printf("Try Again!\n");
    }
   }

}

//Bus Sorting//
void sortingbus()
{
    struct bus*i,*j;
    int tempid,tempseats;
    char tempdriver[50],temproute[60];

    for(i=start;i!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->busid > j->busid)
            {
              tempid = i->busid;
              i->busid = j->busid;
              j->busid = tempid;

              strcpy(temproute,i->route);
              strcpy(i->route,j->route);
              strcpy(j->route,temproute);

              strcpy(tempdriver,i->driver);
              strcpy(i->driver,j->driver);
              strcpy(j->driver,tempdriver);

              tempseats = i->seats;
              i->seats=j->seats;
              j->seats=tempseats;

            }
        }
    }
    printf("Bus List Sorted Successfully!\n");
}
//save file//
void savefile()
{
    FILE*fp;
    struct bus*i=start;
    fp=fopen("bus.text","w");
    while(i!=NULL)
    {
        fprintf(fp,"%d %s %s %d\n",i->busid,i->route,i->driver,i->seats);
        i=i->next;
    }
    fclose(fp);
    printf("Data Saved Successfully!\n");
}
//confirm payment//
void confirmpayment()
{
    struct payment*newpayment;
    newpayment=(struct payment*)malloc(sizeof(struct payment));
    printf("Enter Student Id :");
    scanf(" %[^\n]",&newpayment->studentid);
    printf("\nEnter Student Name :");
    scanf(" %[^\n]",&newpayment->name);
    printf("\nEnter Semester Duration :");
    scanf("%d",&newpayment->semester);
    newpayment->next=NULL;
    if(newpayment->semester==4)
    {
        newpayment->fee=3000;
    }
    else if(newpayment->semester==6)
    {
        newpayment->fee=4000;
    }
    else
    {
        printf("Invalid Semester Duration!\n");
        free(newpayment);
        return;
    }
    printf("\nTransport Fee: %d\n",newpayment->fee);

    while(1)
    {
       printf("Has the student paid the transport fee at the transport office?\n") ;
       printf("1. Yes\n");
       printf("2. No\n");
       int choice;
       printf("Select Your Choice :");
       scanf("%d",&choice);
       if(choice==1)
       {
           newpayment->paid=1;
            printf("\nPayment Confirmed Successfully!\n");
            break;
       }
       else if(choice==2)
       {
           newpayment->paid=0;
           printf("Payment not Confirmed!\n");
           break;
       }
       else
       {
           printf("Invalid Choice!\n");
           free(newpayment);
           return;
       }
    }
       if(paymentstart==NULL)
       {
          paymentstart=newpayment;
       }
       else
       {
           struct payment*i=paymentstart;
           while(i->next!=NULL)
           {
               i=i->next;
           }
           i->next=newpayment;
       }
}
//view payment//
void viewpaymentstatus()
{
    struct payment*i=paymentstart;
    if(paymentstart==NULL)
    {
        printf("No Payment Record Found!\n");
        return;
    }
    printf("=========================================================\n");
    printf("               Payment Status Information                \n");
    printf("=========================================================\n");
    while(i!=NULL)
    {
        printf("Student ID       : %s\n", i->studentid);
        printf("Student Name     : %s\n", i->name);
        printf("Semester Duration: %d Months\n", i->semester);
        printf("Transport Fee    : %d Tk\n", i->fee);
        if(i->paid==1)
        {
           printf("Payment Status   : Confirmed\n");
        }
        else
        {
           printf("Payment Status   : Not Confirmed\n");
        }
        i=i->next;
    }
    printf("=========================================================\n");
}
// Payment Renew //
void renewpayment()
{
    char id[50];
    int choice;
    struct payment*i=paymentstart;
    printf("Enter the student ID :");
    scanf(" %[^\n]",id);
    while(i!=NULL)
    {
        if(strcmp(i->studentid,id)==0)
        {
           printf("\nCurrent Semester Duration : %d Months\n", i->semester);
           printf("Current Transport Fee     : %d Tk\n", i->fee);

           printf("Enter New Semester Duration (4/6 Months): ");
           scanf("%d",&i->semester);

          if(i->semester==4)
            {
                i->fee=2500;
            }
            else if(i->semester==6)
            {
                i->fee=4000;
            }
            else
            {
                printf("\nInvalid Semester Duration!\n");
                return;
            }

            printf("\nTransport Fee: %d\n",i->fee);

             while(1)
            {
                printf("\nHas the student paid at the Transport Office?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                printf("Enter Your Choice: ");
                scanf("%d",&choice);

                if(choice==1)
                {
                    i->paid=1;
                    break;
                }
                else if(choice==2)
                {
                    i->paid=0;
                    break;
                }
                else
                {
                    printf("Invalid Choice!\n");
                    printf("Try Again!\n");
                }
            }
            printf("\nSemester Payment Renewed Successfully!\n");
           return;
        }
       i=i->next;
    }
    printf("\nStudent ID Not Found!\n");
}
//Save Payment Data//
void savepayment()
{
    FILE *fp;
    struct payment *i=paymentstart;

    fp = fopen("payment.txt", "w");

    if(fp == NULL)
    {
        printf("File Could Not Be Opened!\n");
        return;
    }

    while(i != NULL)
    {
        fprintf(fp,"%s %s %d %d %d\n",i->studentid,i->name,i->semester,i->fee,i->paid);

        i = i->next;
    }

    fclose(fp);

    printf("Payment Data Saved Successfully!\n");
}
//Payment Management//
void paymentmanagement()
{
    int choice;
    while(1)
    {
        printf("=========================================================\n");
        printf("         Welcome to the Transport Payment Section        \n");
        printf("=========================================================\n");
        printf("1. Confirm Payment\n");
        printf("2. View Payment Status\n");
        printf("3. Renew Semester Payment\n");
        printf("4. Back\n");
        printf("=========================================================\n");
        printf("Select Your Choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            confirmpayment();
        }
        else if(choice==2)
        {
            viewpaymentstatus();
        }
        else if(choice==3)
        {
            renewpayment();
        }
        else if(choice==4)
        {
            break;
        }
        else
        {
            printf("Invalid Choice!\n");
            printf("Try Again!\n");
        }
    }
}
//Admin Menu//
void adminmenu()
{
    int choice;
    while(1)
    {
        printf("=========================================================\n");
        printf("        Welcome to the Transport Admin Control Panel     \n");
        printf("=========================================================\n");
        printf("1. Add Bus\n");
        printf("2. Display Bus\n");
        printf("3. Search Bus\n");
        printf("4. Update Bus\n");
        printf("5. Delete Bus\n");
        printf("6. Count Total Bus\n");
        printf("7. Sorting Bus\n");
        printf("8. Manage Weekly Bus Schedule\n");
        printf("9. View Weekly Bus Schedule\n");
        printf("10. Payment Management Section\n");
        printf("11. Save Payment File\n");
        printf("12. Save Bus Information File\n");
        printf("13. Exit\n");
        printf("=========================================================\n");
        printf("Select Your Choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            addbus();
        }
        else if(choice==2)
        {
            displayBus();
        }
        else if(choice==3)
        {
          searchbus();
        }
        else if(choice==4)
        {
           updatebus();
        }
        else if(choice==5)
        {
           deletebus();
        }
        else if(choice==6)
        {
            countbus();
        }
        else if(choice==7)
        {
           sortingbus();
        }
        else if(choice==8)
        {
           manageweeklyschedule();
        }
        else if(choice==9)
        {
            viewSchedule();
        }
        else if(choice==10)
        {
            paymentmanagement();
        }
        else if(choice==11)
        {
          savepayment();
        }
        else if(choice==12)
        {
           savefile();
        }
        else if(choice==13)
        {
            break;
        }
        else
        {
            printf("Invalid Choice!\n");
            printf("Try Again!\n");
        }
    }
}
//Admin Login //
void adminlogin()
{
    char username[30];
    char password[30];
    int attempt = 0;

    while(attempt < 3)
    {
        printf("===================Admin Login===========================\n");

        printf("Enter Username: ");
        scanf("%s", username);

       char ch;
       int i = 0;

        printf("Enter Password: ");

        while((ch = getch()) != 13)
         {
            if(i < 8)
            password[i] = ch;
            i++;
            printf("*");
        }

        password[i] = '\0';

        if(strcmp(username,"admin")==0 && strcmp(password,"12345")==0)
        {
            printf("\nLogin Successful!\n");
            adminmenu();
            return;
        }
        else
        {
            attempt++;
            printf("\nInvalid Username or Password!\n");

            if(attempt < 3)
            {
                printf("Remaining Attempts: %d\n", 3-attempt);
            }
        }
    }

    printf("\nToo Many Failed Attempts!\n");
    printf("Returning to Main Menu...\n");
}
//user menu//
void usermenu()
{
    int choice;
    while(1)
    {
    printf("\n=========================================================\n");
    printf("            Welcome to the Transport User Panel          \n");
    printf("=========================================================\n");
    printf("1. Weekly Schedule\n");
    printf("2. Display Bus\n");
    printf("3. Search Bus\n");
    printf("4. Exit\n");
    printf("=========================================================\n");
    printf("Select Your Choice: ");
    scanf("%d",&choice);
    if(choice==1)
    {
      viewSchedule();
    }
    else if(choice==2)
    {
       displayBus();
    }
    else if(choice==3)
    {
      searchbus();
    }
    else if(choice==4)
    {
        printf("\nThank you for using our Transport Management System.\n");
        printf("Have a nice day!!\n");
            return;
    }
    else
    {
      printf("Invalid Choice!\n");
      printf("Try Again!\n");
    }
   }
}
//Payment check Function//
void paymentcheck()
{
    char id[50];
    char role[10];
    struct payment*i=paymentstart;

    printf("=========================================================\n");
    printf("                      User Verification                  \n");
    printf("=========================================================\n");
    printf("Enter Your Role (Student/Teacher/Staff): ");
    scanf(" %[^\n]", role);

    if(strcmp(role,"Teacher")==0 || strcmp(role,"teacher")==0)
    {
        usermenu();
        return;
    }

    if(strcmp(role,"Staff")==0 || strcmp(role,"staff")==0)
    {
        usermenu();
        return;
    }

    if(strcmp(role,"student")==0 || strcmp(role,"student")==0)
    {
       printf("Enter Student ID: ");
       scanf(" %[^\n]", id);

    while(i!=NULL)
     {
       if(strcmp(i->studentid,id)==0)
        {
            if(i->paid==1)
            {
                printf("\nPayment Verified Successfully!\n");
                printf("Welcome %s\n", i->name);
                usermenu();
                return;
            }
            else
            {
                printf("\nTransport Fee Not Paid!\n");
                printf("Please Complete Payment at the Transport Office.\n");
                return;
            }
        }

        i=i->next;
    }
    printf("\nNo Payment Record Found!\n");
    printf("You Cannot Access the User Panel.\n");
    printf("Please Complete Your Payment at the Transport Office.\n");
    }

    else
    {
        printf("Invalid Role!\n");
        printf("Try Again!\n");
        return;
    }
    return;
}
//main function//
int main()
{
    int choice;
    while(1)
    {
        printf("=========================================================\n");
        printf("        Welcome to Our Transport Management System       \n");
        printf("=========================================================\n");

        printf("1. Admin Login\n");
        printf("2. User Verification\n");
        printf("3. Exit\n");
        printf("=========================================================\n");
        printf("Select Your Choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            adminlogin();
        }

        else if(choice==2)
        {
            paymentcheck();
        }
        else if(choice==3)
        {
            printf("\nThank you for using our University Transport Management System.\n");
            printf("Have a nice day!!\n");
            break;
        }
        else
        {
            printf("Invalid Choice!\n");
            printf("Try Again!\n");
        }
    }
    return 0;
}
