#include "LinkedList.h"

#define power2 8
template <typename T>
class Set{

public:
        LinkedList <T> *set;
        int smax;
        int hashMask;
        int count;

        LinkedList <T>& operator[](int index)
        {
            return set[index];
        }

        Set<T> & operator=(Set<T> &s)
		{
			for (int i = 0; i < smax; i++)
            {
                 while (!set[i].isEmpty())
                    set[i].popLast();
            }

            delete[] set;

			this->smax =  s.smax;
			this->hashMask = s.hashMask;
      this->count = s.count;
			set = new  LinkedList <T> [smax];
			
			set->first = s.set->first;
			set->last = s.set->last;

			for(int i = 0; i < 256; i++)
			{
				set[i] = s.set[i];
			}

			return *this;
		}

         Set (int smax)
        {
        	count = 0;
            this->smax = smax;
            hashMask = (1<<power2) - 1;/*2^power2-1*/
            set = new LinkedList<T> [smax];
        }

        ~Set()
        {
            for (int i = 0; i < smax; i++)
            {
                 while (!set[i].isEmpty())
                    {
                      set[i].popLast();
                      
                    }
            }

            delete[] set;
        }

        int hash(T ID)
        {
          return ID & hashMask;/*iau ultimii power biti ai numarului*/
        }

		
		void insert(T x)
		{
			count++;
		   struct Node<T> *p;
           T info;

           int skey = hash(x);
           p = set[skey].front();/*prima valoare din lista numarul key*/

           while (p != NULL)
           {
                if (p->info == x) /*daca key exista deja in hashtable*/
                  break;/*se opreste*/
                p = p->next;/*altfel trec la urmatorul*/
           }

           if (p != NULL)/*daca am gasit key in hashtable*/
               p->info = x;/*doar updatez valoarea*/
           else /*daca key nu exista in hashtable il adaug la sfarsitul listei*/
           {    /*corespunzatoare lui key*/
               info = x;
               set[skey].pushLast(info);
           }

		}	

		int find(T x)
        {
            struct Node<T>  *nod;

            int skey = hash(x);
            nod = set[skey].front();
            /*caut key in Hashtable*/
            while (nod != NULL) {
                if (nod->info == x)
                    break;
                nod = nod->next;
            }

            if (nod != NULL)/*daca nu am ajuns la capat inseamna ca l-am gasit*/
                return 1;/*deci exista in Hashtable*/
            else
                return 0;
        }

        int size()
        {
        	return count;
        }

        int empty()
        {
        	return (count == 0);
        }

        int begin()
        {
        	for(int i = 0; i < 256; i++)
        		if(set[i].first != NULL)
        			return set[i].first->info;
        	return 0;
        }

        int end()
        {
        	for(int i = 255; i >= 0; i--)
        		if(set[i].first != NULL)
        			return set[i].last->info;
        	return 0;
        }

        void erase(T x)
        {
           count--;
		   struct Node<T> *p;
           T info;

           int skey = hash(x);
           p = set[skey].front();/*prima valoare din lista numarul key*/

           while (p != NULL)
           {
                if (p->info == x) /*daca key exista deja in hashtable*/
                  break;/*se opreste*/
                p = p->next;/*altfel trec la urmatorul*/
           }

           if (p != NULL)/*daca am gasit key in hashtable*/
            {
            	set[skey].pop(x,p);
       		}
           else /*daca key nu exista in hashtable il adaug la sfarsitul listei*/
           {    /*corespunzatoare lui key*/
               
           		return ; 
           }


        }


};