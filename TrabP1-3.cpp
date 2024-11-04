#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
};
void printar(struct ListNode* head){
    ListNode* p = head;
    while(p != NULL){
        cout << p->val << endl;
        p = p->next;
    }
    cout << "Null\n";
}

ListNode* insert(struct ListNode* head,int new_data){

    struct ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->val = new_data;
    new_node->next = head;
    return new_node;
}

void bubblesort(struct ListNode* head){
    struct ListNode *end,*p,*q;
    int temp;
    for(end = NULL;end != head->next;end=p){
        for(p = head;p->next != end;p=p->next){
            q = p->next;
            if(p->val > q->val){
                temp = p->val;
                p->val = q->val;
                q->val = temp;
            }
        }
    }
}

void insertNode(ListNode *newlist,ListNode* myinsertNode){
    if(newlist == NULL){
        newlist = myinsertNode;
    }
    else if(myinsertNode->val <=newlist->val){
        myinsertNode->next = newlist;
        newlist = myinsertNode;
        return;
    }
    else{
        ListNode*current = newlist;
        while(current != NULL){
            if(current->next == NULL && myinsertNode->val >= current->val){
                current->next = myinsertNode;
                return;
            }
            if(myinsertNode->val >= current->val && myinsertNode->val <= current->next->val){
                myinsertNode->next = current->next;
                current->next = myinsertNode;
                return ;
            }
            current = current->next;
        }
    }
}
ListNode* insertionSort(ListNode *head){
    ListNode *current = head;
    ListNode *newlist = NULL;
    while(current != NULL){
        ListNode* myinsertNode = current;
        current = current->next;
        myinsertNode->next = NULL;
        insertNode(newlist,myinsertNode);
    }
    return newlist;
}

ListNode* findTail(ListNode* head){
    ListNode* tail = head;
    while(head != NULL){
        tail = head;
        head = head->next;
    }
    return tail;
}
ListNode* partition(ListNode* head,ListNode* tail){
    ListNode* pivot = head;
    ListNode* pre = head;
    ListNode* curr = head;
    while(curr != tail->next){
        if(curr->val < pivot->val){
            swap(pivot->val,pre->val);
            pre=pre->next;
        }
        curr = curr->next;
    }
    swap(pivot->val,pre->val);
    return pre;
}
void quicksortOG(ListNode* head,ListNode* tail){
    if(head == NULL || head == tail){
        return;
    }
    ListNode* pivot = partition(head,tail);
    quicksortOG(head,pivot);
    quicksortOG(pivot->next,tail);
}

ListNode* quicksort(ListNode*head){
    ListNode* tail = findtail(head);
    quicksortOG(head,tail);
    return head;
}

/*void insertionSort(ListNode* primeiroLista,int n){
	// o que seria esse Lista aqui?
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
}*/

int main(){
    cout << "teste\n";
    struct ListNode* head = NULL;
    //head = insert(head,6);
    head = insert(head,4);
    //head = insert(head,8);
    head = insert(head,3);
    head = insert(head,5);
    //bubblesort(head);
    insertionSort(head);
    printar(head);
}