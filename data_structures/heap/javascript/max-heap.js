// binary max heap data-structure in javascript
function BinaryMaxHeap() {
  let list = [];

  //  max heap function
  this.maxHeap = (arr, n, i) => {
    let largest = i;
    let l = 2 * i + 1; // left child index
    let r = 2 * i + 2; // right child index

    // If left child is smaller than root
    if (l < n && arr[l] > arr[largest]) largest = l;

    // If right child is smaller than smallest so far
    if (r < n && arr[r] > arr[largest]) largest = r;

    // If smallest is not root
    if (largest != i) {
      let temp = arr[i];
      arr[i] = arr[largest];
      arr[largest] = temp;

      // Recursively maxHeap the affected sub-tree
      this.maxHeap(arr, n, largest);
    }
  };

  // Insert Value
  this.insert = (num) => {
    const size = list.length;

    list.push(num);

    if (size !== 0) {
      // maxHeap
      for (let i = parseInt(list.length / 2 - 1); i >= 0; i--)
        this.maxHeap(list, list.length, i);
    }
  };

  // Remove value
  this.delete = (num) => {
    const size = list.length;

    // Get the index of the number to be removed
    let i;
    for (i = 0; i < size; i++) {
      if (list[i] === num) break;
    }

    // Swap the number with last element
    [list[i], list[size - 1]] = [list[size - 1], list[i]];

    // Remove the last element
    list.splice(size - 1);

    // maxHeap the list again
    for (let i = parseInt(list.length / 2 - 1); i >= 0; i--)
      this.maxHeap(list, list.length, i);
  };

  // Return max value
  this.findMax = () => list[0];

  // Remove max val
  this.deleteMax = () => this.delete(list[0]);

  //Remove and return max value
  this.extractMax = () => {
    const max = list[0];
    this.delete(max);
    return max;
  };

  // Size
  this.size = () => list.length;

  // IsEmpty
  this.isEmpty = () => list.length === 0;

  // Return head
  this.getList = () => list;
}

// Test inputs:
const heap = new BinaryHeap();

heap.insert(3); // insert 3
heap.insert(4); // insert 4
heap.insert(9); // insert 9
heap.insert(5); // insert 4
heap.insert(2); // insert 2

console.log("Get Head ===> ", heap.getList());

heap.delete(9); // delete 9
console.log("after delete, Get Head ===> ", heap.getList());

heap.insert(7);
console.log("after insert, Get Head ===> ", heap.getList());

// expected outputs:
// console.log("Get Head ===> ", heap.getList()) === [9, 5, 4, 3, 2] 
// console.log("after delete, Get Head ===> ", heap.getList()) === [5, 3, 4, 2]
// console.log("after insert, Get Head ===> ", heap.getList()) === [7, 5, 4, 2, 3]

// size:
// heap.size() === 5

// extractMax heap:
//  heap.extractMax () === 9
//  heap.extractMax () === 5
//  heap.extractMax () === 4
//  heap.extractMax () === 3
//  heap.extractMax () === 2