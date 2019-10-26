#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
typedef long long ll;

struct pt{
    int x, y;
    pt(int x,int y) : x(x),y(y) {}
};

bool comp(pt &a,pt &b){
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
bool cw(pt a,pt b,pt c){
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}
bool ccw(pt a,pt b,pt c){
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}
void convexHull(vector<pt> &pts){
    if(pts.size()==1)
        return;

    sort(pts.begin(),pts.end(),comp);
    pt p1 = pts[0],p2 = pts.back();

    vector<pt> s1,s2;
    s1.pb(p1);
    s2.pb(p1);

    for(int i=1;i<pts.size();i++){
        if(i==pts.size()-1 || cw(p1,pts[i],p2)){
            while(s1.size()>=2 && !cw(s1[s1.size()-2],s1[s1.size()-1],pts[i]))
                s1.pop_back();
            s1.push_back(pts[i]);
        }
        if(i==pts.size()-1 || ccw(p1,pts[i],p2)){
            while(s2.size()>=2 && !ccw(s2[s2.size()-2],s2[s2.size()-1],pts[i]))
                s2.pop_back();
            s2.push_back(pts[i]);
        }
    }

    pts.clear();
    for(int i=0;i<s1.size();i++)
        pts.pb(s1[i]);
    for(int i=s2.size()-2;i>0;i--)
        pts.pb(s2[i]);
}
int main(){
    vector<pt> pts;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        pts.pb({x,y});
    }
    convexHull(pts);
    cout << "\nConvex Hull: \n";
    for(int i=0;i<pts.size();i++)
        cout << pts[i].x << " " << pts[i].y << "\n";
}
