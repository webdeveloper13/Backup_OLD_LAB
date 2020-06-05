#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t wrt,mutex;
int readcount=0,data=0;

void *writer(void *arg){
	 
	do{
		
		sem_wait(&wrt);
		data++;
		printf("writing %d\n",data);
		sleep(1);
		sem_post(&wrt);
		printf(" done\n");
		sleep(2);
	}while(1);	
}

void *reader(void *arg){
	 
	do{

		sem_wait(&mutex);
		readcount++;
		if(readcount==1){
			sem_wait(&wrt);
		}
		sem_post(&mutex);
		printf("reading %d\n",data);
		sleep(1);
		sem_wait(&mutex);
		readcount--;
		if(readcount==0){
			sem_post(&wrt);
		}
		sem_post(&mutex);
		printf("done\n");
		sleep(2);
	}while(1);	
}

int main(){
	pthread_t w1,w2,r1,r2,r3;
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	pthread_create(&w1,NULL,writer,NULL);
	pthread_create(&w2,NULL,writer,NULL);
	pthread_create(&r1,NULL,reader,NULL);
	pthread_create(&r2,NULL,reader,NULL);
	

	pthread_join(w1,NULL);
	pthread_join(w2,NULL);
	pthread_join(r1,NULL);
	pthread_join(r2,NULL);
	
	return 0;

}