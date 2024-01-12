#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node *link;
    
};


void count(struct node * start ){
    struct node *p;
    int count=1;
    p=start;
    while(p->link!=NULL){
        p=p->link;
        count++;
    }
    printf("The on of the node is %d ",count);

}
void Search(struct node *start ,int item){
    struct node  *p;
    p=start;
    int count=1;
    while(p->link!=NULL)
    {
        if(p->info==item){
            printf("Your item %d found at the position %d",item,count);
            return;
        }
        p=p->link;
        count++;
    }
}
void display(struct node* start){
    struct node*p;
    
    if(start==NULL){
        printf("list is empty");
        return;
    }
    p=start;
    printf("List is ");
    while(p!=NULL){
        printf("%d",p->info);
        p=p->link;
    }
    printf("\n");
}
 
struct node *AddAfter(struct node*start,int item,int data){
    struct node *p,*temp;
    if(start==NULL){
        printf("List is empty:");
        return start ;

    }
    temp=(struct node *)malloc(sizeof (struct node));
    temp->info=data;
    p=start;
    if(start->info==item){
        temp->link=start;
        start=temp;
        return start;

    }
    while (p->link!=NULL){

        if(p->link->link->info==item){

            temp->link=p->link;
            p->link=temp;
            return start;

        }
        p=p->link;
        return start;
    }
}

struct node *Addbefore(struct node *start,int item,int data){

    struct node *p,*temp;
    if(start==NULL){
        printf("List is empty:");
        return start ;

    }
    temp=(struct node *)malloc(sizeof (struct node));
    temp->info=data;
    p=start;

    while (p->link!=NULL){
         
         if(p->info==item){
            temp->link=p->link;
            p->link=temp;
            return start;
         }

         p=p->link;
         return start;
    }
    

}

struct node*AddAtAnyPosition(struct node *start,int pos,int item){

    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
     if(pos==1){
    int i;
    temp->info=item;
    if(pos==1){
        temp->link=start;
        start=temp;
        return start;
    }
    p=start;
    for(i=1;i<pos-1;i++){
        p=p->link;
    }
    if(p==NULL){

        printf("There are not enough elements in which position are you want to enter");
        

    }
    else {
        temp->link=p->link;
        p->link=temp;
    }
    return start;

}



struct node *addatbeg(struct node *start,int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp -> info =data;
    temp -> link =start;
    start=temp;
    return start;
}
struct node *addatend(struct node * start,int data){
    struct node * temp,*p;
    p=start;
    temp=(struct node*)malloc(sizeof(struct node));
    temp -> info =data;
    temp ->link=NULL;
    while(p->link!=NULL){
        p=p->link;
    }
    p->link=temp;
    return start;


}
struct node *createlist(struct node *start){
    
    
    int n,data;
    printf("Enter the no of Node");
    scanf("%d",&n);
    if(n==0){
        return start;
    }

    while(n==0){
        printf("Please enter atmost 1 node");
        scanf("%d",&n);

    }
    printf("Enter the element to be inserted");
    scanf("%d",&data);
    start=addatbeg(start,data);
    for(int i=2;i<=n;i++){
        printf("Enter the element to be inserted");
        scanf("%d",&data);
        start=addatend(start,data);
    }

    return start;
}
void main(){
    struct node *start =NULL;
    int choice,data,item,pos;
    while(1){
        printf("1.Create list \n");

        printf("2.Display \n");

        printf("3.Count \n");

        printf("4.Search\n");

        printf("5.Add to empty list / Add at begining");

        printf("6.Add at end\n");

        printf("7.Add after node\n");

        printf("8.Add befor node\n");

        printf("9.At at postion \n");

        printf("10.Delete \n");

        printf("11.Reverse \n");
        
        printf("12.Quit \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        
    
    switch(choice){
        case 1:
             
             start=createlist(start);
             break;

        case 2:
            
            display(start);
            break;

        case 3:
             
            count(start );
            break;
            

        case 4:
            printf("Enter the elements to be searched");
            scanf("%d",&item);
            Search(start,item);
            break;


        case 5:
             
            printf("Enter the element to be inserted  ");
            scanf("%d",&data);
            start = addatbeg(start,data);
            break;

        case 6:
           
            printf("Enter the element to be inserted  ");
            scanf("%d",&data);
            start = addatend(start,data);
            break;
        case 7:
    
              
            printf("Enter the element  which to be insert after");
            scanf("%d ",&item);
            printf("Enter the data");
            scanf("%d",&data);
            start=AddAfter(start,item,data);
            break;

            
        case 8:

            printf("Enter the element before which to be insert ");
            scanf("%d ",&item);
            printf("Enter the data");
            scanf("%d",&data);
            start=Addbefore(start,item,data);
            break;
        
        case 9:
            if(start==NULL){
                printf("Please enter at least one element into the node");
                break;
            }
            else{
                
            
            printf("Enter the element  to be inserted");
            scanf("%d ",&item);
            printf("Enter the position");
            scanf("%d",&pos);
            start = AddAtAnyPosition(start, pos, item);
            break;           
            }
            


        case 12:
            
            exit(1);

        default:

            printf("Wrong choice:");
            
   }
 }
}

