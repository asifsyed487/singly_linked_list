#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createNode(int number, struct node *next)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = number;
    newNode->next = next;
    return newNode;
};
struct node *newNodeAtEnd(int number, struct node *head)
{
    struct node *newNode;
    newNode = createNode(number, NULL);
    if(head == NULL)
    {
        return newNode;
    }
    struct node *startNode = head;
    while(startNode->next != NULL)
    {
        startNode = startNode->next;
    }
    startNode->next = newNode;
    return head;
}
struct node *newNodeAtBegin(int number, struct node *head)
{
    struct node *newNode;
    if(head == NULL)
    {
        newNode = createNode(number, head);
        return newNode;
    }
    else
    {
        newNode = createNode(number, head);
        return newNode;
    }

}
struct node *newNodeAtPosition(int number, int position, struct node *head)
{
    int i;
    struct node *newNode, *start = head, *startFollower;
    if(head == NULL)
    {
        newNode = createNode(number, head);
        return newNode;
    }
    else
    {
        for(i=0; i<position-1; i++)
        {
            startFollower = start;
            start = start->next;
        }
        newNode = createNode(number, start);
        startFollower->next = newNode;
        return head;


    }
}
struct node *deleteNodeAtEnd(struct node *head)
{
    struct node *start = head;
    struct node *startFollower;
    if(head == NULL)
    {
        printf("\nList is empty.\n");
        return head;
    }
    while(start->next != NULL)
    {
        startFollower = start;
        start = start->next;
    }
    startFollower->next = NULL;
    free(start);
    return head;

}
struct node *deleteNodeAtBegin(struct node *head)
{
    struct node *start;
    start = head;
    if(head == NULL)
    {
        printf("\nList is empty.\n");
        return head;
    }
    head = head->next;
    free(start);
    return head;
}
struct node *deleteNodeAtPosition(int number, int position, struct node *head)
{
    int i;
    struct node *start = head, *startFollower;
    if(head == NULL)
    {
        printf("\nList Empty\n");
        return head;
    }
    else
    {
        for(i=1; i<=position-1; i++)
        {
            startFollower = start;
            start = start->next;
        }
        startFollower->next = start->next;
        free(start);
        return head;


    }
}
struct node *reverseNodeList(struct node *head)
{
    struct node *start, *startFollower;
    if(head != NULL)
    {
        startFollower = head;
        start = head->next;
        head = head->next;
        startFollower->next = NULL;
        while(head != NULL)
        {
            head = head->next;
            start->next = startFollower;
            startFollower = start;
            start = head;
        }
        head = startFollower;
        return head;
    }


}
struct node *removeDuplicateNodes(struct node *head)
{
    struct node *start = head, *startFollow, *duplicate;
    if(head == NULL)
    {
        return head;
    }
    while(start->next != NULL)
    {
        startFollow = start;
        while(startFollow->next!=NULL)
        {
            if(start->data == startFollow->next->data)
            {
                duplicate = startFollow->next;
                startFollow->next = startFollow->next->next;
                free(duplicate);
            }
            else
            {
                startFollow = startFollow->next;
            }
        }
        start = start->next;
    }
    return head;
}
void print(struct node *head)
{
    struct node *start = head;
    if(head == NULL)
    {
        printf("\nEmpty");
    }
    else
    {
        printf("\nUpdated Data's are : ");
        while(start != NULL)
        {
            printf(" %d ", start->data);
            start = start->next;
        }
    }
}
int main()
{
    struct node *head= NULL;
    int choice, number, position, position2;
    while(1)
    {
        printf("\n1.Insert New Node at the end. \n2.Insert Node at the beginning.\n3.Insert Node at any position.\n4.Delete Node from last position.\n5.Delete Node from beginning\n6.Delete Node from any position.\n7.Reverse Linked list.\n8.Remove Duplicate data from Linked list.\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        printf("\n");
        if(choice == 1 || choice == 2 || choice == 3)
        {
            printf("\nEnter Data to be inserted: ");
            scanf("%d", &number);
            if(choice == 1)
            {
                head = newNodeAtEnd(number, head);
                print(head);
                printf("\n");
            }
            else if(choice == 2)
            {
                head = newNodeAtBegin(number, head);
                print(head);
                printf("\n");
            }
            else if(choice == 3)
            {
                printf("\nEnter Position: ");
                scanf("%d", &position);
                head = newNodeAtPosition(number, position, head);
                print(head);
                printf("\n");
            }


        }
        else if(choice == 4)
        {

            head = deleteNodeAtEnd(head);
            print(head);
            printf("\n");
        }
        else if(choice == 5)
        {
            head = deleteNodeAtBegin(head);
            print(head);
            printf("\n");
        }
        else if(choice == 6)
        {
            printf("\nEnter Position: ");
            scanf("%d", &position2);
            head = deleteNodeAtPosition(number, position2, head);
            print(head);
            printf("\n");
        }
        else if(choice == 7)
        {
            head = reverseNodeList(head);
            print(head);
            printf("\n");
        }
        else if(choice == 8)
        {
            head = removeDuplicateNodes(head);
            print(head);
            printf("\n");
        }

    }
}






