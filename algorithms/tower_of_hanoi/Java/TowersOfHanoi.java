class TowersOfHanoi
{ public static void main (String args[])
  { System.out.println("     F    T");
    move(3, 3, 1, 2); //disks, to, from, temp
  }
  static void move(int n, int to, int from, int temp)
  { if (n > 0) 
    {   move(n-1, temp, from, to);
        System.out.println("move "+from+" -> "+to);
        move(n-1, to, temp, from);
    }//if
  }//move
}//class
/*
 Notes/output
move n?1 discs from S to A. This leaves disc #n alone on peg S 
move disc #n from S to D 
move n?1 discs from A to D so they sit on disc #n 
           f    t
move 1 -> 3
move 1 -> 2
move 3 -> 2
move 1 -> 3
move 2 -> 1
move 2 -> 3
move 1 -> 3
*/