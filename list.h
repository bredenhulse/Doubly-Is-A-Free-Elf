struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(){
        this->val = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int v){
        this->val = v;
        this->next = nullptr;
        this->prev = nullptr;
    }
    Node(int v, Node n){
        this->val = v;
        this->next = &n;
        this->prev = nullptr;
    }
};

class List{
    private:
        Node* front; //points to the front of list
        Node* it; //points to the current node
        int size; // gives size
        bool empty = true; //checks to see if empty

    public:
        List(){
            this->front = new Node('[');
            this->it = front;
            this->size = 0;
        }
        List(int v){
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
            if(it -> next == nullptr){
                
            }
            it = it -> next;
        }
        void move_back(){ //moves iterator to the previous one
            if(it -> prev != nullptr){
                it = it -> prev;
            }
        }
        void push_front(int x){ //Add another value to the front
            Node temp(x,*front);
            front = &temp;
            size++;
            empty = false;
        }
        void pop_front(){ // remove the front
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        void insert_after(int y){ //insert value where desired
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
            empty = false;
        }
        void insert_here(int y){ // Will insert value where iterator is
            Node *temp = new Node(y);
            temp->prev = it->prev;
            temp->next = it;
            it->prev = temp;
            temp->prev = it;
            it->next = temp;
            it = temp;
            empty = false;
            size++;
        }
        void clear(){ //Will empty the list
            Node *temp = front;
            it = front;
        }
        int print_list(){
            it = front;
            bool done = false;
            while(done != true){
                if(it->next == nullptr){
                    std::cout << it->val;
                    std::cout << " ";
                    done = true;
                }
                else
                    while(it->next != nullptr){
                        std::cout << it->val;
                        std::cout << " ";
                        it = it->next;
                }
            }
            return it->val;
        }
};