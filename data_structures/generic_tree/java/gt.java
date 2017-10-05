package practiceds;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class generictree {
	private class node {
		private int data;
		private ArrayList<node> children;

		public node(int data) {
			this.data = data;
			this.children = new ArrayList<>();
		}
	}

	private node root;
	private int size;

	public generictree() {
		Scanner scn = new Scanner(System.in);
		this.root = this.takeinput(scn, null, 0);
	}

	private node takeinput(Scanner scn, node parent, int ithchild) {
		if (parent == null) {
			System.out.println("Enter data for parent node ");
		} else {
			System.out.println("enter data for " + ithchild + "th child of "+parent.data);
		}
		int childdata = scn.nextInt();
		node child = new node(childdata);
		this.size++;
		System.out.println("Enter the number of children for " + childdata);
		int numgranchild = scn.nextInt();
		for (int i = 0; i < numgranchild; i++) {
			node grandchild = takeinput(scn, child, i + 1);
			child.children.add(grandchild);
		}
		return child;
	}

	public int size() {
		return this.size;
	}

	public boolean isempty() {
		return this.size == 0;
	}

	public void display() {
		System.out.println(this);
	}

	@Override
	public String toString() {
		return this.toString(this.root);
	}

	private String toString(node node) {
		String retval = "";
		retval = retval + node.data + " => ";
		for (int i = 0; i < node.children.size(); i++) {
			retval = retval + node.children.get(i).data + " , ";
		}
		retval = retval + " end\n";
		for (int i = 0; i < node.children.size(); i++) {
			retval = retval + this.toString(node.children.get(i));

		}
		return retval;
	}
	public int max (){
		return this.max (this.root);
	}
	private int max (node Node){
		int max=Node.data;
		for (int i=0;i<Node.children.size();i++){
			int maxofchild=max(Node.children.get(i));
			if (maxofchild>max){
				max = maxofchild;
			}
		}
	return max;
	}
	public boolean find(int data){
		return this.find(data,this.root);
	}
	private boolean find(int data,node Node){
		if (Node.data==data){
			return true;
		}
		for (int i=0;i<Node.children.size();i++){
			boolean reschild = this.find (data,Node.children.get(i));
			if (reschild){
				return reschild;
			}
		}
		return false;
	}
	public int height(){
		return this.height(this.root);
	}
	private int height(node node){
		int height=-1;
		for (int i=0;i<node.children.size();i++){
			int childheight = this.height(node.children.get(i));
			if (childheight>height){
				height = childheight;
			}
		}
		height = height +1;
		return height;
	}
	
}
