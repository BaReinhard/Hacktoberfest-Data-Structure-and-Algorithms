<?php
/*
 * @Author: Sushma Kure
 * @ProblemStatement: Binary search in PHP
 */

function binary_search( $sourceArr, $keyword )
{
  $start  = 0;
  $end    = count( $sourceArr ) - 1;
  while ( $start <= $end )
  {
    $middle = ( $start + $end ) / 2;
    if( $keyword == $sourceArr[$middle] ) {

      return $middle;

    } elseif( $keyword < $sourceArr[$middle] ) {

      $end = $middle - 1;

    } else {

      $start = $middle + 1;

    }

  }
  return -1;
}

$sourceArr = range(1, 100, 7);
$keyword   = $sourceArr[ array_rand( $sourceArr ) ];  
$position  = binary_search( $sourceArr, $keyword );
echo '<pre>'; print_r( $sourceArr ); echo '</pre>';
echo ( $position >= 0 ) ? 'Keyword ' . $keyword . ' is found at position: ' . $position :  'Your keyword is not found.';

?>