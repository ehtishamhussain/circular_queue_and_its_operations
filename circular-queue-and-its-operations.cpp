#include <iostream>
#include <stdlib.h>
using namespace std;

struct circularqueue {
    int r;
    int f;
    int size;
    int *arr;
};

int isfull(struct circularqueue *q){
    if(q->r+1%(q->size)==q->f){
        return 1;
    }
    else{
    return 0;
    }
}
int isempty(struct circularqueue *q){
    if(q->r==q->f){
        return 1;
    }
    else{
        return 0;
    }
}

int dequeue(struct circularqueue *q){
    if (isempty(q)){
        cout<<"Stack underflow";
        return 0;
    }
    else{
    int val;
    q->f=(q->f+1)%(q->size);
    val=q->arr[q->f];
    cout<<val<<endl;
    return 1;
    }

}

int enqueue(struct circularqueue *q, int val){
    if(isfull(q)){
        cout<<"Stack overflow";
        return 0;
    }
    else{
    
    q->r=(q->r+1)%(q->size);
    q->arr[q->r]=val;
    
    return 1;
    }


}
int main(){

    struct circularqueue *q;
    q=(struct circularqueue *)malloc(sizeof(struct circularqueue));
    q->size=10;
    q->r=q->f=0;
    q->arr=(int *)malloc(q->size*sizeof(int));


    enqueue(q,12);
    enqueue(q,14);
    enqueue(q,16);
    enqueue(q,18);

    dequeue(q);
    dequeue(q);
    dequeue(q);
    

    
}