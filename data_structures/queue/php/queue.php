<?php

/**
 * Class Queue by Bennett Treptow
 * Pretty trivial implementation
 * PHP arrays and array_shift do the hard work
 */
class Queue {
    /**
     * @var array
     */
    protected $_data = [];

    /**
     * Queue constructor.
     * @param null $data
     */
    public function __construct($data = null){
        if(!is_null($data)){
            foreach($data as $item){
                $this->enqueue($item);
            }
        }
    }

    /**
     * @return int
     */
    public function size(){
        return count($this->_data);
    }

    /**
     * @param $item
     */
    public function enqueue($item){
        $this->_data[] = $item;
    }

    /**
     * @return mixed
     * @throws Exception
     */
    public function dequeue(){
        if($this->size() > 0){
            return array_shift($this->_data);
        } else {
            throw new Exception('Can\'t dequeue an empty queue!');
        }
    }
}

$queue = new Queue(['1','2','3','4']);
$queue->dequeue(); //1
$queue->enqueue('5'); //2,3,4,5
?>