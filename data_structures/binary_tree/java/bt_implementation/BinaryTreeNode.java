package binaryTrees;

public class BinaryTreeNode<T> {
	
	public T data;
	public BinaryTreeNode<T> left;
	public BinaryTreeNode<T> right;
	
	public BinaryTreeNode(T data) {
		this.data = data;
		this.left = null;
		this.right = null;
	}
	
	public void setLeft(BinaryTreeNode<T> left) {
		this.left = left;
	}
	
	public void setRight(BinaryTreeNode<T> right) {
		this.right = right;
	}
	
}
