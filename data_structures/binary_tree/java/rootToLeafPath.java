class bTree
{
  public void printPaths(Node root)
       {
          //add code here.
          int[] path=new int[1000];
          pathPrint(root,path,0);
          
       }
       void pathPrint(Node root,int[] path,int a){
           if(root==null){
               return;
           }
           path[a]=root.data;
           ++a;
           pathPrint(root.left,path,a);
           pathPrint(root.right,path,a);
           if(root.left==null && root.right==null){
               int[] pathRes=Arrays.copyOfRange(path,0,a);
               System.out.print(Arrays.toString(pathRes).replace("[", "").replace("]", "").replace(",", "") + " #");
           }
       }
}