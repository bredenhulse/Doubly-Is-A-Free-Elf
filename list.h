struct Node{
    char val;
    Node* next;

    Node(){
        this->val = 0;
        this->next = nullptr;
    }
    Node(char v){
        this->val = v;
        this->next = nullptr;
    }
    Node(char v, Node n){
        this->val = v;
        this->next = &n;
    }
};

class List{
    private:
        Node* front; //points to the front of list
        Node* it; //points to the current node
        int size; // gives size
        bool empty; //checks to see if empty

    public:
        List(){
            this->front = new Node('[');
            this->it = front;
            this->size = 0;
        }
        List(char v){
            Node n(v);
            this->front = &n;
            this->it = &n;
            this->size = 1;
        }
        char get_iterator(){
            if(it == nullptr){
                return ']';
            }
            else{
                return it->val; // Will return the value where the iterator is
            }
        }
        void begin(){
            it = front; // will move iterator to the beginning
        }
        void end(){
            while(it->next != nullptr){            
                it = it->next; // will move iterator to the end
            }
        }
        bool isEmpty(){ // Check to see if empty
            if(front == nullptr){
                empty = true;
            }
            else{
                empty = false;
            }
            return empty;
        }
        int getfront(){ //Get front value
            return front -> val;
        }
        void move_up(){ //move iterator forward one
            it = it->next;
        }
        void push_front(char x){ //Add another value to the front
            Node temp(x,*front);
            front = &temp;
            size++;
        }
        void pop_front(){ // remove the front
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        void insert_after(char y){ //insert value where desired
            if(it->next != nullptr){
                Node *temp = new Node(y);
                temp->next = it->next;
                it->next = temp;
                it = temp;
            }
            else{
                Node* temp = new Node(y);
                it->next = temp;
                it = temp;
            }
            size++;
        }
        void clear(){ //Will empty the list
            Node *temp = front;
            it = front;
        }
};