#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int no_of_requests;

int compar(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int fcfs_disk_schedule(int *request_queue, int head)
{
	int i, total_head_movements = 0;
	printf("%d -> ", head);

	for(i = 0; i < no_of_requests; i++)
	{
		printf("%d -> ", request_queue[i]);
		total_head_movements += abs(head - request_queue[i]);
		head = request_queue[i];
	}

	printf("\n%d\n", total_head_movements);
}

int scan_disk_schedule(int *request_queue, int head)
{
	int total_head_movements = 0, i, head_location;

	for(i = 0; head > request_queue[i] && i < no_of_requests; i++);
	head_location = (i == no_of_requests) ? i-1: i;

	printf("%d -> ", head);

	while(i > 0) 
	{
		printf("%d -> ", request_queue[i-1]);
		total_head_movements += abs(head - request_queue[i-1]);
		head = request_queue[i - 1];
		--i;
	}

	total_head_movements += head;
	head = 0;
	i = head_location;
	while(i < no_of_requests)
	{
		printf("%d -> ", request_queue[i]);
		total_head_movements += abs(head - request_queue[i]);
		head = request_queue[i];
		++i;
	}
		
	printf("\n%d\n", total_head_movements);
}

int look_disk_schedule(int *request_queue, int head)
{
	int total_head_movements = 0, i, head_location;

	for(i = 0; head > request_queue[i] && i < no_of_requests; i++);
	head_location = (i == no_of_requests) ? i-1: i;

	printf("%d -> ", head);

	while(i > 0) 
	{
		printf("%d -> ", request_queue[i-1]);
		total_head_movements += abs(head - request_queue[i-1]);
		head = request_queue[i - 1];
		--i;
	}
	
	i = head_location;
	while(i < no_of_requests)
	{
		printf("%d -> ", request_queue[i]);
		total_head_movements += abs(head - request_queue[i]);
		head = request_queue[i];
		++i;
	}
		
	printf("\n%d\n", total_head_movements);
}

int main()
{
	int head, i;
	int *request_queue;

	printf("Enter number of requests\n");
	scanf("%d", &no_of_requests);

	request_queue = (int *) malloc(no_of_requests*sizeof(int));

	printf("Enter values in request queue\n");
	for(i = 0; i < no_of_requests; i++)
		scanf("%d", &request_queue[i]);
	
	printf("Enter current head position\n");
	scanf("%d", &head);

	printf("\nFCFS-----------------------\n");
	fcfs_disk_schedule(request_queue, head);

	qsort(request_queue, no_of_requests, sizeof(int), compar);

	printf("\nSCAN-----------------------\n");
	scan_disk_schedule(request_queue, head);

	printf("\nLOOK-----------------------\n");
	look_disk_schedule(request_queue, head);
}