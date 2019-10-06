#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 10000007

ll GetSizeofSegTree(ll n){
  // Allocate memory for segment tree 
	ll x = (int)(ceil(log2(n))); // Height of the tree 
	// Maximum size of segment tree 
	ll max_size = 2 * (ll)pow(2, x) - 1; 
    return max_size;
}

//build minimum seg array
void BuildMinTree(ll *segtree, ll input[], ll low, ll high, ll pos){
    if(high==low){
        segtree[pos] = input[low];
        return;
    }
    int mid = (low+high)/2;
    BuildMinTree(segtree, input, low, mid, 2*pos+1); // left child
    BuildMinTree(segtree, input, mid+1, high, 2*pos+2); // right child

    segtree[pos] = min(segtree[2*pos+1], segtree[2*pos+2]);
}

ll RangeMinimumQuery(ll segtree[], ll qlow, ll qhigh, ll low, ll high, ll pos){
    if(qlow<=low && qhigh>=high){//total overlap
        return segtree[pos];
    }
    if(qlow>high || qhigh<low){ // no overlap
        return INT_MAX;
    }

    //trace(qlow, qhigh, low, high, pos);

    // if partial overlap search both sides
    ll mid = (high+low)/2;

    return min(RangeMinimumQuery(segtree, qlow, qhigh, low, mid, 2*pos+1), RangeMinimumQuery(segtree, qlow, qhigh, mid+1, high, 2*pos+2));
}

// Lazy Propgation
void updateLazyPropagationRangeMin(ll *segTree, ll *lazy, ll startRange, ll endRange ,ll delta, ll low, ll high, ll pos){
    if(low>high){
        return;
    }

    //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.

        //sanyam ne isko alag function mein daala hain
    if(lazy[pos]!=0){
        segTree[pos] += lazy[pos];
        if(low!=high){
            lazy[2*pos+1] +=lazy[pos];
            lazy[2*pos+2] +=lazy[pos];
        }
        lazy[pos] = 0;
    }

    //no overlap
    if(startRange>high || endRange<low){
        return;
    }

    //total overlap
    if(startRange<=low && endRange>=high){
        segTree[pos] += delta;
        if(low!=high){
            lazy[2*pos+1]+= delta;
            lazy[2*pos+2]+= delta;
        } 
        return;
    }

    //partial overlap
    int mid = (low+high)/2;
    updateLazyPropagationRangeMin(segTree, lazy, startRange, endRange, delta, low, mid, 2*pos+1);
    updateLazyPropagationRangeMin(segTree, lazy, startRange, endRange, delta, mid+1, high, 2*pos+2);
    segTree[pos] = min(segTree[2*pos+1], segTree[2*pos+2]);

    
}

ll rangeMinimumQueryLazy(ll *segTree, ll *lazy, ll qlow, ll qhigh, ll low, ll high, ll pos){
    if(low>high){
        return INT_MAX;
    }

    //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
    if(lazy[pos]!=0){
        segTree[pos] += lazy[pos];
        if(low!=high){
            lazy[2*pos+1] += lazy[pos];
            lazy[2*pos+1] += lazy[pos];
        }
        lazy[pos]=0;
    }

    //no overlap
    if(qhigh<low || qlow>high){
        return INT_MAX;
    }    
    
    //total overlap
    if(qlow <= low && qhigh >= high){
        return segTree[pos];
    }

    //paetial  overlap
    //partial overlap
        int mid = (low+high)/2;
        return min(rangeMinimumQueryLazy(segTree, lazy, qlow, qhigh,
                        low, mid, 2 * pos + 1),
                rangeMinimumQueryLazy(segTree, lazy,  qlow, qhigh,
                        mid + 1, high, 2 * pos + 2));


}

void BuildSumSegTree(ll *segtree, ll input[], ll low, ll high, ll pos){
    // If there is one element in array, store it in current node of  
    // segment tree and return  
    if(low==high){
        segtree[pos] = input[low];
        return;
    }

    ll mid = (high+low)/2;
    BuildSumSegTree(segtree, input, low, mid, 2*pos+1);
    BuildSumSegTree(segtree, input, mid+1, high, 2*pos+2);

    //EVerything is same as range minimum segtree except we sum it
    segtree[pos] = segtree[2*pos+1] + segtree[2*pos+2];
}

void update(ll *segTree, ll index, ll delta, ll low, ll high, ll pos){// delta = the value by which it has to be updated
    //if index to be updated is less than low or higher than high just return.
        if(index < low || index > high){
            return; //no overlap
        }
        
        //if low and high become equal, then index will be also equal to them and update
        //that value in segment tree at pos
        if(low == high){
            segTree[pos] += delta; // total overlap
            return;
        }

        //otherwise keep going left and right to find index to be updated 
        //and then update current tree position if min of left or right has
        //changed.
        ll mid = (low + high)/2;
        update(segTree, index, delta, low, mid, 2 * pos + 1);  // left tree
        update(segTree, index, delta, mid + 1, high, 2 * pos + 2); // right tree
        segTree[pos] = min(segTree[2*pos+1], segTree[2*pos + 2]);
}



ll RangeSumQuery(ll *segtree, ll qlow, ll qhigh, ll low, ll high, ll pos){
    if(qlow<=low && qhigh>=high){ //total overlap
        return segtree[pos];
    }
    if(qlow>high || qhigh<low){
        return 0; // so that sum adds to 0 which does not affect anything
    }
    //trace(qlow, qhigh, low, high, pos);
    //else go both side
    ll mid = (high+low)/2;
    return RangeSumQuery(segtree, qlow, qhigh, low, mid, 2*pos+1)+RangeSumQuery(segtree, qlow, qhigh, mid+1, high, 2*pos+2);

}


int main()
{
    ll input[] = {-1, 2, 4, 0};
    ll n = sizeof(input)/sizeof(input[0]);  
    ll segTree[GetSizeofSegTree(n)];
    BuildSumSegTree(segTree, input, 0, 3, 0);

    for(ll i=0; i<=6; i++){
        cout<<segTree[i]<<" ";
    }
    cout<<endl;
    cout<<RangeSumQuery(segTree, 1, 3, 0, 3, 0);

}
