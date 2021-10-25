import java.util.*;

public class FractionalKnapSack {
    private static double getMax(int[] wt, int[] val,
                                      int capacity)
    {
        ItemValue[] iVal = new ItemValue[wt.length];
  
        for (int i = 0; i < wt.length; i++) {
            iVal[i] = new ItemValue(wt[i], val[i], i);
        }
  
        // sorting items;
        Arrays.sort(iVal, new Comparator<ItemValue>() {
            @Override
            public int compare(ItemValue o1, ItemValue o2)
            {
                return o2.cost.compareTo(o1.cost);
            }
        });
  
        double totalValue = 0d;
  
        for (ItemValue i : iVal) {
  
            int curWt = (int)i.wt;
            int curVal = (int)i.val;
  
            if (capacity - curWt >= 0) {
                capacity = capacity - curWt;
                totalValue += curVal;
            }
            else {
                double rem
                    = ((double)capacity / (double)curWt);
                totalValue += (curVal * rem);
                capacity
                    = (int)(capacity - (curWt * rem));
                break;
            }
        }
  
        return totalValue;
    }
  
    
    static class ItemValue {
        Double cost;
        double wt, val, ind;
  
        public ItemValue(int wt, int val, int ind)
        {
            this.wt = wt;
            this.val = val;
            this.ind = ind;
            cost = new Double((double)val / (double)wt);
        }
    }
  
    public static void main(String[] args)
    {
        int[] wt = { 10, 40, 20, 30 };
        int[] val = { 60, 40, 100, 120 };
        int capacity = 50;
  
        double maxValue = getMax(wt, val, capacity);
  
        
        System.out.println(maxValue);
    }
}