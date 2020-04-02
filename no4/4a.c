#include <stdio.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int m1[5][5], m2[5][5];
int (*ans)[10];
int i,j;
int b1=4, k1=2;//matriks 4x2
int b2=2, k2=5;//matriks 2x5
int stat;

//fungsi untuk mengisi matriks1 dan matriks2 dan perkalian matriks
void *kali_m(void *);
void *isi_m1(void *);
void *isi_m2(void *);

void *isi_m1(void *arg){
	stat=0;
    m1[0][0]=1;
    m1[0][1]=2;
    m1[1][0]=3;
    m1[1][1]=4;
    m1[2][0]=5;
    m1[2][1]=6;
    m1[3][0]=7;
    m1[3][1]=8;
	stat=1;
	return NULL;
}

void *isi_m2(void *arg){
	while(stat!=1){
	}
    m2[0][0]=1;
    m2[0][1]=2;
    m2[0][2]=3;
    m2[0][3]=4;
    m2[0][4]=5;
    m2[1][0]=6;
    m2[1][1]=7;
    m2[1][2]=8;
    m2[1][3]=9;
    m2[1][4]=10;

	stat=2;
	return NULL;
}

void *kali_m(void *arg)
{
	while(stat!=2)	{
	}
	int i, j, k;
	for(i=0;i<b1;i++){
		for(j=0;j<k2;j++){
			for(k=0;k<k1;k++)
				ans[i][j]+=m1[i][k] * m2[k][j];
		}
	}
	return NULL;
}

//fungsi untuk meng output hasil
void print(){
	printf("Hasil dari perkalian matriks: \n");
	for(i=0;i<b1;i++){
		for(j=0;j<k2;j++)
		{
			printf("%d\t", ans[i][j]);
		}
		printf("\n");
	}
}

pthread_t t1, t2, t3;

int main(){
	int i, j;
	key_t key = 1234;
        int shmid = shmget(key, sizeof(int[10][10]), IPC_CREAT | 0666);
        ans = shmat(shmid, 0, 0);

	pthread_create(&t1, NULL, isi_m1, NULL);
	pthread_join(t1,NULL);

	pthread_create(&t2, NULL, isi_m2, NULL);
	pthread_join(t2,NULL);

	for(i=0;i<b1;i++)
	{
		for(j=0;j<k2;j++)
		{
			ans[i][j]=0;
		}
		pthread_create(&t3, NULL, kali_m, NULL);
		pthread_join(t3,NULL);
	}

	print();
	return 0;
}
