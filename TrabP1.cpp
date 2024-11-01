#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};
void printar(struct ListNode *p){
        if(p){
            do{
                cout << p->val << endl;
                p = p->next;
            }while(p);
        }
}

void insert(struct ListNode** head,int new_data){
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode*));
    if(*head == NULL){
        new_node->val = new_data;
        *head = new_node;
    }
    else{
        new_node->val= new_data;
        new_node->next = *head;
        *head = new_node;
    }
}

void bubblesort(struct ListNode* primeiroLista,int n){
        ListNode* P1 = primeiroLista;
        ListNode* P2 = primeiroLista->next;
        int temp;
        for(int i = 0;i < n-1;i++){
            for(int j = 0;j < n-i-1;j++){
                if(P2->val < P1->val){
                    temp = P1->val;
                    P1->val = P2->val;
                    P2->val = temp;
                }
                P1 = P1->next;
                P2 = P2->next;
            }
        }
}

void insertionSort(ListNode* primeiroLista,int n){
    ListNode* head = Lista;
    for(int i = 1;i < n;i++){
        int key = head->next->val;
        int j = i - 1;
        while(j >= 0 && head->val > key){
            head->next->val = head->val;
            j = j - 1;
        }
        head->next->val = key;
    }
}

void swap(int* a,int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(struct ListNode* Lista,int high){
    struct ListNode* head = Lista;
    struct ListNode* prev = Lista;
    struct ListNode* last = Lista;
    struct ListNode* curr = Lista;
    int cont = 0;
    while(last != NULL){
        last = last->next;
    }
    for(int i = 0;i < high;++i){
        if(curr->val < last->val){
            prev = prev->next;
            swap(&prev->val,&curr->val);
        }
        cont++;
    }
    swap(&prev->next->val,&last);
    return cont;
}

int main(){
    struct ListNode* a = NULL;
    insert(a,10);
    insert(a,7);
    insert(a,9);
    bubbleSort(a,3);
    if(a){
        printar(a);
    }




    
}