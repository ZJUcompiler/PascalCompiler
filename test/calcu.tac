_$MAIN$_
asn i32 5 i32 a
asn i32 3 i32 b
add i32 a i32 b i32 $t0
asn i32 $t0 i32 c
arg i32 c
call writeln
sub i32 a i32 b i32 $t0
asn i32 $t0 i32 c
arg i32 c
call writeln
mul i32 a i32 b i32 $t0
asn i32 $t0 i32 c
arg i32 c
call writeln
div i32 a i32 b i32 $t0
asn i32 $t0 i32 c
arg i32 c
call writeln
mod i32 a i32 b i32 $t0
asn i32 $t0 i32 c
arg i32 c
call writeln
mul i32 a i32 b i32 $t0
push i32 $t0
push i32 $t0
mul i32 b i32 a i32 $t0
add i32 $t0 i32 a i32 $t1
pop i32 $t0
mul i32 b i32 $t1 i32 $t1
pop i32 $t0
add i32 $t0 i32 $t1 i32 $t0
asn i32 $t0 i32 c
arg i32 c
call writeln
.data
