class Solution {
    public String countAndSay(int n) {
        String curr="1";
        for(int i=2;i<=n;i++)
        {
            StringBuilder newString=new StringBuilder();
            int c=1;
            char ch=curr.charAt(0);
            for(int j=1;j<curr.length();j++)
            {
                if(curr.charAt(j)==ch)
                {
                    c++;
                }
                else
                {
                newString.append(c);
                newString.append(ch);
                ch=curr.charAt(j);
                 c=1;
                }
            }
            newString.append(c);
                newString.append(ch);
            curr=newString.toString();
        }
        return curr;
    }
}

// Example
// Input: n = 4
// Output: "1211"
