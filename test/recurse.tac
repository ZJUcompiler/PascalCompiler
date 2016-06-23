_$MAIN$_: 
arg i32 0
call fib i32 $t0
asn i32 $t0 i32 r
arg i32 r
call writeln
arg i32 1
call fib i32 $t0
asn i32 $t0 i32 r
arg i32 r
call writeln
arg i32 2
call fib i32 $t0
asn i32 $t0 i32 r
arg i32 r
call writeln
arg i32 3
call fib i32 $t0
asn i32 $t0 i32 r
arg i32 r
call writeln
arg i32 4
call fib i32 $t0
asn i32 $t0 i32 r
arg i32 r
call writeln
arg i32 5
call fib i32 $t0
asn i32 $t0 i32 r
arg i32 r
call writeln
arg i32 6
call fib i32 $t0
asn i32 $t0 i32 r
arg i32 r
call writeln
arg i32 7
call fib i32 $t0
asn i32 $t0 i32 r
arg i32 r
call writeln
arg i32 8
call fib i32 $t0
asn i32 $t0 i32 r
arg i32 r
call writeln
_$FUNC$fib
eq i32 n i32 1 i8 $t0
push i32 $t0
eq i32 n i32 0 i8 $t1
pop i32 $t0
or i8 $t0 i8 $t1 i8 $t0
if_f i8 $t0 _$JMP$_L0
asn i32 1 i32 fib
jmp _$JMP$_L1
_$JMP$_L0
sub i32 n i32 1 i32 $t0
arg i32 $t0
call fib i32 $t0
push i32 $t0
sub i32 n i32 2 i32 $t0
arg i32 $t0
call fib i32 $t1
pop i32 $t0
add i32 $t0 i32 $t1 i32 $t0
asn i32 $t0 i32 fib
_$JMP$_L1
ret
.data
