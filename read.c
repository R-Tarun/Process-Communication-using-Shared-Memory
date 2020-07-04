
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE     30



int main()
{
    int shmid;
    key_t key=ftok("shmfile",65);
    char *shm, *s;

    if ((shmid = shmget(key, MAXSIZE, 0666)) < 0){
        printf("Error");
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1){
        printf("Error");
    }

    for (s = shm; *s != '\0'; s++){
        putchar(*s);
    }
    putchar('\n');

    shmdt(s);
    shmctl(shmid,IPC_RMID,NULL);

    return 0;
}
