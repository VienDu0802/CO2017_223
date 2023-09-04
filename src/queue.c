#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	if(q->size<MAX_QUEUE_SIZE && q->size>=0)
	{
		q->proc[q->size]=proc;
		q->size++;
	}	
}

struct pcb_t * dequeue(struct queue_t * q) {
		int size = q->size;
		if(size == 0) {
			printf("Queue is empty !!\n"); return NULL;
		}
		if( size ==1 )
		{
			struct pcb_t* return_proc = q->proc[0];
			q->proc[0]=NULL;
			q->size =0;
			return return_proc;
		}
		else if( size >1 && size <= MAX_QUEUE_SIZE)
		{
			struct pcb_t* return_proc= q->proc[0];// process will be returned
			uint32_t highest_prior = q->proc[0]->priority;
			int position =0;
			int i;
			for(i=0 ; i < size ;i++)
			{
				if( highest_prior < q->proc[i]->priority )
				{
					highest_prior =q->proc[i]->priority;
					position = i;
				}	
			}
			return_proc = q->proc[position];
			if(position == (size -1 ))	// highest at the end of queue
			{
				q->proc[position] =NULL;
				q->size = size -1;
				return return_proc;
			}
			else 
			{
				for(i = position+1;i< size; i++)
				{
					q->proc[i-1]=q->proc[i];
				}
				q->proc[size -1]=NULL;
				q->size = size -1;
				return return_proc;
			}		
	}
	return NULL;
}
