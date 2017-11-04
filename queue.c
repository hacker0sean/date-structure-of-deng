/*  lab 4    Design and implementation of queue
 *  Author : sean
 *  warning : the max elements of the queue is 10!!!!!
*/


#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define size 9
#define NULL 0

//global variable
int *MyQueue;
int *header;
int *rear;
int length;

//function reference
void queue_initialize();
void queue_enqueue();
void queue_dequeue();
void queue_foreach();
void queue_length();
void queue_reverse();
void queue_free();

//main function
int main()
{
    char index;
    printf("Enter a integer between 1 and 7 : ");
    while (scanf("%c", &index))
    {
        switch (index){
        case '1':
            queue_initialize();
            break;
        case '2':
            queue_enqueue();
            break;
        case '3':
            queue_dequeue();
            break;
        case '4':
            queue_foreach();
            break;
        case '5':
            queue_length();
            break;
        case '6':
            queue_reverse();
            break;
        case '7':
            queue_free();
            break;
        }
        printf("Enter a integer between 1 and 7 : ");
        fflush(stdin);
    }
    return 0;
}

//function definition
void queue_initialize()
{
    printf ("**********************************************\n");
    printf ("Function : queue_initialize \n\n");
    MyQueue = malloc((size + 1) * sizeof(int));
    header = MyQueue;
    rear = MyQueue;
    printf ("Queue creation completed.");
    length = 0;
    printf ("\n");
    printf ("Queue : ");
    queue_foreach();
    printf ("**********************************************\n");
    return ;
}

void queue_enqueue()
{
    printf ("**********************************************\n");
    printf ("Function : queue_enqueue \n\n");
    int enqueue_num;
    printf ("Before enqueue. Queue : ");
    queue_foreach();
    printf ("Enter an integer : ");
    scanf ("%d", &enqueue_num);
    if (rear == header && length == (size + 1))
    {
        printf ("Error : The queue is full. You must dequeue first and then you can enqueue !\n\n");
        printf ("**********************************************\n");
        return ;
    }
    *rear = enqueue_num;
    if (rear == &MyQueue[size])
    {
        rear = MyQueue;
    }
    else
        rear++;
    length++;
    printf ("After enqueue. Queue : ");
    queue_foreach();
    printf ("**********************************************\n");
    return ;
}

void queue_dequeue()
{
    printf ("**********************************************\n");
    printf ("Function : queue_dequeue \n\n");
    printf ("Before dequeue. Queue : ");
    queue_foreach();
    int dequeue_num;
    if (header == rear && length == 0)
    {
        printf ("Error : The queue is empty and it can't be dequeued. You must enqueue first and then you can dequeue !\n\n");
        printf ("**********************************************\n");
        return ;
    }
    dequeue_num = *header;
    if (header == &MyQueue[size])
    {
        header = MyQueue;
    }
    else
        header++;
    length--;
    printf ("The dequeue number is %d.\n\n", dequeue_num);
    printf ("After dequeue. Queue : ");
    queue_foreach();
    printf ("**********************************************\n");
    return ;
}

void queue_foreach()
{
    int *temp_header = header;
    int *temp_rear = rear;
    int temp_length = length;
    while (temp_length != 0)
    {
        if (temp_header == (&MyQueue[size]))
        {
            printf ("%d ", *temp_header);
            temp_header = MyQueue;
            temp_length--;
            continue;
        }
        printf ("%d ", *temp_header);
        temp_header++;
        temp_length--;
    }
    printf("\n");
    return ;
}

void queue_length()
{
    printf ("**********************************************\n");
    printf ("Function : queue_length \n\n");
    printf ("The length of the queue is %d.\n", length);
    printf ("**********************************************\n");
    return ;
}

void queue_reverse()
{
    printf ("**********************************************\n");
    printf ("Function : queue_reverse \n\n");
    printf ("Before reversing. Queue : ");
    queue_foreach();
    int *temp_header = header;
    int *temp_rear = rear;
    int temp_exchange;
    int temp_length = length;
    int *temp_num;
    if (temp_length <= 1)
    {
        printf ("After reversing. Queue : ");
        queue_foreach();
        printf ("**********************************************\n");
        return ;
    }
    while (temp_length > 1)
    {
        if (temp_rear == MyQueue)
            temp_num = &MyQueue[size];
        else
            temp_num = (temp_rear - 1);
        temp_exchange = *temp_header;
        *temp_header = *(temp_num);
        *(temp_num) = temp_exchange;
        temp_length -= 2;
        if (temp_rear == MyQueue)
            temp_rear = &MyQueue[size];
        else
            temp_rear--;
        if (temp_header == &MyQueue[size])
            temp_header = MyQueue;
        else
            temp_header++;
    }
    printf ("After reversing. Queue : ");
    queue_foreach();
    printf ("**********************************************\n");
    return ;
}

void queue_free()
{
    printf ("**********************************************\n");
    printf ("Function : queue_free \n\n");
    free(MyQueue);
    header = NULL;
    rear = NULL;
    printf ("The queue is free.\n");
    printf ("**********************************************\n");
    return ;
}

