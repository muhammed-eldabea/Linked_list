/*include all needed library */ 
#include<stdlib.h>  
#include<stdio.h> 

/* linked list can be defined as forward 
*  head>>data>>data>>Null  
*every data node has a pointer hold the address of the next node  
*/



/***************************************************************************************/
                            /* Definations and global variable*/
/****************************************************************************************/
typedef unsigned char    uint8   ; 

typedef struct 
{  
    /* this node represent an element in the data chain */ 
    /*the defined pointer used to point to the next node to make a conenction */ 
    
    unsigned char data ;  
    unsigned char *ptr ; 
    
}node;




/*---------------------------------------------------------------------------------------------------
                                            Function Declearion 
------------------------------------------------------------------------------------------------------*/

void Add_node_to_the_end (node **head,uint8 Data )  ; 
void Print_list(node **head)  ; 
void ADD_node_to_the_first(node **head, uint8 data) ; 
/*----------------------------------------------mainCode--------------------------------------------*/

int main () 
{  
node *head = NULL ; 
     
Add_node_to_the_end(&head,45) ; 
Add_node_to_the_end(&head,44) ; 
Add_node_to_the_end(&head,45) ;
Add_node_to_the_end(&head,61) ;  
ADD_node_to_the_first(&head,1) ; 
Print_list(&head) ; 
    
     return 0 ; 

} 



/*-----------------------------------------------------------------------------------------------------
                                        Function Definations 
--------------------------------------------------------------------------------------------------------*/


void Add_node_to_the_end (node **head,uint8 Data ) 
{ 

/* 
 [Function name] : Add_node_to_the_end    
 [Description] : used to add a node a linked list 
 [Argument] : 
                input >> Data variable with unsigned char type >> as a definations to the input data to the node 
                      >> a  head pointer of the list at which a node will be connected  
                output >> void 
*/

/*creat a new node with name link */
node *link = (node*)malloc(sizeof(node)) ; 

/*store data to the allocated node */ 
link->data = Data ; 
link->ptr = NULL ; 
/*check if we have no node yet */ 

if (head == NULL)
{   
    head=link ; 
    return ;  
} 

node * current = head ;

/*we need to walk until we reach the node last node */
while (current->ptr != NULL) 
{
    current = current->ptr ; 
} 

/*link the last node to the allocated one */
current->ptr = link ; 


}

void ADD_node_to_the_first(node **head, uint8 Data) 
{ 
    /*used to addd a node at the first of the list */

node * link = (node*) malloc(sizeof(node)) ; 

link->data = Data ; 
link->ptr = head ; 
head = link ; 

}












void Print_list(node **head) 
{ 
    /*used to priint the data stored in the list */ 
    /*take the  head pointer of the list  that  will be printed  */
    node *current = head ; 
    printf("head>> \t")  ; 
    while (current != NULL) 
    {
        printf("%d >> \t  ", current->data) ; 
        current=current->ptr ; 
    }
    printf("Null")  ;
} 