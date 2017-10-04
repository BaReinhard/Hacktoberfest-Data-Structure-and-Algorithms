"""
Defining a TreeNode class
"""

class TreeNode:
    def __init__(self,k=None):
        self.parent=None
        self.key=k
        self.left=None
        self.right=None

    def isleft(self):
    	if self.parent is None:
    		print("Root")
    	if self.parent.left==self:
    		return True
    	return False
    
    def isright(self):
    	if self.parent is None:
    		print("Root")
    	if self.parent.right==self:
    		return True
    	return False
    def isleaf(self):
    	if self.right is None and self.left is None:
    		return True
    	else:
    		return False		
"""
Binary Search Tree Implementation.
Methods : 
isEmpty()
insert()
delete()
precdecessor()
maximum()
minimum()
successor()
search()

"""

class BST:
    
    def __init__(self):
        self.root=None
    
    def isEmpty(self):
    	if self.root is None:
    		return True
    	return False
    
    def insert(self,key1):
    	temp=TreeNode(key1)
    	if self.isEmpty():
    		self.root=temp
    	else:
    		current=self.root
    		while current is not None:
    			if key1 > current.key:
    				if current.right is None:
    					current.right=temp
    					temp.parent=current
    					break
    				else:
    					current=current.right
    			else:
    				if current.left is None:
    					current.left=temp
    					temp.parent=current
    					break
    				else:
    					current=current.left
    							
    def maximum(self):
    	if self.isEmpty():
    		return "Empty Tree"
    	else:
    		current=self.root
    		while current is not None:
    			if current.right is None:
    				return current.key
    			else:
    				current=current.right		

    def minimum(self):
    	if self.isEmpty():
    		return "Empty Tree"
    	else:
    		current=self.root
    		while current is not None:
    			if current.left is None:
    				return current.key
    			else:
    				current=current.left

    def successor(self,node):
    	if node.key ==self.maximum():
    		return node.key
    	else:
    		if node.right is not None:
    			tempt=BST()
    			tempt.root=node.right
    			return tempt.minimum()
    		else:
    			ch=node
    			p=node.parent
    			while ch is not None:
    				if ch.isleft():
    					return p.key
    				else:
    					ch=p
    					p=p.parent
    def predecessor(self,node):
    	if node.key ==self.minimum():
    		return node.key
    	else:
    		if node.left is not None:
    			tempt=BST()
    			tempt.root=node.left
    			return tempt.maximum()
    		else:
    			ch=node
    			p=node.parent
    			while ch is not None:
    				if ch.isright():
    					return p.key
    				else:
    					ch=p
    					p=p.parent
					

    def search(self,key):					
    	current=self.root
    	while current is not None:
    		if current.key==key:
    			return current
    		elif current.key<key:
    			current=current.right
    		else:
    			current=current.left		
    	return None

    def delete(self,node):
        if self.isEmpty():
            return "Empty tree"
        elif node is None:
        	return "Node not in tree"
        elif node==self.root:
        	pred=self.search(self.predecessor(node))
        	node.key=pred.key
        	self.delete(pred)				
        else:
        	if node.isleaf():
        		if node.isleft():
        			node.parent.left=None
        		else:
        			node.parent.right=None
        	elif node.left is None or node.right is None:
        		if node.left is None:
        			child=node.right
        		else:
        			child=node.left
        		if node.isleft():
        			node.parent.left=child
        			child.parent=node.parent
        		else:
        			node.parent.right=child
        			child.parent=node.parent
        	else:
        		pred=self.search(self.predecessor(node))
        		node.key=pred.key
        		self.delete(pred)
"""
Function to print preorder traversal of tree
"""


def printree(r):
	if r.isleaf():
		print(r.key,end=' ')
	else:
		if r.left is not None:
			printree(r.left)
		if r.right is not None:
			printree(r.right)
		print(r.key,end=' ')
	print(" ")    	
