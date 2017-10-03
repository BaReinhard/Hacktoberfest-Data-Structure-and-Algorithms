using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures
{
    class BinaryTree
    {

        public class TreeObject
        {
            TreeObject key;
            TreeObject leftchild = null;
            TreeObject rightchild = null;

            public TreeObject(TreeObject newitem)
            {
                key = newitem;
            }

            public TreeObject getRoot()
            {
                return key;
            }

            public TreeObject getLeftChild()
            {
                return leftchild;
            }

            public TreeObject getRightChild()
            {
                return rightchild;
            }

            public void setRoot(TreeObject newItem)
            {
                key = newItem;
            }

            public void setLeftChild(TreeObject newItem)
            {
                leftchild = newItem;
            }

            public void setRightChild(TreeObject newItem)
            {
                rightchild = newItem;
            }

        }

        public TreeObject init(TreeObject newitem)
        {
            return new TreeObject(newitem);
        }


        public void insertRight(TreeObject self, TreeObject newNode)
        {
            if (self.getRightChild() == null)
            {
                self.setRightChild(newNode);
            }
            else
            {
                TreeObject obj = new TreeObject(newNode);
                obj.setRightChild(self.getRightChild());
                self.setRightChild(obj);
            }
        }


        public void insertLeft(TreeObject self, TreeObject newNode)
        {
            if (self.getLeftChild() == null)
            {
                self.setLeftChild(newNode);
            }
            else
            {
                TreeObject obj = new TreeObject(newNode);
                obj.setLeftChild(self.getLeftChild());
                self.setLeftChild(obj);
            }
        }

    }
}
