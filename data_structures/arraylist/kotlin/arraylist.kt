import java.util.ArrayList

fun createArrayList() {

    // Create arrayList
    println("Creating arrayList")
    val arrayList: ArrayList<String> = ArrayList()
    println("Initial size of arrayList: " + arrayList.size)

    // Add arrayList elements
    println("Adding arrayList elements")
    arrayList.add("cheddar")
    arrayList.add("brie")
    arrayList.add("gouda")
    arrayList.add("feta")
    arrayList.add("mozzarella")
    arrayList.add(2, "asiago")
    println("Updated size of arrayList: " + arrayList.size)
    println("Contents of arraylist: $arrayList")

    // Remove elements from the array list
    println("Removing feta")
    arrayList.remove("feta")
    println("Contents of arraylist: $arrayList")
    println("Removing item at index 1")
    arrayList.removeAt(1)
    println("Contents of arraylist: $arrayList")
}
