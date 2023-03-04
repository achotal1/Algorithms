fn convtemp(f:f32) -> f32{
	//println!("{}", (f - 32)* (5/9));
	let c = (f-32.0) * (5.0/9.0);
	return c;
	
}

fn fibo(num: i32) -> i32{
	if(num == 0){
		1
	}
	else if(num == 1){
		1
	}
	else{
		fibo(num - 1) + fibo(num - 2)
	}
}
#[derive(Debug)]
enum States{
	Alaska,
	Alabama,
	// --snip
}
enum Coin{
	Penny,
	Nickel,
	Dime,
	Quarter(States),
}

fn add_value(coin:Coin) -> i32{
	match coin{
		Coin::Penny => 1,
		Coin::Nickel => 5,
		Coin::Dime => 10,
		Coin::Quarter(state) => {
			println!("Coin is of state {:?}", state);
			25
		}
	}
}

fn main() {
    let x = 5;

    let x = x + 1;

    {
        let x = x * 2;
        println!("The value of x in the inner scope is: {x}");
    }

    println!("The value of x is: {x}");

    let _tup = (500, 6.4, 1);

    //let (x, y, z) = tup;

    //println!("The value of y is: {y}");

    // convert fahrenheit to celsius 
    let temp = 54.0;
    println!("The temp conversion from {temp} F to C is : {}", convtemp(temp));

    // fibonacci

    //println!("{}",fibo(6));
    // trying enums out
    let coin_try = Coin::Quarter(States::Alabama);
    add_value(coin_try);
}
