#include <stdio.h>
void main()
{
    int n, bt[20], at[20], wt[20], tt[20], awt = 0, att = 0, i, j;
    printf("Enter the number of processes : ");
    scanf("%d", &n);

    printf("Enter the burst time of processes \n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d : \n", i);
        scanf("%d", &bt[i]);
    }

    printf("Enter the arrival time of processes \n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d \n", i);
        scanf("%d", &at[i]);
    }

    int sort_at[20], sort_bt[20], temp;

    for (i = 0; i < n; i++)
    {
        sort_at[i] = at[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {

            if (sort_at[j] > sort_at[j + 1])
            {
                temp = sort_at[j];
                sort_at[j] = sort_at[j + 1];
                sort_at[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (sort_at[i] == at[j])
            {
                sort_bt[i] = bt[j];
                break;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            wt[i] = 0;
            temp = sort_bt[i];
        }
        else
        {
            wt[i] = temp - sort_at[i];
            temp += sort_bt[i];
        }
    }

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            tt[i] = sort_bt[i];
        }
        else
        {
            tt[i] = sort_bt[i] + wt[i];
        }
    }

    for ( i = 0; i < n; i++)
    {
        awt+=wt[i];
        att+=tt[i];
    }
    

    printf("Average Waiting Time : %d \n",awt/n);
    printf("Average TurnAround Time : %d \n",att/n);
    

    printf("process \t bt \t wt \t tt \t at\n");
    for (i = 0; i < n; i++)
    {

        printf("%d \t\t %d \t %d \t %d \t %d \n", i, sort_bt[i], wt[i], tt[i], sort_at[i]);
    }
}