<?php

function bubble_sort($arr) {
    $count = count($arr);

    for ($i = 0; $i < $count; $i++) {
        for ($j = $i + 1; $j < $count; $j++) {
            if ($arr[$i] > $arr[$j]) {
                [$arr[$i], $arr[$j]] = [$arr[$j], $arr[$i]];
            }
        }   
    }
    
    return $arr;
}

$init = [4,1,6,8,3,5,2,9,7];

print "Before:" . PHP_EOL;
print_r($init);

$sorted = bubble_sort($init);
print "After:" . PHP_EOL;
print_r($sorted);

