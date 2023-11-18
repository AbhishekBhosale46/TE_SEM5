#include <iostream>
#include <vector>
#include <algorithm>

class Process {
public:
    int id;
    bool active;

    Process(int _id) : id(_id), active(true) {}
};

class BullyAlgorithm {
private:
    std::vector<Process> processes;

public:
    BullyAlgorithm(int numProcesses) {
        for (int i = 0; i < numProcesses; ++i) {
            processes.push_back(Process(i + 1));
        }
    }

    void election(int processId) {
        auto currentProcess = std::find_if(processes.begin(), processes.end(), 
            [processId](const Process& p) { return p.id == processId; });

        if (currentProcess != processes.end() && currentProcess->active) {
            for (auto& p : processes) {
                if (p.id > processId && p.active) {
                    std::cout << "Process " << processId << " sends Election message to " << p.id << std::endl;
                }
            }
        } else {
            std::cout << "Error: Process " << processId << " is not active." << std::endl;
        }
    }

    void coordinatorElection(int processId) {
        auto currentProcess = std::find_if(processes.begin(), processes.end(), 
            [processId](const Process& p) { return p.id == processId; });

        if (currentProcess != processes.end() && currentProcess->active) {
            std::cout << "Process " << processId << " declares itself as the coordinator." << std::endl;
        } else {
            std::cout << "Error: Process " << processId << " is not active." << std::endl;
        }
    }
};

int main() {
    BullyAlgorithm bully(5);  // Assuming 5 processes for example

    // Simulating an election initiated by Process 3
    // bully.election(3);

    // Simulating a coordinator election initiated by Process 5
    bully.coordinatorElection(5);

    return 0;
}
