<?php
$input = array('A','B','C','D');
    foreach ($input as $a){
    foreach ($input as $b) {
        if($a == $b){ continue; }
        echo $a.$b.", ";
  }
}
?>