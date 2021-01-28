#include <stdio.h>
#include <stdlib.h>

int no_of_frames;

int fifo_page_replace(int *frames, char *page_ref_string)
{
	int i = 0, j = 0, no_of_faults = 0, front = 0, hit = 0;
	for(i = 0; i < no_of_frames; i++)
		frames[i] = -1;

	for(i = 0; page_ref_string[i]; i++)
	{
		hit = 0;
		for(j = 0; j < no_of_frames; j++)
			if(frames[j] == page_ref_string[i])
				hit = 1;
		
		
		if(!hit)
		{
			++no_of_faults;
			frames[front] = page_ref_string[i];
			front = (front + 1) % no_of_frames;
		}

		for(j = 0; j < no_of_frames; j++)
			if(frames[j] == -1)
				printf("F");
			else
				printf("%c", frames[j]);
		
		printf("\n");
	}

	printf("Number of page faults: %d\n", no_of_faults);
}

int lru_page_replace(int *frames, char *page_ref_string)
{
	int i = 0, j = 0, k =0, no_of_faults = 0, hit = 0, count = 0;
	int time[no_of_frames], min, minIndex;

	for(i = 0; i < no_of_frames; i++)
		frames[i] = -1;
	
	for(i = 0; page_ref_string[i]; i++)
	{
		hit = 0;

		for(j = 0; j < no_of_frames; j++)
		{
			if(frames[j] == page_ref_string[i])
			{
				hit = 1;
				time[j] = ++count;
			}
		}

		if(!hit)
		{
			++no_of_faults;
			for(j = 0;j < no_of_frames; j++)
			{
				if(frames[j] == -1)
				{
					
					frames[j] = page_ref_string[i];
					time[j] = ++count;
					break;
				}
			}
			if(j == no_of_frames)
			{
				min = time[0];
				minIndex = 0;
				
				for(k = 0; k < no_of_frames; k++)
				{
					if(min > time[k])
					{
						min = time[k];
						minIndex = k;
					}
				}

				frames[minIndex] = page_ref_string[i];
				time[minIndex] = ++count;
			}
		}

		for(j = 0; j < no_of_frames; j++)
			if(frames[j] == -1)
				printf("F");
			else
				printf("%c", frames[j]);
		printf("\n");
	}

	printf("Number of page faults: %d\n", no_of_faults);
}

int main() 
{
	char page_ref_string[30];
	int *frames;

	printf("Enter number of frames\n");
	scanf("%d", &no_of_frames);

	frames = malloc(no_of_frames * sizeof(int));
	

	printf("Enter page reference string\n");
	scanf("%s", page_ref_string);

	printf("\nFIFO\n---------------------------\n");
	fifo_page_replace(frames, page_ref_string);

	printf("\nLRU\n---------------------------\n");
	lru_page_replace(frames, page_ref_string);
}