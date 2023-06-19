use clap::{Arg, App};

const VERSION: Option<&'static str> = option_env!("CARGO_PKG_VERSION");

fn main() {
	let matches = App::new("thing")
		.version(VERSION.unwrap_or("unknown version"))
		.arg(...)
		...
		.get_matches();
	}
}
