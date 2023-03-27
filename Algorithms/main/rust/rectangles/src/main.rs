
use std::io;

#[allow(dead_code)]
struct Rectangle{
	width: f32,
	height: f32
}

impl Rectangle{
    fn square(w: f32) -> Rectangle{
		Rectangle { width: w, height: w }
	}
	fn rectangle(w: f32, h: f32)-> Rectangle{
		Rectangle { width: w, height: h }
	}
	fn calc_area(&self) -> f32{
		self.width*self.height
	}

	fn fits(&self, r2: &Rectangle) -> bool{
		self.width >= r2.width && self.height >= r2.height	
	}
}

fn main(){
	println!("Enter how many rectangles you want to make: ");
	let mut s = String::new();
	io::stdin()
		.read_line(&mut s).expect("Expected an integer!");
	let s1 = s.trim().parse::<u32>().expect("yes");
	let mut rectangles: Vec<Rectangle> = Vec::new();
	// println!("{}", s1);

	for _ in 0..s1{
		rectangles.push(Rectangle::rectangle(5f32, 8f32));
	}

	println!("{}",rectangles[2].calc_area());

	println!("{}",rectangles[2].fits(&rectangles[4]));


}
