/**
  * Scala implementation of binary search algorithm to search an element in a sorted list
  */

import scala.annotation.tailrec

object BinarySearch {

  def binarySearch(arr: List[Int], elem: Int): Int = {
    binarySearch(arr,elem,0,arr.length)
  }

  def binarySearch(arr: List[Int], elem: Int, fromIndex: Int, toIndex: Int): Int = {

    @tailrec
    def searchHelper(lo: Int, hi: Int): Int = {
      if (lo > hi)
        -1
      else {
        val mid: Int = lo + (hi - lo) / 2
        arr(mid) match {
          case mv if (mv == elem) => mid
          case mv if (mv <= elem) => SearchImpl(mid + 1, hi)
          case _ => SearchImpl(lo, mid - 1)
        }
      }
    }

    searchHelper(fromIndex, toIndex-1)
  }
}