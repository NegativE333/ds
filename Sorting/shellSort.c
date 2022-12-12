#include <stdio.h>

struct employee
{
    int emp_no;
    char emp_name[50];
    float emp_salary;
};

int shell(struct employee a[], int n)
{
    struct employee temp;

    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; i += 1)
        {
            int temp = a[i].emp_no;
            int j;
            for (j = i; j >= interval && a[j - interval].emp_no > temp; j -= interval)
                a[j].emp_no = a[j - interval].emp_no;
            a[j].emp_no = temp;
        }
    }
}

int main()
{
    int n, count;
    printf("Enter number of employees \n");
    scanf("%d", &n);
    struct employee A[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nSr No. %d", i + 1);
        printf("\nEnter emp_no = ");
        scanf("%d", &A[i].emp_no);
        printf("\n Enter emp_name = ");
        scanf("%s", &A[i].emp_name);
        printf("\n Enter emp_salary = ");
        scanf("%f", &A[i].emp_salary);
    }

    shell(A, n);
    printf("\nSorted data \n");
    printf("emp_no \t \t Name \t\t emp_salary \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t \t %s \t %f \n", A[i].emp_no, A[i].emp_name, A[i].emp_salary);
    }

    return 0;
}