// this project demonstrates the Linear Search in Golang

package main
  
import "fmt"
 
func linearSearch(arr []int, key int) bool {
    for _, item := range arr {
        if item == key {
            return true
        }
    }
    return false
} 
  
func main() {
	arr := []int{95,78,46,58,45,86,99,251,320}
	var searchKey = 99

	if(linearSearch(arr, searchKey) == true){
		fmt.Println(searchKey, "is in the array")
	}else{
		fmt.Println(searchKey, "isn't available in the array")
	}
	

}