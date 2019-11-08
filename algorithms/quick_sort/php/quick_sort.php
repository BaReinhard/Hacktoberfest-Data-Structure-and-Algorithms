<?php
 
    function quicksort($array)
    {
        if (count($array) == 0)
            return array();
 
        $pivot = $array[0];
        $left = $right = array();
 
        for ($i = 1; $i < count($array); $i++) {
            if ($array[$i] <$pivot)
                $left[] = $array[$i];
            else
                $right[] = $array[$i];
        }
 
        return array_merge(quicksort($left), array($pivot), quicksort($right));
    }

    $list = array(9,2,1,28,13,17,13,69);
 
    $quick_sorted_numbs = quicksort($list);
 
    die(json_encode($quick_sorted_numbs));