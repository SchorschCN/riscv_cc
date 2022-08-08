#########################################################################
# File Name: test.sh
# Author: Schorsch
# mail: sh19931026@163.com
# Created Time: Fr 29 Jul 2022 14:51:36 CEST
# Description: 
#########################################################################
#!/bin/zsh

assert() {
	expected="$2"
	input="$1"

	./rvcc $input > tmp.s || exit

	riscv64-unknown-linux-gnu-gcc -static -o tmp tmp.s

	qemu-riscv64 -L /usr/riscv64-linux-gnu ./tmp

	actual="$?"
	
	if [ "$actual" = "$expected" ]; then
		echo "$input -> $actual"
	else
		echo "$input -> $expected expected, but got $actual"
		exit 1
	fi
}

assert 1-2+3 2
assert 2+1-5 -2

echo OK

