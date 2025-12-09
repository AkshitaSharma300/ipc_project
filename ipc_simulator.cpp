#include <iostream>
#include <unistd.h>
using namespace std;
void simulatePipe() {
    int pipefd[2];
    char buffer[50];
    // Creating a pipe for communication between parent and child   ← REVISION 2
    if (pipe(pipefd) == -1) {
        cout << "Pipe creation failed!" << endl;
        return;
    }
    cout << "Pipe created successfully. Preparing to fork..." << endl;   // ← REVISION 3
    int pid = fork();
    if (pid < 0) {
        cout << "Fork failed!" << endl;
        return;
    }
    // Child Process
    if (pid == 0) {
        close(pipefd[0]); // Close read end
        string message = "Hello from Child Process (PIPE)";
        write(pipefd[1], message.c_str(), message.size() + 1);
        close(pipefd[1]);
        cout << "Child Process: Writing to pipe..." << endl;    
    } 
    // Parent Process
    else {
        close(pipefd[1]); // Close write end
        read(pipefd[0], buffer, sizeof(buffer));
        cout << "Parent received: " << buffer << endl;
        close(pipefd[0]);
        cout << "Pipe communication completed successfully." << endl;  // ← REVISION 4
    }
}
int main() {
    cout << "=== IPC Debugger Tool: Pipe Simulation ===\n";
    simulatePipe();
    return 0;
}
