
#include <stdio.h>
#include <stdlib.h>

#include <string.h>



typedef struct dynarray_struct{
    int *array;
    int size;
    
    
}dynarray;

void init_dynarray(dynarray * da, int size){
    //dynarray *da;
    da->size=size;
    //
    da ->array=(int*)calloc(size, sizeof(int));
    
    if(da->array==NULL){
        printf("no memory no array");
        da->size=0;
        return;
        
    }
    
    else{
        
       // printf("get an arrya of size %d  at memory %p ",da->size, da->array);
    }
    
   //da=(dynarray*) calloc(1,sizeof(dynarray));
    //release memory otherwise memory leak
    
    
}

void setValue(dynarray *da,int index, int value){
    
    // this functio sets the value of the index entry in the array to value and if the indes is //larger than the size of the array it resizes the array
    int *new_array=NULL;
    
    if (index<da->size){
        *(da->array+index)=value;
        
        return;
    }
    
    
    //need to get more memory need to copy old array into new space update dynamic array compd data type
    //
    new_array=(int*)calloc(2*da->size, sizeof(int));
    printf("resizing%d\n", 2*da->size);
    if (new_array==NULL){
        
        printf("sorry, out of mem");
        return;
    }
    //  get space copy the odl array into the new array
    for (int i=0; i<da->size; i++){
        *(new_array+i)=*(da->array+i);
        
    }
    da ->array=new_array;
    
    //must release old arrays there would be memory leak so you use more storage
    //
    free(da->array);
    //calloc keeps a table and sees how much memory is resaoved, free sees it and frees that memory
    da -> size=2*da->size;
    //update value
    *(da->array+index)=value;
    return;
}

int main() {

    dynarray my_array;
    init_dynarray(&my_array,10);
    
    //free(my_array.array);
    
    for(int i=0; i<150;i++){
        //use offsets
        //my array.array is a pointer to int
        
        //*(my_array.array+i)=i*i;
        setValue(&my_array, i,i*i);
        
        
        
        
        printf("entry %d contains %d\n",i, *(my_array.array+i));
        
        
    }
    
    return 0;
}
//malloc: be careful 6 gb of memory
//while true: calloc calloc calloc.
//memory hog.1024*1024*1024 1 gb  bytes
//malloc is only pinters not the thing
// table for 20, not here yet, go sit.
//somebody also get the same table
//yeah there is enough memory, not actually using it, not giving it to you
//press enter
//malloc uses one that had memory and it got killed
//calloc doesnt do that you initialize it and  its yours malloc u d k

//linked lists*********************
//tasks: need to do make a
//cdt:
//need 2: 1 for the review
//1 for the linked list node
//linekd list node is a data payload and a pointer
//typedef struct the node(int){
//review rev;
//node_struct *next;}node;

typedef struct review_str{
    char name[100];
    int score;
}review;
typedef struct llnode_struct{
    review rev;
    struct llnode_struct *next;
}node;

//write function to allocate and initial e a new linked lizt
node *new_node(char name[100], int score){
    
    // allocates and initializes a node
    node *new;
    
    new=(node*) calloc(1, sizeof(int));
    //check for null
    if(new==NULL){
        printf("fuck");
        return new;
        
    }
    
    new->rev.score=score;
    strcpy(new->rev.name, name);
    return new;
    
    
}
/*
main
node * my;
my=new_node("l",2);
 printf(my->rev.name, my->rev.score);
 free(my);
 return 0;
*/
