fn main() {
    let x = 1;
    let y = 1;
    let z = add(x, y);
    println!("{}", z);

    let num = 7;
    if num < 5 {
        println!("<5");
    } else {
        println!(">=5");
    }

    let mut cnt = 0;
    loop {
        cnt += 1;
        if cnt == 10 {
            break;
        }
    }
    println!("{}", cnt);

    let mut n = 3;
    while n != 0 {
        println!("{}!", n);
        n -= 1;
    }
}

fn add(a: i32, b: i32) -> i32 {
    a + b
}
