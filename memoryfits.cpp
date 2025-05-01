#include <iostream>
using namespace std;

void firstFit(int* memoryBlock, int sizeMemory, int* processMemory, int sizeProcess){

    for(int i = 0;i<sizeProcess;i++){
        bool allocated = false;
        for(int j=0;j<sizeMemory;j++){
            if(processMemory[i] <= memoryBlock[j]){
                memoryBlock[j]-=processMemory[i];
                cout<<"Process "<< i 
                    << " - Size : " 
                    <<processMemory[i]
                    <<" -> " << "Block " 
                    << j << "- Left Memory in Block " << j << " : " << memoryBlock[j]
                    <<endl;
                allocated = true;
                break;
            }
        }
        if (!allocated) {
            cout << "Process " << i + 1
                 << " - Size: " << processMemory[i]
                 << " -> Not allocated" << endl;
        }
    }
}

void bestFit(int* memoryBlock, int sizeMemory, int* processMemory, int sizeProcess){
    for(int i = 0;i<sizeProcess;i++){
        int min = 9999999;
        int index = -1;
        for(int j=0;j<sizeMemory;j++){
            if(memoryBlock[j] >= processMemory[i]) { 
                int remaining = memoryBlock[j] - processMemory[i]; 
                if(remaining < min) {               
                    min = remaining;                
                    index = j;                      
                }
            }
        }
        
        if (index==-1) {
            cout << "Process " << i + 1
                 << " - Size: " << processMemory[i]
                 << " -> Not allocated" << endl;
        } else {
            memoryBlock[index]-=processMemory[i];
                cout<<"Process "<< i 
                    << " - Size : " 
                    <<processMemory[i]
                    <<" -> " << "Block " 
                    << index << "- Left Memory in Block " << index << " : " << memoryBlock[index]
                    <<endl;
        }
    }
}

void worstFit(int* memoryBlock, int sizeMemory, int* processMemory, int sizeProcess){

    for(int i = 0;i<sizeProcess;i++){
        int max = -1;
        int index = -1;
        for(int j=0;j<sizeMemory;j++){
            if(memoryBlock[j] >= processMemory[i]) { 
                int remaining = memoryBlock[j] - processMemory[i]; 
                if(remaining > max) {               
                    max = remaining;                
                    index = j;                      
                }
            }
        }
        
        if (index==-1) {
            cout << "Process " << i + 1
                 << " - Size: " << processMemory[i]
                 << " -> Not allocated" << endl;
        } else {
            memoryBlock[index]-=processMemory[i];
                cout<<"Process "<< i 
                    << " - Size : " 
                    <<processMemory[i]
                    <<" -> " << "Block " 
                    << index << "- Left Memory in Block " << index << " : " << memoryBlock[index]
                    <<endl;
        }
    }
}

int main(){
    int memoryBlocks[] = {100,200,600,300,545,229};
    int processMemory[] = {200,234,494,133,33};

    int sizeProcess = sizeof(processMemory)/sizeof(processMemory[0]);
    int sizeMemory = sizeof(memoryBlocks)/sizeof(memoryBlocks[0]);
    // firstFit(memoryBlocks,sizeMemory,processMemory,sizeProcess);
    // bestFit(memoryBlocks,sizeMemory,processMemory,sizeProcess);
    worstFit(memoryBlocks,sizeMemory,processMemory,sizeProcess);
}