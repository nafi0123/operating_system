#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int id;         // Process ID
    int burstTime;  // Burst Time
    int waitingTime; // Waiting Time
    int turnAroundTime; // Turnaround Time
};

bool compareBurstTime(Process a, Process b) {
    return a.burstTime < b.burstTime;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
    }

    // Step 3: Sort processes by burst time in ascending order
    sort(processes.begin(), processes.end(), compareBurstTime);

    // Step 4: Find waiting time and turnaround time for all processes
    processes[0].waitingTime = 0; // Waiting time for the first process is 0

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].burstTime + processes[i - 1].waitingTime;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
    }

    // Step 5: Find average waiting time
    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
    }
    float averageWaitingTime = (float)totalWaitingTime / n;

    // Step 6: Find average turnaround time
    int totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalTurnAroundTime += processes[i].turnAroundTime;
    }
    float averageTurnAroundTime = (float)totalTurnAroundTime / n;

    // Print results
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t" << processes[i].burstTime << "\t\t" << processes[i].waitingTime << "\t\t" << processes[i].turnAroundTime << endl;
    }

    cout << "\nAverage Waiting Time: " << averageWaitingTime;
    cout << "\nAverage Turnaround Time: " << averageTurnAroundTime;

    return 0;
}
