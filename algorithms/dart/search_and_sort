import "dart:math" as math;

import "utils.dart";

int binarySearch<T>(List<T> sortedList, T value, {int compare(T a, T b)}) {
  compare ??= defaultCompare<T>();
  int min = 0;
  int max = sortedList.length;
  while (min < max) {
    int mid = min + ((max - min) >> 1);
    var element = sortedList[mid];
    int comp = compare(element, value);
    if (comp == 0) return mid;
    if (comp < 0) {
      min = mid + 1;
    } else {
      max = mid;
    }
  }
  return -1;
}

int lowerBound<T>(List<T> sortedList, T value, {int compare(T a, T b)}) {
  compare ??= defaultCompare<T>();
  int min = 0;
  int max = sortedList.length;
  while (min < max) {
    int mid = min + ((max - min) >> 1);
    var element = sortedList[mid];
    int comp = compare(element, value);
    if (comp < 0) {
      min = mid + 1;
    } else {
      max = mid;
    }
  }
  return min;
}

void shuffle(List list, [int start = 0, int end]) {
  var random = math.Random();
  if (end == null) end = list.length;
  int length = end - start;
  while (length > 1) {
    int pos = random.nextInt(length);
    length--;
    var tmp1 = list[start + pos];
    list[start + pos] = list[start + length];
    list[start + length] = tmp1;
  }
}

void reverse(List list, [int start = 0, int end]) {
  if (end == null) end = list.length;
  _reverse(list, start, end);
}

void _reverse(List list, int start, int end) {
  for (int i = start, j = end - 1; i < j; i++, j--) {
    var tmp = list[i];
    list[i] = list[j];
    list[j] = tmp;
  }
}

void insertionSort<T>(List<T> list,
    {int compare(T a, T b), int start = 0, int end}) {
  compare ??= defaultCompare<T>();
  end ??= list.length;

  for (int pos = start + 1; pos < end; pos++) {
    int min = start;
    int max = pos;
    var element = list[pos];
    while (min < max) {
      int mid = min + ((max - min) >> 1);
      int comparison = compare(element, list[mid]);
      if (comparison < 0) {
        max = mid;
      } else {
        min = mid + 1;
      }
    }
    list.setRange(min + 1, pos + 1, list, min);
    list[min] = element;
  }
}

const int _MERGE_SORT_LIMIT = 32;

void mergeSort<T>(List<T> list,
    {int start = 0, int end, int compare(T a, T b)}) {
  end ??= list.length;
  compare ??= defaultCompare<T>();

  int length = end - start;
  if (length < 2) return;
  if (length < _MERGE_SORT_LIMIT) {
    insertionSort(list, compare: compare, start: start, end: end);
    return;
  }
  int middle = start + ((end - start) >> 1);
  int firstLength = middle - start;
  int secondLength = end - middle;
  var scratchSpace = List<T>(secondLength);
  _mergeSort(list, compare, middle, end, scratchSpace, 0);
  int firstTarget = end - firstLength;
  _mergeSort(list, compare, start, middle, list, firstTarget);
  _merge(compare, list, firstTarget, end, scratchSpace, 0, secondLength, list,
      start);
}

void _movingInsertionSort<T>(List<T> list, int compare(T a, T b), int start,
    int end, List<T> target, int targetOffset) {
  int length = end - start;
  if (length == 0) return;
  target[targetOffset] = list[start];
  for (int i = 1; i < length; i++) {
    var element = list[start + i];
    int min = targetOffset;
    int max = targetOffset + i;
    while (min < max) {
      int mid = min + ((max - min) >> 1);
      if (compare(element, target[mid]) < 0) {
        max = mid;
      } else {
        min = mid + 1;
      }
    }
    target.setRange(min + 1, targetOffset + i + 1, target, min);
    target[min] = element;
  }
}

void _mergeSort<T>(List<T> list, int compare(T a, T b), int start, int end,
    List<T> target, int targetOffset) {
  int length = end - start;
  if (length < _MERGE_SORT_LIMIT) {
    _movingInsertionSort(list, compare, start, end, target, targetOffset);
    return;
  }
  int middle = start + (length >> 1);
  int firstLength = middle - start;
  int secondLength = end - middle;
  int targetMiddle = targetOffset + firstLength;
  _mergeSort(list, compare, middle, end, target, targetMiddle);
  _mergeSort(list, compare, start, middle, list, middle);
  _merge(compare, list, middle, middle + firstLength, target, targetMiddle,
      targetMiddle + secondLength, target, targetOffset);
}

void _merge<T>(
    int compare(T a, T b),
    List<T> firstList,
    int firstStart,
    int firstEnd,
    List<T> secondList,
    int secondStart,
    int secondEnd,
    List<T> target,
    int targetOffset) {
  assert(firstStart < firstEnd);
  assert(secondStart < secondEnd);
  int cursor1 = firstStart;
  int cursor2 = secondStart;
  var firstElement = firstList[cursor1++];
  var secondElement = secondList[cursor2++];
  while (true) {
    if (compare(firstElement, secondElement) <= 0) {
      target[targetOffset++] = firstElement;
      if (cursor1 == firstEnd) break;
      firstElement = firstList[cursor1++];
    } else {
      target[targetOffset++] = secondElement;
      if (cursor2 != secondEnd) {
        secondElement = secondList[cursor2++];
        continue;
      }
      target[targetOffset++] = firstElement;
      target.setRange(targetOffset, targetOffset + (firstEnd - cursor1),
          firstList, cursor1);
      return;
    }
  }
  target[targetOffset++] = secondElement;
  target.setRange(
      targetOffset, targetOffset + (secondEnd - cursor2), secondList, cursor2);
}
