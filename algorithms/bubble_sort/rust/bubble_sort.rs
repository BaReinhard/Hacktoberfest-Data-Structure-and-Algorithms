//Bubblesort with first Element first order, inplace (with 1 additional space for the swap)
pub fn bubble_sort_t<T, F>(array: &mut Vec<T>, compare: F) -> &mut Vec<T> where F: Fn(&T,&T) -> bool {
    for outer in 0..array.len() {
        for inner in 0..(array.len() - 1) {
            if compare(&array[outer], &array[inner]) {
                array.swap(outer, inner);
            }
        }
    }
    array
}

fn main() {
    let mut sorting_vec: Vec<i32> = vec![10, 19, 13, 1, 11, 7, 3, 8, 0];
    
    bubble_sort_t(&mut sorting_vec, |x,y| x < y);

    println!("{:?}", &sorting_vec);
}
