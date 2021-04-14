#include<bits/stdc++.h>
using namespace std;

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next)
{
    Node *new_node = (Node *) malloc(sizeof(Node));
    if(new_node == NULL){
        cout << "Error" << "\n";
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
}

Node *prepend(Node *head, int item){
    Node *new_node = create_node(item, head);
    return new_node;
}

Node *append(Node *head, int item){
    Node *new_node = create_node(item, NULL);

    if(head==NULL){
        return new_node;
    }
    Node *current_node = head;
    while(current_node->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
    return head;
}

Node* insertNodeAtPosition(Node *head, int item, int position) {
    Node *newNode = create_node(item, head);

    if (head == NULL) return newNode;

    if (position == 0){
       newNode->next = head;
       return newNode;
    }

    Node *currentNode = head;
    while (position - 1 > 0){
        currentNode = currentNode->next;
        position--;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;

    return head;
}

Node* sortList(Node *head){
    Node *newNode = create_node(head->data, NULL);
    Node *cn = head->next;
    while(cn != NULL){
        Node *cn2 = newNode;
        int pos = 0, value = cn->data;
        while(cn2 != NULL){
            if(cn2->data <= value) pos++;
            else break;
            cn2 = cn2->next;
        }
        newNode = insertNodeAtPosition(newNode, value, pos);
        cn = cn->next;
    }
    return newNode;
}

void print_linked_list(Node *head)
{
    Node *current_node = head;
    while(current_node != NULL){
        cout << current_node->data << "\n";
        current_node = current_node->next;
    }
    cout << endl;
}

void reversePrint(Node *head){
    if(head == NULL) return;
    else{
        reversePrint(head->next);
        cout << head->data << "\n";
    }
}

int count(Node *head){
    int c = 0;
    Node *current_node = head;
    while(current_node != NULL){
        c++;
        current_node = current_node->next;
    }
    return c;
}

Node *remove_node(Node *head, Node *node){
    if(node == head){
        head = node->next;
        free(node);
        return head;
    }
    Node *current_node = head;
    while(current_node != NULL){
        if(current_node->next == node){
            break;
        }
        current_node = current_node->next;
    }
    if(current_node==NULL){
        return head;
    }
    current_node->next = node->next;
    free(node);
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    Node *n1, *head;
    n1 = create_node(10, NULL);
    head = n1;
    print_linked_list(head);

    head = prepend(head, 20);
    print_linked_list(head);

    head = append(head, 30);
    print_linked_list(head);
    n = count(head);
    //cout << "c: " << n << endl;
    return 0;
}
