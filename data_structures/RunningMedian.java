import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class runningMedian {
	
	public static void runningMedian(int arr[]) {
		
		for(int i=0;i<arr.length;i++) {
			ArrayList<Integer> temp = new ArrayList<Integer>();
			PriorityQueue<Integer> ans = new PriorityQueue<Integer>();
			for(int j=0;j<=i;j++) {
				ans.add(arr[j]);
			}
			while(!ans.isEmpty()) {
				temp.add(ans.remove());
			}
			int x = 0;
			if(temp.size()%2 == 0) {
				x = temp.size()/2;
				System.out.println(temp.get(x)+temp.get(x+1));
				continue;
			}
			else {
				x = temp.size()/2;
				System.out.println(arr[x]);
			}
		}
		
	}

}
