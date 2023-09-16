#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int customers;
} office;

int buff[1000];

int input(office &room)
{
    scanf("%d", &room.customers);
    return room.customers;
}

int sum_of_digits(int d)
{
    int sum=0, digit;
    while (d != 0)
    {
        digit = d%10;
        sum += digit;
        d = d/10;
    }
    return sum;
}

void inputfile(office *a, int n)
{
    FILE *fptr;
    fptr = fopen("company.inp", "w");
    if (fptr == NULL)
    {
        printf("Error!!!");
        exit(0);
    }
    fprintf(fptr, "%d", n);
    for (int i=0; i<n; i++)
    {
        printf("Enter the number of customers in room %d: ", i+1);
        fprintf(fptr, "\n%d", input(a[i]));
    }
    fclose(fptr);
}

void bonus(office *a, int n)
{   
    FILE *ptr;
    int num[1000];
    
    ptr = fopen("company.inp", "r");
    if (ptr == NULL)
    {
        printf("Error!!!");
        exit(0);
    }
    for (int i=0; i<=n; i++)
    {
        fscanf(ptr, "%d", &num[i]);
        buff[i] = sum_of_digits(num[i])*1000000;
    }
    fclose(ptr);
}

void outputfile(office *a, int n)
{
    FILE *p;
    p = fopen("company.out", "w");
    if (p == NULL)
    {
        printf("Errorr!!");
        exit(0);
    }
    bonus(a,n);
    for (int i=1; i<=n; i++)
    {
        fprintf(p, "%d\n", buff[i]);
    }
    fclose(p);
}

int main()
{
    int n;
    do {
        printf("\nEnter the number of rooms: "); 
        scanf("%d", &n);
    }  while(n <= 0);
    office a[n];
    inputfile(a, n);
    outputfile(a, n);
    return 0;
}