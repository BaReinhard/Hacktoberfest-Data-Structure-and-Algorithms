function quickSort(list) {
    if (list.length <= 1) { 
        return list
    } else {
        const left = []
        const right = []
        const sorted = []
        const pivot = list.pop() 
        const length = list.length

        for (let i = 0; i < length; i++) {
            if (list[i] <= pivot) {
                left.push(list[i])
            } else {
                right.push(list[i])
            }
        }

        return sorted.concat(quickSort(left), pivot, quickSort(right))
    }
}

const list = [4, 2, 3, 1, 5]

const sorted = quickSort(list)

console.log(sorted)