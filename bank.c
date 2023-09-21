#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>

struct customer
{
    // int a,b;
    char name[50], add[50], email_id[50], pass[16];
    long long mob;
    long acc_num,acc_amount;
    long total_amount ;
    int id;

} s;
// Function declarations ... Note:  if not declared then it will give "<function name> was not declared in this scope" error for some compilers

void home(struct customer s);
void create_acc(struct customer s);
void login(struct customer s);
void cash_deposit(struct customer s);
void cash_withdrawal(struct customer s);
void Display_Acct_Info(struct customer s);
void mini_s(struct customer s);

int main()
{
    struct customer s;
    home(s);
}

void home(struct customer s)
{
    system("clear");
    int op;
    printf("\t\t*** WELCOME TO PSK BANK *\n\n\n");

    printf("01.login\n02.Create New Account\n03.Display account info\n");
    printf("Choose the above option :");
    scanf("%d", &op);

    switch (op)
    {
    case 01:
        login(s);
        break;

    case 02:
        create_acc(s);

        break;
    case 03:
        Display_Acct_Info(s);
        break;
    default:
        printf("\n choose the correct option :");
        break;
    }
}

void create_acc(struct customer s)
{
    int e;
    
    static long last_account_number = 123456;

    system("clear");
    printf("*******PSK BANK**********\n\n\n");
    printf("\nAccount name :\t");
    scanf("%s", s.name);
    printf("enter Address :\t");
    scanf("%s", s.add);
    printf("enter mob no :\t");
    scanf("%lld", &s.mob);
    // printf("Mobile\n");
    // scanf("%lld",&s.mob);
    printf("Enter email Id:\t");
    scanf("%s", s.email_id);
    printf("Enter password:\t");
    scanf("%s", s.pass);
    printf("Enter initial deposit :");
    scanf("%d", &s.id);
    s.acc_amount = s.id;
    system("clear");
    printf("*****Successfuly Account Created...***");
    
    s.acc_num = ++last_account_number;
    printf("\n\nYour Acc number is: %ld",s.acc_num);
    
    printf("\n\n\n1.login\n2.Back\n");

    scanf("%d", &e);

    switch (e)

    {

    case (1):

        login(s);
        break;

    case (2):
        //system("cls");
        home(s);

    default:
        printf("Invalid Choice ..");
        break;
    }
    system("clear");
}

void login(struct customer s)
{
    int r, num;
    char email[100], pass[100];
    system("clear");
    printf("\nEnter email id : ");
    scanf("%s", email);
    printf("\nenter the password : ");
    scanf("%s", pass);

    if(strcmp(s.email_id, email) == 0 && (strcmp(s.pass, pass) == 0)) 
        printf("\n Login Successful ... \n\n") ;
    else {
        printf("\n Invalid login id or password");
        return;
    }
    while(1)
    {
    printf("\nSelect below options \n 1.Cash Deposit \n 2.Cash Withdrawal \n 3.Display Account Information\n 4.Mini Statement\n 5.Log Out\n");
    scanf("%d",&num);
    
    //printf("\nnum --> %d",num);

    switch (num)
    {
    case 1:
        cash_deposit(s);
        break;

    case 2:
        cash_withdrawal(s);
        break;

    case 3:
        Display_Acct_Info(s);
        break;

    case 4:
        mini_s(s);
        break;

    case 5:
        
        printf("\nLogging off ...");
        system("clear");
        home(s);
        break;

    default:
        printf("invalid num");
        break;
    }
        
    }
}

void Display_Acct_Info(struct customer s)
{
    system("clear");
    s.total_amount=s.id;
    printf("\nname -%s\n", s.name);
    printf("address -%s\n", s.add);
    printf("mobNo -%lld\n", s.mob);
    printf("emailId -%s\n", s.email_id);
    printf("password -%s\n", s.pass);
    printf("initial deposit -%d\n", s.id);
    printf("Account num -%d\n", s.acc_num);
    printf("Account Balance -%ld\n", s.total_amount);
  
}


void cash_deposit(struct customer s)
{
    long num, amount;

    printf("\nEnter account num  ");
    scanf("%ld",&num);
    if (num == s.acc_num)
    {
        printf("\nEnter cash amount to deposit:");
        scanf("%ld",&amount);
        s.acc_amount += amount;
        s.total_amount=s.acc_amount+s.id;
        printf("%ld",s.total_amount);
        
    }
    else
    {
        printf("\nInvalid account number , please check");
    }
}

void cash_withdrawal(struct customer s)
{
    long num, amount;

    printf("\nEnter account num");
    scanf("%ld", num);
    if (num == s.acc_num)
    {
        printf("\nEnter cash amount to Withdrawal:");
        scanf("%ld",&amount);
        s.acc_amount -= amount;
        printf("\nWithdraw Successfuly !!! \nRemaining balance is - %d",s.acc_amount);
    }
    else
    {
        printf("\nInvalid account number , please check");
    }
}
void mini_s(struct customer s){
    system("clear");
        printf("*****Mini Statement******\n\n\n");
        printf("Name of Account Holder%s\n",s.name);
        printf("Initial deposit : %s\n",s.id);
        printf("Last deposited amount : %ld\n",s.acc_amount);
        printf("Total Balance : %ld\n",s.total_amount);
}