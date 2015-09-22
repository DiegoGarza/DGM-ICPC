#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

    void display() {
        ListNode* head = this;
        while(head){
            cout<<head->val<<" ";
            head = head->next;
        }
        cout<<endl;
    }

    void addByThree(){
        ListNode *aux = this, *first = aux;
        int count = 0, sum = 0;

        if(!aux) return;

        while(true){
            if(count == 3 || !aux) {
                first->val = sum;
                for(int i=0; i<2 && first->next; i++){
                    ListNode *del = first->next;
                    first->next = first->next->next;
                    delete(del);
                }
                first = aux;
                count = sum = 0;
            }

            if(!aux) break;

            count++;
            sum += aux->val;
            aux = aux->next;
        }
    }
};

int main(){
    ListNode *a = new ListNode(1), *c;
    ListNode *auxA = a;

    for(int i = 7; i<19; i += 2){
        auxA->next = new ListNode(i);
        auxA = auxA->next;
    }

    a->display();
    a->addByThree();
    a->display();

    return 0;
}
