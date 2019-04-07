#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i, total_burst = 0, totalt, x, n;
	
	int flg=1;
	
	float avg_wait_time, avg_turn_ar_time;
	
	printf("\nEnter no of processes: ");
	scanf("%d", &n);
	
	int matrix[n][7];

	printf("\nEnter Process_ID, Arrival_time and Burst_time (seperated by space): \n");
	
	for (i = 0; i < n; i++)
	{
		
		scanf("%d %d %d", &matrix[i][0] ,&matrix[i][1] , &matrix[i][2]);
		printf("---------\n");
		if(matrix[i][1]==0 && flg>=0){
			flg--;
		} 
		if(flg==-1){

			printf("\nTwo processes can't have arrival time -> 0 \n");
			exit(0);
		}
		total_burst += matrix[i][2];
		matrix[i][6] = -1;
	}

	//check the process having least arrival time. start processing with that process.
	
	int min=999999,f=0,burst=0;
	for(i=0;i<n;i++){
		
		if(min>matrix[i][1]){
			printf("%d",matrix[i][1]);
			min=matrix[i][1];f=i;
			}
	}
	burst=matrix[f][2];matrix[f][6]=0;matrix[f][3]=matrix[f][1]+matrix[f][2];
	
	total_burst = total_burst + min;
	totalt = burst;
	while (totalt < total_burst)
	{	min=999999;
		for(i=0;i<n;i++){
		if(min>matrix[i][1] && matrix[i][6]==-1) {min=matrix[i][1];f=i;}
		}
		burst=matrix[f][2];
		matrix[f][6]=0;
		matrix[f][3]=totalt+burst+2;
		totalt += burst;
									   
	}
	avg_turn_ar_time = 0.0;
	avg_wait_time = 0.0;
	printf("\n  Process  \tAT   \tBT   \tCT   \tTAT   \tWT   \t");
	printf("\n----------------------------------------------------");
	for (int j = 0; j < n; j++)
	{
		printf("\n|\t %d", matrix[j][0]);
		printf("|\t %d", matrix[j][1]);
		printf("|\t %d", matrix[j][2]);
		printf("|\t %d", matrix[j][3]);
		matrix[j][4] = matrix[j][3] - matrix[j][1];
		printf("|\t %d", matrix[j][4]);
		matrix[j][5] = matrix[j][4] - matrix[j][2];
		printf("|\t %d |", matrix[j][5]);
		avg_wait_time =  + matrix[j][5];
		avg_turn_ar_time = avg_turn_ar_time + matrix[j][4];
		printf("\n----------------------------------------------------");
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