use std::io;
use rand::Rng;

fn main() {
	println!("Guessing game!\n");
	let secret_number = rand::thread_rng().gen_range(1..=100);
	loop{
        println!("Enter a number to guess: ");
        let mut guess = String::new();
		io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read the line");
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        if guess < secret_number{
            println!("Too small");
        }
        else if guess > secret_number{
            println!("Too big");
        }
        else{
            println!("Matched!");
            break;
        }
	}
	
}
