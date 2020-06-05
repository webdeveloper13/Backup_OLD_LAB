#include<stdio.h>
#include<stdbool.h>

int getVictim(int p, int n, int frame[p], int requests[n], int pos){

	bool frame_flags[p];
	int count = 0;

	for(int i=0;i<p;i++){
		frame_flags[i] = false;
	}

	for(int i=pos-1;i>=0;i--){
		if(count < p-1){
			for(int j=0;j<p;j++){
				//printf("\nFor request %d count = %d", requests[i], count);
				if(requests[i] == frame[j] && frame_flags[j] == false){
					count++;
					frame_flags[j] = true;
					break;
				}
			}
		}
	}

	for(int i=0;i<p;i++){
		if(frame_flags[i] == false)
			return frame[i];
	}
}

int main(){

	int p;
	printf("\nEnter frame size: ");
	scanf("%d", &p);

	int n;
	printf("\nEnter number of requests: ");
	scanf("%d", &n);

	int requests[n];
	printf("\nEnter requests: ");
	for(int i=0;i<n;i++)
		scanf("%d", &requests[i]);

	int pageHit = 0, pageFault = 0;
	int count = 0;
	int frame[p];

	//initial frame filling
	for(int i=0;i<p;i++){
		frame[i] = requests[i];
		printf("\nPage Fault for %d", requests[i]);
		pageFault++;
	}

	for(int i=p;i<n;i++){

		int flag = 0;

		for(int j=0;j<p;j++){
			//if request is found
			if(requests[i] == frame[j]){
				pageHit++;
				flag = 1;
				printf("\nPage Hit for %d\n", requests[i]);
				break;
			}
		}


		printf("\n");
		for(int i=0;i<p;i++)
			printf("%d ",frame[i]);

		if(flag == 1){
			continue;
		}

		//if not found
		pageFault++;
		
		int victimPage = getVictim(p, n, frame, requests, i);

		printf("\nPage Fault for %d", requests[i]);
		printf("\nReplacing %d\n", victimPage);
		for(int j=0;j<p;j++){
			if(victimPage == frame[j]){
				frame[j] = requests[i];
			}
		}

		for(int i=0;i<p;i++)
			printf("%d ",frame[i]);


	}

	printf("\nPage Hits = %d\nPage Faults = %d\n", pageHit, pageFault);

}