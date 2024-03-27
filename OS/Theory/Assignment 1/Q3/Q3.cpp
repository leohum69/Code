#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
using namespace std;

#define SHM_SIZE 1024

int main()
{
    int shmid;

    key_t key = 1234; // Unique key for shared memory segment

    char *shm_ptr;

    // Create a shared memory segment or obtain the identifier if it already exists

    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | S_IRUSR | S_IWUSR)) == -1)
    {

        perror("shmget");

        exit(EXIT_FAILURE);
    }
    // Attach the shared memory segment to the sender's address space

    shm_ptr = (char*)shmat(shmid, NULL, 0);

    if (shm_ptr == (char *)(-1))
    {

        perror("shmat");

        exit(EXIT_FAILURE);
    }

    // Write data to the shared memory

    cout<<"Enter The Word to Check Spelling : "<<endl;
    char test[256];
    cin.getline(test,256);

    strcpy(shm_ptr, test);

    pid_t pid = fork();

    if(pid == 0){
        execlp("./yes", "yes", NULL);
    }


    // Detach the shared memory segment
    wait(NULL);

    cout<<shm_ptr;

    shmdt(shm_ptr);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}