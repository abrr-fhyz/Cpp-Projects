#include<stdio.h>
#include<stdlib.h>


struct block{ //fundamental unit
    int data;
    struct block *link; //self-referential struct, pointer points to parent struct
};


struct block* inputL(int data1, struct block *head) //function named input, data type is a block pointer
{
    struct block* current_block= (struct block*) malloc(sizeof(struct block*)); //allocating space
    if(current_block == NULL) //out of bounds
    {
        printf("Out of Bounds\n");
        exit(0);
    }
    else //if memory properly allocated
    {
        //store data
        current_block->data=data1;
        current_block->link=NULL; //don't know next address yet
        if(head==NULL) //if first element
            head=current_block;
        else //all other cases
        {
            //list traversal
            struct block* now=head;
            while((now->link)!=NULL) //while now isnt the last element
                now=now->link; //moving to the next element by jumping on the link

            now->link=current_block; //updating the last element to point to this now
        }
    }
    return head;
}

struct block* insertF(int data1, struct block *head)
{
    struct block* current_block= (struct block*) malloc(sizeof(struct block*));
    if(current_block == NULL)
    {
        printf("Out of Bounds\n");
        exit(0);
    }
    else
    {
        current_block->data=data1;
        current_block->link= head; //set link of current block points to head (previous block)
        head = current_block; //update head as current block
    }

    return head;
}

struct block* insertX(int data1, int position, struct block *head)
{
    struct block* current_block= (struct block*) malloc(sizeof(struct block*));
    if(current_block == NULL)
    {
        printf("Out of Bounds\n");
        exit(0);
    }
    else
    {
        struct block* now=head;
        while((now->data)!=position)
        {
            if(now->link== NULL)
            {
                printf("Element not found\n");
                exit(0);
            }
            now=now->link; //moving to the next element by jumping on the link
        }
        //printf("at the point %d, %d\n", now->data, temp->data);
        current_block->data=data1;
        current_block->link=now->link;
        now->link=current_block;
    }
}

struct block* erase(int position, struct block **head)
{
        //taking **head instead of *head, so i wont have to return head everytime
        struct block* now=*head;
        struct block* temp=*head; //previous element
        while((now->data)!=position)
        {
            if(now->link== NULL)
            {
                printf("Element not found\n");
                exit(0);
            }
            temp=now;
            now=now->link; //moving to the next element by jumping on the link
        }
        //printf("at the point %d\n", now->data);
        if(now==*head) //first element
        {
            *head=now->link; //head is now this element
        }
        else if(now->link==NULL) //last element
        {
            temp->link=NULL; //assign new last element
        }
        else //other cases
        {
            (temp->link)=(now->link); //skip this element
        }
}



void print(struct block* pointer)
{
    if(pointer==NULL)
        printf("bruhh ki hoilo\n");
    else
    {
        while(pointer!=NULL)
        {
            printf("%d ", pointer->data);
            pointer=pointer->link;
        }
    }
    printf("\n");
}


int main()
{
    struct block* head = NULL;
    int n, m, point, x;
    scanf("%d", &n);
    m=n;
    printf("insert at end\n");
    while(n--)
    {
        scanf("%d", &x);
        head=inputL(x, head);
        print(head);
    }

    printf("insert at beginning\n");
    while(m--)
    {
        scanf("%d", &x);
        head=insertF(x, head);
        print(head);
    }

    printf("insert at specific point\n");
    scanf("%d%d", &point, &x);
    insertX(x, point, head); //removing the need to return head
    print(head);

    printf("erase a specific element\n");
    scanf("%d", &x);
    erase(x, &head); //erasing the element x from the list

    print(head);

    return 0;
}
