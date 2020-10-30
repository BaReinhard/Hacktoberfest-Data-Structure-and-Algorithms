/* Check graph coloring using the Mathematical Theorems of the  Bipartite Graph*/

import java.util.*;

public class BipartiteGraph
{
public static void main(String args[])
{
int choice, nodes;

Scanner scn=new Scanner(System.in);
System.out.println("1. Cycle \n 2. Planer Graph \n 3. Face Map");
System.out.println("Select Type of a Graph");
choice=scn.nextInt();

switch(choice)
{
case 1:
System.out.println("Enter number of nodes in a Cycle");
nodes=scn.nextInt();
if(nodes%2==0)
{
System.out.println("Chromatic Number 2 colors are sufficient");
}
else 
{
System.out.println("Chromatic Number 3 colors are sufficient");
}

break;
case 2:
case 3:
System.out.println("Chromatic Number 4 colors are sufficient");
break;
}
}
}
