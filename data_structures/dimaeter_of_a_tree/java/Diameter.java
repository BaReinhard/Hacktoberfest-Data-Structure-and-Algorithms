import java.lang.Math;


class Diameter{
	Node root;

	public Diameter(Node root){
		this.root = root;
	}

   public static int c_diameter(Node node){

   	if(node == null)return 0;


    //heights of left & right subtrees
   	int c_left_height = c_height(node.left);
   	int c_right_height = c_height(node.right);

   	//diameters of left an right subtrees
   	int c_left_diameter = c_diameter(node.left);
   	int c_right_diameter = c_diameter(node.right);

    //return 
    return  Math.max(c_left_height+c_right_height+1,Math.max(c_left_diameter,c_right_diameter));

   }


   public static int c_height(Node node){
   	if(node == null) return 0;


   	return 1 + Math.max(c_height(node.left),c_height(node.right));
   }





	public static void main(String[] args){
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.left.left.left = new Node(6);

		Diameter diameter = new Diameter(root);

		System.out.println(c_diameter(root));

	}
}