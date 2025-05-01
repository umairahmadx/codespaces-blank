#include <iostream>
using namespace std;

class Process {
public:
    bool isCompleted;
    int processNo;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitTime;
    int responseTime;
    int priority;
    
    Process(int p, int pri, int a, int b) {
        priority = pri;
        processNo = p;
        arrivalTime = a;
        burstTime = b;
        completionTime = 0;
        isCompleted = false;
    }
    
    void turnAroundTimeCalc() {
        turnAroundTime = completionTime - arrivalTime;
    }
    
    void waitTimeCalc() {
        waitTime = turnAroundTime - burstTime;
    }
    
    void responseTimeCalc(int t) {
        responseTime = t - arrivalTime;
    }
};

int main() {
    Process p[] = {
        Process(1, 3, 0, 8),
        Process(2, 4, 1, 2),
        Process(3, 4, 3, 4),
        Process(4, 5, 4, 1),
        Process(5, 2, 5, 6),
        Process(6, 6, 6, 5),
        Process(7, 1, 10, 1),
    };

    int size = sizeof(p) / sizeof(p[0]);
    int time = 0;
    int completed = 0;

    while (completed < size) {
        int minPriority = 10000;
        int selectProcess = -1;

        for (int i = 0; i < size; i++) {
            if (!p[i].isCompleted && p[i].arrivalTime <= time) {
                if (p[i].priority < minPriority || 
                   (p[i].priority == minPriority && p[i].arrivalTime < p[selectProcess].arrivalTime)) {
                    minPriority = p[i].priority;
                    selectProcess = i;
                }
            }
        }

        if (selectProcess != -1) {
            p[selectProcess].responseTimeCalc(time);
            time += p[selectProcess].burstTime;
            p[selectProcess].completionTime = time;
            p[selectProcess].turnAroundTimeCalc();
            p[selectProcess].waitTimeCalc();
            p[selectProcess].isCompleted = true;
            completed++;
        } else {
            time++;
        }
    }

    double avgTAT = 0;
    double avgWT = 0;

    for (int i = 0; i < size; i++) {
        cout << "Process " << p[i].processNo 
             << " - Completion Time: " << p[i].completionTime 
             << " - Turn Around Time: " << p[i].turnAroundTime 
             << " - Wait Time : " << p[i].waitTime 
             << " - Response Time : " << p[i].responseTime 
             << endl;

        avgTAT += p[i].turnAroundTime;
        avgWT += p[i].waitTime;
    }

    avgTAT /= size;
    avgWT /= size;

    cout << "Avg Turn Around Time : " << avgTAT << endl;
    cout << "Avg Wait Time : " << avgWT << endl;

    return 0;
}
