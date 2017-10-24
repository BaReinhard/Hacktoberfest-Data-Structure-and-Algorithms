<?php 
class Stack { 
    private $_data = array();
    private $_top = -1; 
    public function Pop(){
        if($this->_top == -1){
            throw new Exception("Stack is empty");
        }else{
            $this->_top--;
        }
    }
    public function Push($data) { 

        $this->_top++;
        array_push($this->_data,$data);
    } 
    public function Top(){
        return $this->_data[$this->_top];
    }
    
} 

$stack = new Stack(); 
$stack->Push("First Input");
$stack->Push("Second Input");

echo $stack->Top();
$stack->Pop();
echo $stack->Top();
?> 
