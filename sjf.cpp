#include <iostream>
using namespace std;

class Process
{
public:
    bool isCompleted;
    int processNo;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitTime;
    int responseTime;

    Process(int p, int a, int b)
    {
        processNo = p;
        arrivalTime = a;
        burstTime = b;
        completionTime = 0;
        isCompleted = false;
    }

    void turnAroundTimeCalc()
    {
        turnAroundTime = completionTime - arrivalTime;
    }

    void waitTimeCalc()
    {
        waitTime = turnAroundTime - burstTime;
    }

    void responseTimeCalc(int t)
    {
        responseTime = t - arrivalTime;
    }
};

int main()
{
    Process p[] = {
        Process(1, 1, 3),
        Process(2, 2, 4),
        Process(3, 1, 2),
        Process(4, 4, 4)};

    int size = sizeof(p) / sizeof(p[0]);
    int time = 0;
    int completed = 0;

    while (completed < size)
    {
        int minBurst = 99999;
        int selectProcess = -1;
        for (int i = 0; i < size; i++)
        {
            if (!p[i].isCompleted && p[i].arrivalTime <= time)
            {
                if (p[i].burstTime < minBurst ||(p[i].burstTime == minBurst && p[i].arrivalTime < p[selectProcess].arrivalTime))
                {

                    minBurst = p[i].burstTime;
                    selectProcess = i;
                }
            }
        }

        if (selectProcess != -1)
        {
            p[selectProcess].responseTimeCalc(time);
            time += p[selectProcess].burstTime;
            p[selectProcess].completionTime = time;
            p[selectProcess].turnAroundTimeCalc();
            p[selectProcess].waitTimeCalc();
            p[selectProcess].isCompleted = true;
            completed++;
        }
        else
        {
            time++;
        }
    }
    double avgTAT = 0;
    double avgWT = 0;

    for (int i = 0; i < size; i++)
    {
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
