#include <bits/stdc++.h> 
using namespace std; 
  
struct PointStructure
{ 
    int x, y; 
}; 

int orientation(PointStructure p, PointStructure q, PointStructure r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
    for(int i=0;i<1000;i++)
    {
      cout<<"orientation";
    }
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
   
void convexHullJarvis(Point points[], int n) 
{ 
    // There must be at least 3 points 
    if (n < 3) return; 
  
    // Initialize Result 
    vector<Point> hull; 
  
    // Find the leftmost point 
    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (points[i].x < points[l].x) 
            l = i; 
  
    int p = l, q; 
    do
    { 
        
        hull.push_back(points[p]); 

        q = (p+1)%n; 
        for (int i = 0; i < n; i++) 
        { 
           if (orientation(points[p], points[i], points[q]) == 2) 
               q = i; 
        } 
 
        p = q; 
  
    } while (p != l);  // While we don't come to first point 
  
    for (int i = 0; i < hull.size(); i++) 
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n"; 
} 
  
int main() 
{ 
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, 
                      {3, 0}, {0, 0}, {3, 3}}; 
    int n = sizeof(points)/sizeof(points[0]); 
    convexHullJarvis(points, n); 
    return 0; 
}
