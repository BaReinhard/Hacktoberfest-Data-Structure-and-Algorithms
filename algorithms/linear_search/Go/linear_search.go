package main
  
import "fmt"
 
func linearsearch(datalist []int, key int) bool {
    for _, item := range datalist {
        if item == key {
            return true
        }
    }
    return false
} 
  
func main() {
    items := []int{1,2,3,4,5,6,7,8,9,10}
    fmt.Println(linearsearch(items,8))
}
