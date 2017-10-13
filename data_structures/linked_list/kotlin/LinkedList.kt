import java.util.*

/*
 *  Kotlin Program to Implement Singly Linked List
 */

/*  Class Node  */
internal class Node {
    /*  Function to get data from current Node  */
    /*  Function to set data to current Node  */
    var data: Int = 0
    /*  Function to get link to next node  */
    /*  Function to set link to next Node  */
    var link: Node? = null

    /*  Constructor  */
    constructor() {
        link = null
        data = 0
    }

    /*  Constructor  */
    constructor(d: Int, n: Node?) {
        data = d
        link = n
    }
}

/* Class linkedList */
internal class linkedList {
    private var start: Node? = null
    private var end: Node? = null
    /*  Function to get size of list  */
    var size: Int = 0
    /*  Function to check if list is empty  */
    val isEmpty: Boolean
        get() = start == null

    /*  Constructor  */
    init {
        start = null
        end = null
        size = 0
    }

    /*  Function to insert an element at begining  */
    fun insertAtStart(value: Int) {
        val nptr = Node(value, null)
        size++
        if (start == null) {
            start = nptr
            end = start
        } else {
            nptr.link = start
            start = nptr
        }
    }

    /*  Function to insert an element at end  */
    fun insertAtEnd(value: Int) {
        val nptr = Node(value, null)
        size++
        if (start == null) {
            start = nptr
            end = start
        } else {
            end!!.link = nptr
            end = nptr
        }
    }

    /*  Function to insert an element at position  */
    fun insertAtPos(value: Int, pos: Int) {
        var pos = pos
        val nptr = Node(value, null)
        var ptr = start
        pos =- 1
        for (i in 1 until size) {
            if (i == pos) {
                val tmp = ptr!!.link
                ptr.link = nptr
                nptr.link = tmp
                break
            }
            ptr = ptr!!.link
        }
        size++
    }

    /*  Function to delete an element at position  */
    fun deleteAtPos(pos: Int) {
        var pos = pos
        if (pos == 1) {
            start = start!!.link
            size--
            return
        }
        if (pos == size) {
            var s = start
            var t = start
            while (s !== end) {
                t = s
                s = s!!.link
            }
            end = t
            end!!.link = null
            size--
            return
        }
        var ptr = start
        pos =- 1
        for (i in 1 until size - 1) {
            if (i == pos) {
                var tmp = ptr!!.link
                tmp = tmp!!.link
                ptr.link = tmp
                break
            }
            ptr = ptr!!.link
        }
        size--
    }

    /*  Function to display elements  */
    fun display() {
        print("\nSingly Linked List = ")
        if (size == 0) {
            print("empty\n")
            return
        }
        if (start!!.link == null) {
            println(start!!.data)
            return
        }
        var ptr = start
        print(start!!.data.toString() + "->")
        ptr = start!!.link
        while (ptr!!.link != null) {
            print(ptr.data.toString() + "->")
            ptr = ptr.link
        }
        print(ptr.data.toString() + "\n")
    }
}

/*  Class SinglyLinkedList  */
object SinglyLinkedList {
    fun main(args: Array<String>) {
        val scan = Scanner(System.`in`)
        /* Creating object of class linkedList */
        val list = linkedList()
        println("Singly Linked List Test\n")

        var ch: Char
        /*  Perform list operations  */
        do {
            println("\nSingly Linked List Operations\n")
            println("1. insert at begining")
            println("2. insert at end")
            println("3. insert at position")
            println("4. delete at position")
            println("5. check empty")
            println("6. get size")

            val choice = scan.nextInt()
            when (choice) {
                1 -> {
                    println("Enter integer element to insert")
                    list.insertAtStart(scan.nextInt())
                }
                2 -> {
                    println("Enter integer element to insert")
                    list.insertAtEnd(scan.nextInt())
                }
                3 -> {
                    println("Enter integer element to insert")
                    val num = scan.nextInt()

                    println("Enter position")
                    val pos = scan.nextInt()

                    if (pos <= 1 || pos > list.size)
                        println("Invalid position\n")
                    else
                        list.insertAtPos(num, pos)
                }
                4 -> {
                    println("Enter position")

                    val p = scan.nextInt()
                    if (p < 1 || p > list.size)
                        println("Invalid position\n")
                    else
                        list.deleteAtPos(p)
                }
                5 -> println("Empty status = " + list.isEmpty)
                6 -> println("Size = " + list.size + " \n")
                else -> println("Wrong Entry \n ")
            }

            /*  Display List  */
            list.display()

            println("\nDo you want to continue (Type y or n) \n")
            ch = scan.next()[0]

        } while (ch == 'Y' || ch == 'y')
    }
}
