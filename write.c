#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define MAXSIZE     30


int main()
{
    char c, m[30] = "This is the message", *s, *shm;
    int shmid, i;
    key_t key=ftok("shmfile",65);

    if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0){
        printf("Error");
    }

    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1){
        printf("Error");
    }

    s = shm;

    for (i = 0; i <= 30; i++){
        *s++ = m[i];
    }
    shmdt(s);
    return 0;
}

