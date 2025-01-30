class Node
{
    public :
    int val;
    Node* next;
    Node* prev;

    Node(int val)
    {
        this -> val = val;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

class MyLinkedList {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int size;
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index >= size)
        return -1;

        Node* temp = head;
        for(int i = 0;i < index;i++)
        {
            temp = temp->next;
        }

        return temp->val;
    }
    
    void addAtHead(int val) {
        if(!head)
        {
           head = new Node(val);
           size++;
           return;
        }

        Node* newnode = new Node(val);
        newnode->next = head;
        head = newnode;
        size++;
    }
    
    void addAtTail(int val) {
        if(!head)
        {
            head = new Node(val);
            tail = head;
            size++;
            return;
        }

        Node* newnode = new Node(val);
        tail->next = newnode ;
        newnode->prev = tail;
        tail = newnode;
        size++;

    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > size)
            return;

        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        
        Node* newnode = new Node(val);
        Node* temp = head;

        for(int i = 0;i < index-1 ; i++)
        {
            temp = temp->next;
        }
        
        Node* temp2 = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = temp2;

        size++;

    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;

        if(index == 0)
        {
            Node* temp = head;
            head = temp->next;
            temp->next = NULL;
            size --;
            delete temp;
            return;
        }

        Node* temp = head;
        for(int i = 0;i < index -1 ; i++)
        {
            temp = temp->next;
        }

        Node* deletenode = temp->next;
        temp->next = temp->next->next;
        if(temp->next)
           temp->next->prev = temp;
        delete deletenode;
    }
};