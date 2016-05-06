#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


vector<int> createRandArray(int N){

    vector<int> a(N);
    for(int i=0; i<N; i++){
        a[i] = rand() % 100;
    }

    return a;
}



class supertree{

    class node{
    public:
        int data;
        node *right;
        node *left;
    };

    node *root;

    node *newnode(int num){
        node *newone;
        newone = new node;
        newone->data = num;
        newone->left = NULL;
        newone->right = NULL;

        return newone;
    }

public:
void insert(int num);
void post_order_remove(node *ptr);
void display();
void post_order_display(node *ptr);
void in_order_display(node *ptr);
supertree();
~supertree();

};

supertree::supertree(){
    root = NULL;
}

supertree::~supertree(){
    post_order_remove(root);
    cout<<"\ntree said bye bye\n";
}

void supertree::post_order_remove(node *ptr){

    if(ptr == NULL) return;
    post_order_remove(ptr->left);
    post_order_remove(ptr->right);
    delete ptr;

}

void supertree::insert(int num){
    node *ptr,*current,*next;
    ptr = newnode(num);
    bool isLeft;

    if(root == NULL) {
        root = ptr;
        return;
    }

    current = root;
    while(1){

        if(num < current->data){
            isLeft = true;
            next = current->left;
        }
        else{
            isLeft = false;
            next = current->right;
        }

        if(next == NULL){
            if(isLeft) current->left = ptr;
            else current->right = ptr;
            return;
        }

        current = next;

    }

}


void supertree::display(){
    in_order_display(root);
}

void supertree::post_order_display(node *ptr){

    if(ptr == NULL) return;
    post_order_display(ptr->left);
    post_order_display(ptr->right);
    cout<<ptr->data<<" ";

}

void supertree::in_order_display(node *ptr){

    if(ptr == NULL) return;
    in_order_display(ptr->left);
    cout<<ptr->data<<" ";
    in_order_display(ptr->right);

}


int main(){


    vector<int> a = createRandArray(100);
    supertree tree1;
    for(int i=0; i<100; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n-------------\n";

    for(int i=0; i<100; i++){
        tree1.insert(a[i]);
    }


    tree1.display();


}



