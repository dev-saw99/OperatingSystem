#include <stdio.h>
#include <stdlib.h>

//required libraries

struct process
{
    int p_id;   //Process id
    int b_time; //Burst Time
    int a_time; //Arrival Time
};
//structure process stimulating one individual process.

struct process create_processes()
{
    struct process processes;

        scanf("%d ", &processes.p_id);
    scanf("%d", &processes.a_time);
    scanf("%d", &processes.b_time);
    ;
    return processes;
}
// method to create the process by the user

int main()
{
    int N;
    printf("\n\nEnter number of process : ");
    scanf("%d", &N);
    printf("\nEnter Process Detatils \n\n");
    printf("Process ID     Arrival Time     Burst Time (seperated by space)\n");
    struct process proc[N];
    for (int i = 0; i < N; i++)
    {
        proc[i] = create_processes();
    }
}