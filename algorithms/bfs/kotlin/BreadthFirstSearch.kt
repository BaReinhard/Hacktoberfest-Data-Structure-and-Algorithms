mport java.util.LinkedList

class BreadthFirstSearch {
    fun numIslands(grid: Array<CharArray>): Int {
        var result = 0
        
        (0 until grid.size).forEach { x ->
            (0 until grid[0].size).forEach { y ->
                if(grid[x][y] == '1') {
                    bfs(grid, intArrayOf(x, y))
                    result++
                }
            }
        }
        
        return result
    }
    
    private fun bfs(grid: Array<CharArray>, start: IntArray) {
        val queue = LinkedList<IntArray>()
        queue.offer(start)
        grid[start[0]][start[1]] = '0'
        
        while(!queue.isEmpty()) {
            val current = queue.poll()
            val x = current[0]
            val y = current[1]
            
            val top = intArrayOf(x - 1, y)
            val bottom = intArrayOf(x + 1, y)
            val left = intArrayOf(x, y - 1)
            val right = intArrayOf(x, y + 1)
            
            for(point in listOf(top, bottom, left, right)) {
                if(!isIsland(grid, point)) continue
                queue.offer(point)
                grid[point[0]][point[1]] = '0'
            }
        }
    }
    
    private fun isIsland(grid: Array<CharArray>, point: IntArray) =
        point[0] >= 0 && point[1] >= 0 && point[0] < grid.size && point[1] < grid[0].size && grid[point[0]][point[1]] == '1'
}
