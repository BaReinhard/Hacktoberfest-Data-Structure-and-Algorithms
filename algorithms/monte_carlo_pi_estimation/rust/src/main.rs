extern crate rand;
use rand::StdRng;
use rand::Rng;

fn main() {
    let iterations: usize = 100_000_000;
    let mut inside: usize = 0;

    let mut rng = StdRng::new().unwrap();
    for _ in 0..iterations {
        let (x, y) = (rng.next_f64(), rng.next_f64());
        if x*x + y*y <= 1. {
            inside += 1;
        }
    }
    let prediction = (4 as f64) * (inside as f64) / (iterations as f64);
    println!("I did approximate pi as {}, using {} iterations, am I right?", prediction, iterations );
    let error_magnitude = (prediction - std::f64::consts::PI).abs();
    println!("I was wrong by only {}!", error_magnitude);
}
