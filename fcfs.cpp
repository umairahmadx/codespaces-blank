#include <iostream>
using namespace std;

class Process {
public:
    int processNo;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitTime;
    int responseTime;
    
    Process(int p, int a, int b) {
        processNo = p;
        arrivalTime = a;
        burstTime = b;
        completionTime = 0;
    }
    
    void turnAroundTimeCalc(){
        turnAroundTime = completionTime - arrivalTime;
    }
    
    void waitTimeCalc(){
        waitTime = turnAroundTime-burstTime;
    }
    
    void responseTimeCalc(int t){
        responseTime = t - arrivalTime;
    }
};

int main() {
    Process p[] = {
        Process(1, 0, 2),
        Process(2, 1, 2),
        Process(3, 5, 3),
        Process(4, 6, 4)
    };

    int size = sizeof(p) / sizeof(p[0]);
    int time = 0;
    int pnum = 0;

    while (pnum < size) {
        if (p[pnum].arrivalTime <= time) {
            
            p[pnum].responseTimeCalc(time);
            time += p[pnum].burstTime;
            p[pnum].completionTime = time;
            p[pnum].turnAroundTimeCalc();
            p[pnum].waitTimeCalc();
            
            pnum++;
        } else {
            time++; 
        }
    }
    double avgTAT=0;
    double avgWT=0;
    
    for (int i = 0; i < size; i++) {
        cout << "Process " << p[i].processNo 
            << " - Completion Time: " << p[i].completionTime 
            << " - Turn Around Time: " << p[i].turnAroundTime 
            << " - Wait Time : " <<p[i].waitTime
            << " - Response Time : " << p[i].responseTime
            << endl;
        
        avgTAT+=p[i].turnAroundTime;
        avgWT+=p[i].waitTime;
    }
    
    avgTAT/=size;
    avgWT/=size;
     
    cout<<"Avg Turn Around Time : " << avgTAT<<endl;
    cout<<"Avg Wait Time : " << avgWT <<endl;
    

    return 0;
}
