
// binary min heap data-structure in javascript
function BinaryMinHeap() {
  let list = [];

  // min heap function
  this.minHeap = (arr, n, i) => {
    let smallest = i;
    let l = 2 * i + 1; // left child index
    let r = 2 * i + 2; // right child index

    // If left child is smaller than root
    if (l < n && arr[l] < arr[smallest]) smallest = l;

    // If right child is smaller than smallest so far
    if (r < n && arr[r] < arr[smallest]) smallest = r;

    // If smallest is not root
    if (smallest != i) {
      let temp = arr[i];
      arr[i] = arr[smallest];
      arr[smallest] = temp;

      // Recursively heapify the affected sub-tree
      this.minHeap(arr, n, smallest);
    }
  };

  // Insert Value
  this.insert = (num) => {
    const size = list.length;

    list.push(num);

    if (size !== 0) {
      // minHeap
      for (let i = parseInt(list.length / 2 - 1); i >= 0; i--) {
        this.minHeap(list, list.length, i);
      }
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

    // minHeap the list again
    for (let i = parseInt(list.length / 2 - 1); i >= 0; i--) {
      this.minHeap(list, list.length, i);
    }
  };

  // Return min value
  this.findMin = () => list[0];

  // Remove min val
  this.deleteMin = () => this.delete(list[0]);

  // Remove and return min value
  this.extractMin = () => {
    const min = list[0];
    this.delete(min);
    return min;
  };

  // Size
  this.size = () => list.length;

  // IsEmpty
  this.isEmpty = () => list.length === 0;

  // Return head
  this.getList = () => list;
}

// Test inputs:
const heap = new BinaryMinHeap();

heap.insert(3); // insert 3
heap.insert(4); // insert 4
heap.insert(9); // insert 9
heap.insert(5); // insert 5
heap.insert(2); // insert 2

console.log("Get Head ===> ", heap.getList());

heap.delete(9); // delete 9
console.log("after delete, Get Head ===> ", heap.getList());

heap.insert(7);
console.log("after insert, Get Head ===> ", heap.getList());

// expected outputs:
// console.log("Get Head ===> ", heap.getList()) === [2, 3, 9, 5, 4] 
// console.log("after delete, Get Head ===> ", heap.getList()) === [2, 3, 4, 5]
// console.log("after insert, Get Head ===> ", heap.getList()) === [2, 3, 4, 5, 7]

// size:
// heap.size() === 5

// extractMin heap:
//  heap.extractMin() === 2
//  heap.extractMin() === 3
//  heap.extractMin() === 4
//  heap.extractMin() === 5
//  heap.extractMin() === 9