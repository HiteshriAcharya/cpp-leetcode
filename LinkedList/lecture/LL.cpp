  #include <iostream>
  using namespace std;

  class Node{

  public:

    int data;
    Node* nextAdd;
    Node(int data){

        this->data = data;
        nextAdd = NULL;
    }
  };

  class List{
  public:

      Node *head;
      Node *tail;

      List()
      {
          head = NULL;
          tail = NULL;
      }

    ~List(){

        if(head != NULL){

            delete head;
            head == NULL;
        }
    }

    void push_front(int val){

        Node* newNode = new Node(val); //dynamic allocation
        if(head == NULL){
            head = tail = newNode;
        } else {
            newNode->nextAdd = head;
            head = newNode;
        }
    }

    void push_back(int val){

        Node* newNode = new Node(val);
        if(tail == NULL){
            head = tail = newNode;
        } else {

            tail->nextAdd = newNode;
            tail = newNode;
        }
    }

    void pop_front(){

        Node* temp = head; // just to delete the node later on, 
                           // since it is dynamically allocated

        head = head->nextAdd;
        delete temp;
        temp = NULL;
    }

    void pop_back(){

        Node* temp = head;

        while(temp->nextAdd->nextAdd != NULL){

            temp = temp->nextAdd;
        }

        temp->nextAdd = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int val, int pos){

        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i = 0; i < pos-1; i++){

            if(temp == NULL){
                cout << "This position is invalid" << endl;
            } else{
                temp = temp->nextAdd;
            }
        }

        newNode->nextAdd = temp->nextAdd;
        temp->nextAdd = newNode;
    }

    int searchItr(int key){

        Node* temp = head;
        int idx = 0;

        while(temp != NULL){

            if(temp->data == key){

                return idx;
            }

            idx +=1;
            temp = temp->nextAdd;
        }

        return -1;
    }

    int helper(Node* head, int key){

        Node* temp = this->head;

        if(temp == NULL){
            return -1;
        }

        if(temp->data == key){
            return 0;
        }

        int idx = helper(temp->nextAdd, key);

        if(idx == -1){

            return -1;
        }

        return idx+1;
    }

    int searchRec(int key){

        int idx = helper(head, key);
        return idx;
    }


    void printLL(Node* head){

        Node* temp = head;

        while(temp != NULL){

            cout << temp->data << " ";
            temp = temp->nextAdd;
        }

        cout << endl;
    }

    void reverseLL(){

        Node* prev = NULL;
        Node* curr = head;
        Node* next = head->nextAdd;

        while(curr != NULL){

            next = curr->nextAdd;
            curr->nextAdd = prev;
            prev = curr;
            curr = next;
        }
    }

    void removeNthNode(){

    }

    bool detectCycle(Node* head){

        bool isCycle = false;

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->nextAdd != NULL){

            slow = slow->nextAdd;
            fast = fast->nextAdd->nextAdd;

            if(slow == fast){
                isCycle = true;
                break;
            }
        }

        return isCycle;
    }

    void removeCycle(Node *head){

        Node* slow = head;
        Node* fast = head;

        bool isCycle = false;

        while(fast != NULL && fast->nextAdd != NULL && isCycle != true){

            slow = slow->nextAdd;
            fast = fast->nextAdd->nextAdd;

            if(slow == fast){
                isCycle = true;
            }
        }

        // Right now, slow and fast pointing at the same node
        // Not necessarily the "shared" node

        if(isCycle == false){

            cout << "There is no cycle" << endl;
            return;
        } else{

            slow = head;

            // This means my "shared" node is the head

            if(slow == fast){

                while(fast->nextAdd != slow){
                    fast = fast->nextAdd;
                }

                fast->nextAdd = NULL;
                
            } else{

                Node* prev = fast;

                while(slow != fast){
                    slow = slow->nextAdd;
                    prev = fast;
                    fast = fast->nextAdd;
                }

                prev->nextAdd = NULL;
            }
        }
    }


    Node* splitAtMid(Node* head){

        Node* prev = NULL;
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->nextAdd != NULL){

            prev = slow;
            slow = slow->nextAdd;
            fast = fast->nextAdd->nextAdd;
        }
 
        if(prev != NULL){         // if the list is not a singular node
            prev->nextAdd = NULL; //split in the middle
        }
        return slow;
    }

    Node* merge(Node* head, Node* rightHead){

        Node* i = head;
        Node* j = rightHead;
        List merged;

        while(i != NULL && j != NULL){

            if(i->data <= j->data){
                merged.push_back(i->data);
                i = i->nextAdd;
            } else{
                merged.push_back(j->data);
                j = j->nextAdd;
            }
        }

        while(i != NULL){
            merged.push_back(i->data);
            i = i->nextAdd;
        }

        while(j != NULL){
            merged.push_back(j->data);
            j = j->nextAdd;
        }

        return merged.head;

    }
    

    Node* mergeSortLL(Node* head){

        if(head == NULL || head->nextAdd == NULL){

            return head;
        }

        Node* rightHead = splitAtMid(head);

        Node* left = mergeSortLL(head);
        Node* right = mergeSortLL(rightHead);

        return merge(left, right);
    }

    Node* zigZagRev(Node* head){

        Node* prev = NULL;
        Node* curr = head;
        Node* next = curr->nextAdd;

        while(curr != NULL){

            next = curr->nextAdd;
            curr->nextAdd = prev;

            prev = curr;
            curr = next;
        }

        return prev; // prev is the  head of the reversed LL
    }



    Node* zigZagLL(Node* head){

        Node* rightHead = splitAtMid(head);
        Node* rightHeadRev = zigZagRev(rightHead);

        Node* left = head;
        Node* right = rightHeadRev;

        while(right != NULL && left != NULL){

            Node* nextRight = right->nextAdd;
            Node* nextLeft = left->nextAdd;

            left->nextAdd = right;
            right->nextAdd = nextLeft;

            tail = right; //tail will always be an element from the right array

            left = nextLeft;
            right = nextRight;
        }

        if(right != NULL){

            tail->nextAdd = right;
        }

        return head;
    }
    
  };

  int main(){

    List L1;

    L1.push_front(3);
    L1.push_front(2);
    L1.push_front(1);
    L1.printLL(L1.head);

    L1.push_back(4);
    L1.printLL(L1.head);

    L1.insert(5,4);
    L1.insert(8,2);
    L1.printLL(L1.head);

    L1.pop_front();
    L1.printLL(L1.head);

    L1.head = L1.zigZagLL(L1.head);
    L1.printLL(L1.head);

    L1.pop_back();
    L1.printLL(L1.head);

    L1.head = L1.mergeSortLL(L1.head);
    L1.printLL(L1.head);
  }