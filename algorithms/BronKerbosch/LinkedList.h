
template<typename T> 
struct Node 
{
    T info;
    struct Node<T> *next, *prev;

    Node <T> & operator=(Node <T> &n)
    {
        info = n.info;
    
        next = n.next;
        prev = n.prev;
    
        return *this;
    }
};

template <typename T> 
class LinkedList {
    
    public:
    struct Node<T> *first, *last;


    LinkedList() /*constructor*/
    {
        first = new Node <T>;
        last = new Node <T>;
        first = NULL;
        last = NULL;
    }

    LinkedList<T> & operator=(LinkedList<T> &l)
        {

            
             while (!this->isEmpty())
                {
                    this->popLast();
                    std::cout<<"Esti noob";
                }

            
           // delete first;
           // delete last;

            first = new Node <T>;
            last = new Node <T>;

            first =  l.first;
            last = l.last;

            while(!l.isEmpty())
            {
                this->pushLast(l.first->info);
                l.popLast();

            }

            return *this;
        }

    Node<T> *front() 
    {
        return first;
    }


    void pushLast(T x) 
    {
        struct Node<T> *aux;

        aux = new struct Node<T>;
        /*adaug toate datele in nod*/
        aux->info = x;
        aux->prev = last;
        aux->next = NULL;

        /*daca nu e singurul element din lista*/
        if (last != NULL) 
            last->next = aux;

        last = aux;/*updatez last*/
        
        /*daca e singurul element*/
        if (first == NULL) 
            first = last;
    }

    void popLast() 
    {
        struct Node<T> *aux;

        /*daca exista elemente in lista*/
        if (last != NULL) 
        {
            /*aux este penultimul element()*/
            aux = last->prev;
            if (first == last) 
                first = NULL;

            delete last;
            last = aux;
            if (last != NULL) 
                last->next = NULL;
        }
        else 
          std::cout<<"The list is empty\n";

    }

    void pop(T x,struct Node <T> *px)
    {

        if (px != NULL) 
        {
            if (px->prev != NULL)
                px->prev->next = px->next;

            if (px->next != NULL)
                px->next->prev = px->prev;

            if (px->prev == NULL) 
                first = px->next;

            if (px->next == NULL) 
                last = px->prev;

            delete px;
        }

    }

    int isEmpty() 
    {
        return (first == NULL);
    }

};


