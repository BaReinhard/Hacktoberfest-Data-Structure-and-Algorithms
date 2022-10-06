import java.util.*;
public class KClosestElements {
    public static class pair implements Comparable <pair>{
        int val;
        int gap;
        pair(){

        }
        pair(int val,int gap){
            this.val=val;
            this.gap=gap;
        }
        public int compareTo(pair o){
           if(this.gap!=o.gap){
               return this.gap-o.gap;
           }
           else{
               return this.val-o.val;
           }
        }
    }
    public static ArrayList<Integer>find_K_Closest_Element(int[]arr,int k,int x) {
        ArrayList<Integer>al=new ArrayList<>();
        PriorityQueue<pair>pq=new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0;i<arr.length;i++){
            if(i<k){
                pq.add(new pair(arr[i],Math.abs(x-arr[i])));
            }
            else{
                if(pq.peek().gap > Math.abs(x-arr[i])){
                    pq.remove();
                    pq.add(new pair(arr[i],Math.abs(x-arr[i])));
                }
            }
        }
        while(pq.size()>0){
           pair p=pq.remove();
           al.add(p.val);
        }
        Collections.sort(al);
        return al;
    }

    public static void main(String[]args) {

        //input work
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();

        int[]arr = new int[n];

        for(int i=0; i < n;i++) {
            arr[i] = scn.nextInt();
        }

        int k = scn.nextInt();
        int x = scn.nextInt();

        ArrayList<Integer>ans = findClosest(arr,k,x);

        for(int val : ans) {
            System.out.print(val + " ");
        }

    }
}
