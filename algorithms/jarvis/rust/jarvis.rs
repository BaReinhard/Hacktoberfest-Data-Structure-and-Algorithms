
#[derive(Debug)]
struct Point
{
    x: i32,
    y: i32,
}

impl Point
{
    fn new(x: i32, y: i32) -> Point
    {
        Point{ x, y}
    }
}

impl std::cmp::PartialEq for Point {
    fn eq(&self, p: &Point) -> bool {
        return self.x == p.x && self.y == p.y
    }
}

fn angel_cos(point1: &Point, point2: &Point, point3: &Point) -> f64
{
    let v1 = (point1.x as f64 - point2.x as f64, point1.y as f64 - point2.y as f64);
    let v2 = (point3.x as f64 - point2.x as f64, point3.y as f64 - point2.y as f64);
    let v1_len = (v1.0.powf(2.0) + v1.1.powf(2.0)).sqrt();
    let v2_len = (v2.0.powf(2.0) + v2.1.powf(2.0)).sqrt();

    (v1.0*v2.0 + v1.1*v2.1) / (v1_len*v2_len)
}

fn jarvis<'a>(points: &'a Vec<Point>) -> Vec<&'a Point>
{
    fn find_next_point<'a>(p0: &Point, p1: &Point, points: &'a Vec<Point>) -> &'a Point {
        let mut max_angel = 1.0;
        let mut next_p = &points[0];
        for p in points.iter() {
            let cos = angel_cos(&p0, p1, p);
            if cos < max_angel {
                max_angel = cos;
                next_p = p;
            }
        }
        next_p
    }


    let mut p1 = &points[0];
    for p in points.iter() {
        if p.y < p1.y {
            p1 = p;
        }
    }

    let p0 = Point::new(-1000, p1.y);
    let mut result = vec![p1];

    let next_p = find_next_point(&p0, result[0], points);
    result.push(next_p);

    let mut i = 1;
    while result[0] != result[i] {
        let next_p = find_next_point(result[i-1], result[i], points);
        result.push(next_p);
        i = i + 1;
    }

    result.pop();
    result
}

fn main()
{
    let points = vec![
        Point::new(15,15), Point::new(4,4), Point::new(3,5),
        Point::new(1,1), Point::new(8,2), Point::new(10,1),
        Point::new(1,10), Point::new(3,6), Point::new(16,14),
    ];

    let res = jarvis(&points);
    println!("{:?}", res);
}
