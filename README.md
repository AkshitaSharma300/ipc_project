This repository contains a simple simulation of Inter-Process Communication (IPC) using UNIX pipes.
It demonstrates how a parent and child process communicate through a pipe in C++.

1. Initial commit: Added base IPC simulation code:
Added the complete working code for pipe creation, forking, and data transfer.
2. Revision 2: Added child process debug message:
Inserted an additional cout statement inside the child block to show when the child process runs.
3. Added explanation comment for pipe():
Added a meaningful comment explaining the purpose and working of the pipe() system call.
4. Added cout message before forking:
Added a debug print statement right before the fork() call to show program flow.
5. Added closing message after communication:
Added a final message printed at the end of communication to indicate successful completion.
