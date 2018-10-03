void bubbleSort(Integer[] arr) {
    int n = arr.length;
    IntStream.range(0, n - 1)
    .flatMap(i -> IntStream.range(i + 1, n - i))
    .forEach(j -> {
        if (arr[j - 1] > arr[j]) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            }
     });
}