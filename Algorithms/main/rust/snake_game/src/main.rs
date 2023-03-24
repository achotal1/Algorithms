extern crate glutin_window;
extern crate graphics;
extern crate opengl_graphics;
extern crate piston;

use glutin_window::GlutinWindow as Window;
use opengl_graphics::{GlGraphics, OpenGL};
use piston::event_loop::{EventSettings, Events};
use piston::input::*;
use piston::window::WindowSettings;
use crate::piston::EventLoop;
use crate::piston::ButtonEvent;
use piston::Button;
use piston::ButtonState;
use piston::Button::Keyboard;
use piston::keyboard::Key;
use std::collections::LinkedList;
use std::iter::FromIterator;

#[derive(Clone, PartialEq)]
enum Direction{
	Left,Right,Up,Down
}

struct Game{
	gl: GlGraphics,
	snake: Snake,
}

struct Snake{
	body: LinkedList<(i32,i32)>,
	dir: Direction
}


impl Snake{
	fn render(&self, gl: &mut GlGraphics, arg: &RenderArgs){
		use graphics;
		let RED: [f32; 4] = [1.0, 0.0, 0.0, 1.0];

		let squares: Vec<graphics::types::Rectangle> = self.body
			.iter()
			.map(|&(x,y)|{
				graphics::rectangle::square(
				(x*20) as f64, 
				(y*20) as f64,
				20_f64)
			})
			.collect();
	
		gl.draw(arg.viewport(), |c, gl|{
            let transform = c.transform;
            squares.into_iter()
            	.for_each(|square|graphics::rectangle(RED, square, transform, gl));
        });
	}

	fn update(&mut self){
		let mut new_head = (*self.body.front().expect("No body found")).clone();
		match self.dir{
			Direction::Left => new_head.0 -= 1,
			Direction::Right => new_head.0 += 1,
			Direction::Up => new_head.1 -= 1,
			Direction::Down => new_head.1 += 1,
		}
		self.body.push_front(new_head);
		self.body.pop_back().unwrap();
	}
}

impl Game{
	fn render(&mut self, arg: &RenderArgs){
		use graphics::*;
		let COLOR: [f32; 4] = [0.3 ,0.4 ,0.4 ,1.0];
		self.gl.draw(arg.viewport(), |_c, gl|{
            // Clear the screen.
            clear(COLOR, gl);
        });
        self.snake.render(&mut self.gl, arg);
	}

	fn update(&mut self){
		self.snake.update();
	}

	fn pressed(&mut self, button: &Button){
		let last_direction = self.snake.dir.clone();
		self.snake.dir = match button{
			&Button::Keyboard(Key::W) 
				if last_direction != Direction::Down => Direction::Up,
			&Button::Keyboard(Key::A) 
				if last_direction != Direction::Right => Direction::Left,
			&Button::Keyboard(Key::S) 
				if last_direction != Direction::Up => Direction::Down,
			&Button::Keyboard(Key::D) 
				if last_direction != Direction::Left => Direction::Right,
			_ => last_direction,
		};
	}
}

fn main() {
     let opengl = OpenGL::V3_2;

    // Create a Glutin window.
    let mut window: Window = WindowSettings::new("Snake-Game", [200, 200])
    	.graphics_api(opengl)
    	.exit_on_esc(true)
    	.build()
    	.unwrap();

    let mut game = Game{
    	gl: GlGraphics::new(opengl),
    	snake: Snake{ 
    		body: LinkedList::from_iter((vec![(0,0), (0,1)]).into_iter()), 
    		dir: Direction::Right
    	},
    };

    let mut events = Events::new(EventSettings::new().ups(8));
    while let Some(e) = events.next(&mut window) {
        if let Some(r) = e.render_args() {
            game.render(&r);
        }
        if let Some(u) = e.update_args() {
        	game.update();
        }

        if let Some(b) = e.button_args() {
        	if b.state == ButtonState::Press {
        		game.pressed(&b.button);
        	}
        }
    }
}
