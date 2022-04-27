#include <stdio.h>
struct process
{
    int bt, at, wt, tt, ct, pr, pn;
} p[10];
int main()
{
    int n, i, pos, sum = 0, j, a, tct, low;
    struct process temp;
    float awt = 0, att = 0;
    printf("enter the no of process:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("arrival time p%d:", i + 1);
        scanf("%d", &p[i].at);
        printf("burst time p%d:", i + 1);
        scanf("%d", &p[i].bt);
        printf("priority of p%d:", i + 1);
        scanf("%d", &p[i].pr);
        p[i].pn = i + 1;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].at > p[j].at)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    i = 0;
    a = p[i].at;
    pos = i;
    for (j = i + 1; p[j].at <= a; j++)
    {
        if (p[pos].pr > p[j].pr)
        {
            pos = j;
        }
    }
    temp = p[i];
    p[i] = p[pos];
    p[pos] = temp;

    p[0].ct = p[0].at + p[0].bt;
    p[0].wt = 0;
    p[0].tt = p[0].bt;
    att = p[0].bt;

    for (i = 1; i < n; i++)
    {
        pos = i;
        tct = p[i - 1].ct;
        low = p[i].pr;
        for (j = i; j < n; j++)
        {
            if (tct >= p[j].at && p[i].pr >= p[j].pr)
            {
                pos = j;
                if (p[i].pr == p[j].pr && p[i].at < p[j].at)
                {
                    pos = i;
                }
                temp = p[i];
                p[i] = p[pos];
                p[pos] = temp;
            }
        }
        p[i].wt = p[i - 1].ct - p[i].at;
        p[i].tt = p[i].wt + p[i].bt;
        p[i].ct = p[i - 1].ct + p[i].bt;
        awt = awt + p[i].wt;
        att = att + p[i].tt;
    }
    printf("\nprocess id\tarrival time\tburst time\tpriority\twaiting time\tturnaround time \tcompletion time");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t\t\t%d\t\t\t\t%d\t\t\t%d\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t%d", p[i].pn, p[i].at, p[i].bt, p[i].pr,
               p[i].wt, p[i].tt, p[i].ct);
    }
    printf("\naverage waiting time:%f", awt / n);
    printf("\naverage turnaround time:%f", att / n);
    return 0;
}
