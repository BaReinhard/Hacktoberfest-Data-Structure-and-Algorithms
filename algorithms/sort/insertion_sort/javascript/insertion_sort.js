function insertionSort(unsortedList) {
	let len = unsortedList.length;

	for (let i = 1; i < len; i++) {
		let ele = unsortedList[i];

		for (var j = i - 1; j >= 0 && (unsortedList[j] > ele); j--) {
			unsortedList[j+1] = unsortedList[j];
		}

		unsortedList[j+1] = ele;
	}
}