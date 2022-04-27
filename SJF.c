#include <stdio.h>
int main(void)
{
    int at[10], bt[10], wt[10], tt[10], ct[10], i, p[10], n, sum = 0, pos, j, temp, tct, low, a;
    printf("No of process:");
    scanf("%d", &n);
    float awt = 0, att;
    for (i = 0; i < n; i++)
    {
        printf("arrival time of p%d:", i + 1);
        scanf("%d", &at[i]);
        printf("burst time of p%d:", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n - 1; j++)
        {
            if (at[j] < at[pos])
                pos = j;
        }
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;

        temp = at[i];
        at[i] = at[pos];
        at[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
    }

    i = 0;
    a = at[i];
    pos = i;
    for (j = i + 1; at[j] <= a; j++)
    {
        if (bt[pos] > bt[j])
        {
            pos = j;
        }
    }
    temp = p[i];
    p[i] = p[pos];
    p[pos] = temp;

    temp = at[i];
    at[i] = at[pos];
    at[pos] = temp;

    temp = bt[i];
    bt[i] = bt[pos];
    bt[pos] = temp;

    ct[0] = at[0] + bt[0];
    wt[0] = 0;
    tt[0] = bt[0];
    att = bt[0];
    for (i = 1; i < n; i++)
    {
        pos = i;
        tct = ct[i - 1];
        low = bt[i];
        for (j = i; j < n; j++)
        {
            if (tct >= at[j] && bt[i] >= bt[j])
            {
                pos = j;
                if (bt[i] == bt[j] && at[i] < at[j])
                {
                    pos = i;
                }
                temp = p[i];
                p[i] = p[pos];
                p[pos] = temp;

                temp = at[i];
                at[i] = at[pos];
                at[pos] = temp;

                temp = bt[i];
                bt[i] = bt[pos];
                bt[pos] = temp;
            }
        }
        wt[i] = ct[i - 1] - at[i];
        tt[i] = wt[i] + bt[i];
        ct[i] = ct[i - 1] + bt[i];
        awt = awt + wt[i];
        att = att + tt[i];
    }
    printf("\nprocess id\tarrival time\tburst time\twaiting time\tturnaround time \tcompletion time");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t%d", p[i], at[i], bt[i], wt[i], tt[i], ct[i]);
    }
    printf("\naverage waiting time:%f", awt / n);
    printf("\naverage turnaround time:%f", att / n);
    return 0;
}
