class Tree
{
   
    int diameter(Node root)
    {
        if(root==null)
          return 0;
          
          
        int lh=height(root.left);
        int rh=height(root.right);
        int th=lh+rh+1;
        int ld=diameter(root.left);
        int rd=diameter(root.right);
        int max=Math.max(ld,rd);
        
        int res = Math.max(th,max);
        return res;
        
        
    }
    
    int height(Node root){
        if(root==null)
          return 0;
        return 1+Math.max(height(root.left),height(root.right));
        
    }
}