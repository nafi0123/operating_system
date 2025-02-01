#include <stdio.h>
#define MAX_PROCESSES 10

struct Process {
    int id;               
    int burst_time;        
    int priority;          
    int waiting_time;      
    int turnaround_time;   
};

void calculateWaitingTime(struct Process processes[], int n) {
    processes[0].waiting_time = 0; 
    
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
}

void calculateTurnaroundTime(struct Process processes[], int n) {
    
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void priorityScheduling(struct Process processes[], int n) {
    struct Process temp;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].priority > processes[j].priority) {
                // Swap processes[i] and processes[j]
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    
  
    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);
    
    
    printf("\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time,
               processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }
    
    
    int total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("\nAverage Waiting Time: %.2f", (float)total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

int main() {
    int n;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process processes[MAX_PROCESSES];
    
  
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;  // Process ID
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority for process %d: ", processes[i].id);
        scanf("%d", &processes[i].priority);
    }
    
    
    priorityScheduling(processes, n);
    
    return 0;
}
/*
ter the number of processes: 3
Enter burst time for process 1: 10
Enter priority for process 1: 2
Enter burst time for process 2: 5
Enter priority for process 2: 1
Enter burst time for process 3: 8
Enter priority for process 3: 3

Process ID      Burst Time      Priority        Waiting Time    Turnaround Time
2               5               1               0               5
1               10              2               5               15
3               8               3               15              23

Average Waiting Time: 6.67
Average Turnaround Time: 14.33

[Process completed - press Enter]
*/
