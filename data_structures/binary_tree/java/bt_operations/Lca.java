package binaryTrees;
import java.util.*;
public class Lca {

	//Lowest common ancestor
	
	//LCA: means the ancestor which is at the lowest height;
	
	private static Scanner s = new Scanner(System.in);

	static Vector<Integer> path1 = new Vector<Integer>();
	static Vector<Integer> path2 = new Vector<Integer>();
	
	public static int lca(BinaryTreeNode<Integer> head) {
		
		System.out.println("Find v1: ");
		int v1 = s.nextInt();
		System.out.println("Find v1: ");
		int v2 = s.nextInt();
		int i=0;
		if(findPath(head, path1, v1) && findPath(head, path2, v2)) {
			
			//now we have both the paths
			for(i=0;i<path1.size() && i<path2.size() ;i++) {
				
				//just break from where the common deviates
				if(!path1.get(i).equals(path2.get(i))) {
					break;
				}
			}
		}
		return path1.get(i-1);
	}
	
	public static boolean findPath(BinaryTreeNode<Integer> node, Vector<Integer> path, int value){
		
		if(node == null) {
			return false;
		}
		
		path.add(node.data);
		
		if(node.data == value) {
			return true;
		}
		
		if(node.left!=null && findPath(node.left, path,value)) {
			return true;
		}
		
		if(node.right!=null && findPath(node.right, path,value)) {
			return true;
		}
		
		return false;
	}
	
	public static void main() {
		BinaryTreeNode<Integer> head = BinaryTreeUse.buildBinaryTree();
		System.out.println(lca(head));
		s.close();
	}
}
