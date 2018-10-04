
fn partition<T, F>(array: &mut Vec<T>, cmp_f: &F, low: usize, high: usize) -> usize
where F: Fn(&T, &T) -> bool
{
    let mut i = low;
    for j in low..high {
        if cmp_f(&array[j], &array[high]) {
            array.swap(i, j);
            i = i + 1;
        }
    }
    array.swap(high, i);
    i
}

fn quick_sort_fn<T, F>(array: &mut Vec<T>, cmp_f: &F, low: usize, high: usize)
    where F: Fn(&T, &T) -> bool
{
    if low < high {
        let p = partition(array, &cmp_f, low, high);
        if p > 0 {
            quick_sort_fn(array, cmp_f, low, p-1);
        }
        quick_sort_fn(array, cmp_f, p+1, high);
    }
}

fn quick_sort<T, F>(array: &mut Vec<T>, cmp_f: &F)
    where F: Fn(&T, &T) -> bool
{
    let len = array.len() - 1;
    quick_sort_fn(array, cmp_f, 0, len);
}

fn main()
{
    let mut array = vec![1,3,5,4,8,6,1,2,5];
    println!("Before: {:?}", array);
    quick_sort(&mut array, &|a, b| a < b);
    println!("After: {:?}", array);
}

