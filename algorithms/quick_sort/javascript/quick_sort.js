/* Quicksort implementation in JavaScript */

function quicksort(arr, p, r) {
	if ( p < r ) {
		q = partition(arr, p, r);
		quicksort(arr, p, q-1);
		quicksort(arr, q+1, r);
	}
	return arr;
}


function partition(arr, p, r) {
	x = arr[r];
	i = p-1;
	var temp;
	for(var j = p; j < r; j++) {
		if (arr[j] < x) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	i++;
	temp = arr[i];
	arr[i] = arr[r];
	arr[r] = temp;

	return i;
}
	

var arr = [9, 8, 7, 6, 5, 4, 3, 2, 1];
console.log(quicksort(arr, 0, arr.length-1));
