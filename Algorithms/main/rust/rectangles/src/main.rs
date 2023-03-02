struct Rectangle{
	length: f32,
	breadth: f32
}

impl Rectangle{
	fn calcarea(&self)->f32{
		self.length*self.breadth
	}
	fn can_hold(&self,rec2: &Rectangle)->bool{
		if self.length>rec2.length && self.breadth> rec2.breadth{
			return true;
		}
		false
	}
}
fn main() {
  	let rec1 = Rectangle{
  				length : 12.5,
  				breadth : 10.2,
  	    };
  	let rec2 = Rectangle{
  				length : 10.5,
  				breadth : 6.2,
  	    };
  	let rec3 = Rectangle{
  				length : 9.5,
  				breadth : 10.2,
  	    };
  	println!("{}",rec1.calcarea());
  	println!("{}", rec1.can_hold(&rec3));
}

