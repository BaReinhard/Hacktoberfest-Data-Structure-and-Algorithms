#include <iostream>
#include <stdio.h>
#include "Set.h"
#include "Vector.h"

#define MAXN 100

using namespace std;

Set < int > FinalSet(MAXN);
bool found = false;
Vector < int > G[MAXN];

void Bron(Set < int > R, Set < int > P, Set < int > X) {
    if(P.empty() && X.empty()) {
        FinalSet = R; /*aici*/
        found = true;
    }

    int l = P.size();
    while(l --) {
        int v = (P.begin());/*aici*/
        Set < int > newP(MAXN), newX(MAXN);

        for(int i = 0; i < (int) G[v].mySize(); ++ i) {
            if(P.find(G[v][i])) {/*aici*/
                newP.insert(G[v][i]);
            }

            if(X.find(G[v][i])) {/*aici*/
                newX.insert(G[v][i]);
            }
        }

        if(!found) {
            R.insert(v);
            Bron(R, newP, newX);
            R.erase(v);/*aici*/

            P.erase(P.begin());/*aici*/
            X.insert(v);
        }
    }
}

int main() {
    int m, n, x, y;
    Set < int > P(MAXN), R(MAXN), X(MAXN);
    scanf("%d%d", &n, &m);
    while(m--) {
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
        P.insert(x);
        P.insert(y);
    }

    Bron(R, P, X);

    //printf("%lu\n", FinalSet.size());

    //for(Set < int > :: iterator it = FinalSet.begin(); it != FinalSet.end(); ++ it)
    //    printf("%d ", *it);

    printf("\n");
    return 0;
}
