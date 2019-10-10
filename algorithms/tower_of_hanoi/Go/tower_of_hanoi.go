package main
  
import "fmt"
 
type solver interface {
    play(int)
}
   

type towers struct {
    
}


func (t *towers) play(n int) {    
    t.moveN(n, 1, 2, 3)
}
  

func (t *towers) moveN(n, from, to, via int) {
    if n > 0 {
        t.moveN(n-1, from, via, to)
        t.moveM(from, to)
        t.moveN(n-1, via, to, from)
    }
}
 
func (t *towers) moveM(from, to int) {
    fmt.Println("Move disk from rod", from, "to rod", to)
}
 
func main() {
    var t solver    
    t = new(towers) 
    t.play(4)
}
