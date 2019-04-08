#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i, total_burst = 0, totalt, x, n;
	
	int flg=1;
	
	float avg_wait_time, avg_turn_ar_time;
	
	printf("\nEnter no of processes: ");
	scanf("%d", &n);
	
	int matrix[n][8];
	//7 index for remaining time;
	printf("\nEnter Process_ID, Arrival_time, Burst_time and Priority (seperated by space): \n");
	
	for (i = 0; i < n; i++)
	{
		
		scanf("%d %d %d %d", &matrix[i][0] ,&matrix[i][1] , &matrix[i][2],&matrix[i][3]);
		printf("---------\n");
		matrix[i][7]=matrix[i][2];
	}

	
	//sorting according to the arrival time;
	int temp0,temp1,temp2,temp3,temp7;
	for(int i = 0; i < n-1; i++ ){
		for(int j = 0;j<n-1-i;j++){
			if(matrix[j][1]>matrix[j+1][1]){
				
				temp0=matrix[j][0];
				temp7=matrix[j][7];
				temp1=matrix[j][1];
				temp2=matrix[j][2];
				temp3=matrix[j][3];
				matrix[j][0]=matrix[j+1][0];
				matrix[j][7]=matrix[j+1][7];
				matrix[j][2]=matrix[j+1][2];
				matrix[j][3]=matrix[j+1][3];
				matrix[j][1]=matrix[j+1][1];
				matrix[j+1][0]=temp0;
				matrix[j+1][7]=temp7;
				matrix[j+1][1]=temp1;
				matrix[j+1][2]=temp2;
				matrix[j+1][3]=temp3;
			}
		}
	}
	/*
	int flg1=0,time=0,prio=999999;
	while(flg1!=1){
		int i=0,f=0;
		if(matrix[f][7]!=0){
			prio=matrix[f][3];
			time++;
			matrix[f][4]=time;
			matrix[f][7]--;
			while(i!=n-1){
				if(prio>matrix[i][3]) {
					prio=matrix[i][3];
					f=i;
				}
			}
		}
		else{
			f++;
		}
	}*/
    avg_turn_ar_time = 0.0;
	avg_wait_time = 0.0;
	printf("\n  Process  \tAT   \tBT   \tPrio \tCT   \tTAT   \tWT   \t");
	printf("\n--------------------------------------------------------------");
	for (int j = 0; j < n; j++)
	{
		printf("\n|\t %d", matrix[j][0]);
		printf("|\t %d", matrix[j][1]);
		printf("|\t %d", matrix[j][2]);
		printf("|\t %d", matrix[j][3]);
        printf("|\t %d", matrix[j][4]);
		matrix[j][5] = matrix[j][4] - matrix[j][1];
		printf("|\t %d", matrix[j][5]);
		matrix[j][6] = matrix[j][5] - matrix[j][2];
		printf("|\t %d |", matrix[j][6]);
		avg_wait_time =  avg_wait_time+ matrix[j][6];
		avg_turn_ar_time = avg_turn_ar_time + matrix[j][5];
		printf("\n--------------------------------------------------------------");
	}
	avg_turn_ar_time = avg_turn_ar_time / n;
	avg_wait_time = avg_wait_time / n;
	printf("\n-----------------------");

	printf("\n|Average TAT: %f|", avg_turn_ar_time);

	printf("\n-----------------------");
	printf("\n|Average WT: %f |", avg_wait_time);
    
	printf("\n-----------------------\n");
	return 0;


}
