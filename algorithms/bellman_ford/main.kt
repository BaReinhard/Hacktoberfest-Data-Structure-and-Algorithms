import java.util.*
//----------------------- Struct Edge --------------------------------//
data class edge(var Start:Int, var Stop:Int, var Weght:Int, var E:Int){
    var StartArray  = Array(E){i -> Start}
    var StopArray   = Array(E){i -> Stop}
    var WeghtArray  = Array(E){i -> Weght}

}
//------------ Struct Graph Number Of Vertex & Edge -------------------//
data class graph(var Vertex:Int, var Edge: Int)                       {
    var edg = edge(0,0,0,Edge)
}
//-------------------------- Create Graph -----------------------------//
fun create( V:Int , E:Int):graph                                      {
    val g = graph(V,E)
    g.edg =  edge(9999,9999,9999,E)

 return g
}
//----------------------- Print Final Answer --------------------------//
fun print(array :Array<Int>)                                          {
    println("vertex \t  distane from parent")
    for (i in array.indices)
        println("$i \t\t\t${array[i]}")
}
//-------------------- BellmanFord Function----------------------------//
fun bellmanford(graphe:graph,Stv:Int)                                 {
    val V = graphe.copy().Vertex
    val E = graphe.copy().Edge

    var arr = Array(V){i -> 9999}

    arr[Stv] = 0
    var A: Int
    var B :Int
    var C : Int

    for (i in 0 until V-1)
        for (j in 0 until E) {
            A = graphe.edg.StartArray[j]
            B = graphe.edg.StopArray[j]
            C = graphe.edg.WeghtArray[j]
            if (arr[A] != 9999  && arr[A]+ C < arr[B])
                arr[B] = arr[A] + C
        }
    print(arr)
}
//--------------------- Input Function --------------------------------//
fun input()                                                           {
    var V : Int
    var E : Int

    var A : Int
    var B : Int
    var W : Int


    val reader = Scanner(System.`in`)

    println("How many vertex !?")
    V = reader.nextInt()

    println("How Many Edge?")
    E = reader.nextInt()


    var g : graph = create(V,E)

    println("Name Of Vertex:")
    for(i in 0 until V)
        print("$i   ")
    println("\n ok sir now enter start, stop vertex and weght edge:" )

    for(i in 0 until E)
    {
        print(" Start Vertex:\t")
        A = reader.nextInt()
        print(" Stop Vertex:\t")
        B = reader.nextInt()
        print(" Weght Edge:\t")
        W = reader.nextInt()

        g.edg.StartArray[i] = A
        g.edg.StopArray[i]  = B
        g.edg.WeghtArray[i] = W

    }
    bellmanford(g,0)
    
}
//--------------------- Lets Start ------------------------------------//
fun main(arg: Array<String>)                                          {
    input()
}
