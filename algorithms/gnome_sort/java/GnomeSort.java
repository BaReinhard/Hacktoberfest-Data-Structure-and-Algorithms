
public class GnomeSort {
	
	
	public GnomeSort(int[] list) {
		
		for (int index = 1; index < list.length;) {
			
			if (list[index - 1] <= list[index]) {
				index++;
			} else {
				int tempVal = list[index];
				list[index] = list[index - 1];
				list[index - 1] = tempVal;
				index--;
				if (index == 0) {
					index = 1;
				}
			}
		}
	}
}
