#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <ctype.h>
#include <unistd.h>

char cwd[100];
pthread_t td[3]; 
pid_t c;
char *array[4],*array2[20];
char array3[100],x[100];
int p = 0, q = 0;
int i=0, j=0, e;
int argc;
char *argv[100];

int l=5; 
void* pac(void *arg)
{
    strcpy(x,arg);
    char *t,*t1;

 unsigned long i=0;
 pthread_t id=pthread_self();
 int iter;

    t1 = strtok(x, "/");
    while( t1 != NULL ) {
        array2[q] = t1;
        q++;
        t1 = strtok(NULL, "/");
    }
    strcpy(array3,array2[q-1]);
    t = strtok(array2[q-1], ".");
    while( t != NULL ) {
        array[p] = t;
        p++;
        t = strtok(NULL, ".");
    }

    char a[100];
    strcpy(a,array[p-1]);
    for(int i = 0; a[i]; i++){
        a[i] = tolower(a[i]);
    }
  
    DIR *folder, *folderopen;
    struct dirent *entry;
    char t2[100],t3[100];
    folder = opendir(cwd);
    int av = 0;
    printf("p = %d\n",p);
    if( p > 1 ){

        if(folder == NULL)
        {
            printf("error\n");
        }
        while( (entry=readdir(folder)) )
        {
            if(strcmp(entry->d_name,a) == 0 && entry->d_type == 4){
                av = 1;
                break;
            }
        }

        if(av == 0){
            strcpy(t2,cwd);
            strcat(t2,"/");
            strcat(t2,a);
            printf("aaaa = %s\n%s\n",a,t2);
            mkdir(t2, 0777);
            
        }
    }
    else{
        strcpy(t2,cwd);
        strcat(t2,"/");
        strcat(t2,"Unknown");
        printf("bbbb= %s\n %s\n",a,t2);
        mkdir(t2, 0777);
    }
 

    char s[1024], tgt[1024];


    strcpy(s,arg);
    strcpy(tgt,cwd);
    strcat(tgt,"/");
    if(p == 1 ){
        strcat(tgt,"Unknown");
    }
    else{
        strcat(tgt,a);
    }
    strcat(tgt,"/");
    strcat(tgt,array3);
    rename(s,tgt);
    p = 0;
    q = 0;

 return NULL;
}

void gcwd(){
    if(getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working dir: %s\n", cwd);
    }  
}

void pt(){
 if (strcmp(argv[1],"-f") == 0) {
        for(j = 2 ; j < argc ; j++ ){
            int e;
            pthread_create(&(td[i]),NULL,pac,argv[j]);
            pthread_join(td[i],NULL);
            i++;
        }
    }
     
    else if (strcmp(argv[1],"*") == 0 && argc == 2) {
        i = 0;
        DIR *fd, *fdo;
        struct dirent *m;
        char ta[100],tb[100];
        fd = opendir(cwd);
        int av = 0;

        if(fd == NULL)
        {
            printf("error\n");
        }
        while( (m=readdir(fd)) )
        {
            if ( !strcmp(m->d_name, ".") || !strcmp(m->d_name, "..") )
            continue;
            printf("%s %d\n",m->d_name,m->d_type);

            int e;
            strcpy(ta,cwd);
            strcat(ta,"/");
            strcat(ta,m->d_name);
            if(m->d_type == 8){
            pthread_create(&(td[i]),NULL,pac,ta);
            pthread_join(td[i],NULL);
            i++;
            }
        }

    }
    else if (strcmp(argv[1],"-d") == 0 && argc == 3) {
        i = 0;
        DIR *fd, *fdo;
        struct dirent *m;
        char ta[100],tb[100];
        fd = opendir(argv[2]);
        int av = 0;

        if(fd == NULL)
        {
            printf("error\n");
        }
        while( (m=readdir(fd)) )
        {
            if ( !strcmp(m->d_name, ".") || !strcmp(m->d_name, "..") )
            continue;
            printf("%s %d\n",m->d_name,m->d_type);

            int e;
            strcpy(ta,argv[2]);
            strcat(ta,"/");
            strcat(ta,m->d_name);
            if(m->d_type == 8){
            pthread_create(&(td[i]),NULL,pac,ta); 
            pthread_join(td[i],NULL);
            i++;
            }
        }
    }

}

int main(int argc, char *argv[])
{
 int i=0, j=0;
int e;
    gcwd();
    pt();

    return 0; 
}
