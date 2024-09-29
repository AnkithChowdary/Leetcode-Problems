class AllOne {
public:
    struct Node {
        int count;
        list<string> keys;
        Node* prev;
        Node* next;
        Node(int c) {
            count = c;
            prev = nullptr;
            next = nullptr;
        }
    };

    unordered_map<string, Node*> mp;
    Node* head;
    Node* tail;

    AllOne() {
        head = new Node(0);
        tail = head;
    }

    void addNode(Node* head, int count) {
        Node* newNode = new Node(count);
        newNode->next = head->next;
        newNode->prev = head;

        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        }

        head->next = newNode;

        if (head == tail) {
            tail = newNode;
        }
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }

        if (tail == node) {
            tail = node->prev;
        }

        delete node;
    }

    void inc(string key) {
        // if key doesn't exist
        if (mp.find(key) == mp.end()) {
            if (head->next == nullptr || head->next->count != 1) {
                addNode(head, 1);
            }
            head->next->keys.push_front(key);
            mp[key] = head->next;
        } else {
            Node* currNode = mp[key];
            int currCount = currNode->count;
            if (currNode->next == nullptr || currNode->next->count != currCount + 1) {
                addNode(currNode, currCount + 1);
            }
            currNode->next->keys.push_front(key);
            mp[key] = currNode->next;
            currNode->keys.remove(key);
            if (currNode->keys.empty()) {
                removeNode(currNode);
            }
        }
    }

    void dec(string key) {
        Node* currNode = mp[key];
        int currCount = currNode->count;

        if (currCount == 1) {
            mp.erase(key);
        } else {
            if (currNode->prev->count != currCount - 1) {
                addNode(currNode->prev, currCount - 1);
            }
            currNode->prev->keys.push_front(key);
            mp[key] = currNode->prev;
        }

        currNode->keys.remove(key);
        if (currNode->keys.empty()) {
            removeNode(currNode);
        }
    }

    string getMaxKey() {
        if (tail == head) {
            return "";
        }
        return tail->keys.front();
    }

    string getMinKey() {
        if (head->next == nullptr)
            return "";

        return head->next->keys.back();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
