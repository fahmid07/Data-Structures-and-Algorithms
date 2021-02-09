#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{
    int data;
    Node *next;
    Node *prev;
};

Node *create_node(int item, Node * next, Node *prev){
    Node *new_node = (Node *) malloc(sizeof(Node));

    if(new_node == NULL){
        cout << "Error!" << "\n";
        exit(1);
    }

    new_node->data = item;
    new_node->prev = prev;
    new_node->next = next;

    return new_node;
}

Node *prepend(Node *head, int item){
    Node *new_node = create_node(item, head, NULL);
    new_node->next->prev = new_node;
    return new_node;
}

Node *append(Node *head, int item){
    Node *new_node = create_node(item, NULL, NULL);

    if(head==NULL) return new_node;

    Node *current_node = head;

    while(current_node->next != NULL){
        current_node = current_node->next;
    }

    current_node->next = new_node;
    new_node->prev = current_node;

    return head;
}

Node *remove_node(Node *head, Node *node){
    if(node==head){
        head = node->next;
        head->prev = NULL;
        free(node);
        return head;
    }

    Node *previous_node = node->prev;
    Node *next_node = node->next;

    previous_node->next = next_node;
    next_node->prev = previous_node;

    free(node);

    return head;
}

void print_list(Node *head)
{
    Node *current_node = head;
    while(current_node != NULL){
        cout << current_node->data << "\n";
        current_node = current_node->next;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    Node *n1, *head;
    n1 = create_node(10, NULL, NULL);
    head = n1;
    print_list(head);
    head = append(head, 45);
    head = prepend(head, 5);
    print_list(head);
    return 0;
}
