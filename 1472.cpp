1472. Design Browser History
https://leetcode.com/problems/design-browser-history/

class BrowserHistory {
public:
    class Node {
    public:
        Node *prev, *next;
        string val;
        Node(string val) {
            this->val = val;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };
    Node * node;
    BrowserHistory(string homepage) {
        this -> node = new Node(homepage);
        
    }
    
    void visit(string url) {
        Node * newNode = new Node(url);
        this -> node -> next = newNode;
        newNode -> prev = this -> node;
        this -> node = newNode;
    }
    
    string back(int steps) {
        while(steps--){
            if(this -> node -> prev) this -> node = this -> node -> prev;
            else break;
        }
        return this -> node -> val;
    }
    
    string forward(int steps) {
        while(steps--){
            if(this -> node -> next) this -> node = this -> node -> next;
            else break;
        }
        return this -> node -> val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */