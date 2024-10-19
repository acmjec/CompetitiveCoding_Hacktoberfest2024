// solution for LRU Cache 
class LRUCache {
public:
    class Node{
        public:
            int key, value;
            Node* next, *prev;
            Node(int key, int value){
                this->key = key;
                this->value = value;
                next = NULL;
                prev = NULL;
            }
    };

    int capacity;
    unordered_map<int, Node*>mp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head; 

        node->next = temp;
        temp->prev = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        else{
            Node* currNode = mp[key];
            deleteNode(currNode);
            insertAtHead(currNode);
            return currNode->value;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* currNode = mp[key];
            currNode->value = value; 
            deleteNode(currNode);
            insertAtHead(currNode);
        }
        else{
            Node* newNode = new Node(key, value);
            if(mp.size() == capacity){
                Node* todel = tail->prev;
                mp.erase(todel->key);
                deleteNode(tail->prev);
                insertAtHead(newNode);
                mp[key]  = newNode;
                delete todel;
            }
            else{
                insertAtHead(newNode);
                mp[key] = newNode;
            }
        }
    }
};
