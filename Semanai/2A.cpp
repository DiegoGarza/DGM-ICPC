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

    ListNode* mergeLists(ListNode* b){
        ListNode* a = this;

        //Temporary head
        ListNode* ans = new ListNode(-1);

        //Aux pointers to traverse lists.
        ListNode* auxA = a;
        ListNode* auxB = b;

        //Auxiliar head to create linked list.
        ListNode* auxAns = ans;

        while(auxA || auxB) {
            if(auxA) {
                auxAns->next = new ListNode(auxA->val);
                auxAns = auxAns->next;
                auxA = auxA->next;
            }
            if(auxB) {
                auxAns->next = new ListNode(auxB->val);
                auxAns = auxAns->next;
                auxB = auxB->next;
            }
        }

        //Delete temporary head node (-1).
        auxAns = ans;
        ans = ans->next;
        delete(auxAns);

        return ans;
    }
};

int main(){
    ListNode *a = new ListNode(5), *b = new ListNode(2), *c;
    ListNode *auxA = a, *auxB = b;

    for(int i = 7; i<20; i += 2){
        auxA->next = new ListNode(i);
        auxA = auxA->next;
    }
    for(int i = 4; i<30; i += 2){
        auxB->next = new ListNode(i);
        auxB = auxB->next;
    }

    c = a->mergeLists(b);

    a->display();
    b->display();
    c->display();

    return 0;
}
