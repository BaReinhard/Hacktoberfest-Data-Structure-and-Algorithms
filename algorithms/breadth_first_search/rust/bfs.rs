
#[derive(Debug)]
struct Node<T>
{
    value: T,
    nodes: Vec<Node<T>>
}

impl <T>Node<T>
{
    fn new(value: T, nodes: Vec<Node<T>>) -> Node<T> {
        Node{ value, nodes }
    }
}

trait Searchable<T>
where T: std::cmp::PartialEq
{
    fn breadth_first_search(&self, value: &T) -> Option<&Node<T>>
        where T: std::cmp::PartialEq;
}

impl <T>Searchable<T> for Node<T>
where T: std::cmp::PartialEq
{
    fn breadth_first_search(&self, value: &T) -> Option<&Node<T>>
    {
        let mut queue = Vec::new();
        queue.push(self);

        while queue.len() > 0 {
            if queue[0].value == *value {
                return Some(&queue[0]);
            }

            for node in &queue[0].nodes {
                queue.push(&node);
            }

            queue.remove(0);
        }
        None
    }
}

fn main()
{
    let root = Node::new(7, vec![
                         Node::new(2, vec![
                                   Node::new(5, vec![]),
                                   Node::new(10, vec![]),
                                   Node::new(8, vec![
                                             Node::new(9, vec![])
                                   ])
                         ]),
                         Node::new(3, vec![
                                   Node::new(6, vec![]),
                                   Node::new(1, vec![
                                             Node::new(4, vec![])
                                   ])
                         ])
    ]
    );

    println!("{:?}", root.breadth_first_search(&1));
    println!("{:?}", root.breadth_first_search(&11));

}
