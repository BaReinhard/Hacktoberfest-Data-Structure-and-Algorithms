import java.util.*;

class MinHeap {

        const MAX = 50;
        int data[] = new int[MAX];
        int size = 0;

        private void swap(int p, int q) {
            int t = data[p];
            data[p] = data[q];
            data[q] = t;
        }

        void enqueue(int d) {
            data[size] = d;
            int p = size++;
            while (p > 0 && data[p] < data[(p-1)/2]) {
                swap(p,(p-1)/2); //swap data
                p = (p-1)/2; //change pointer to parent
            }
        }

        int dequeue() {
            int d = data[0];
            data[0] = data[--size];
            int p = 0;
            int q = 2*p+1;
            while (true) {
                if (size <= q) break;
                if (size > q+1) {
                    q = data[q]<data[q+1]?q:q+1;
                }
                swap(p,q);
                p = q;
            }
            return d;
        }

    }
}