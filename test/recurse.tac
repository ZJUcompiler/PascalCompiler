_$MAIN$_: 
arg i32 3
call fib i32 $t0
asn i32 $t0 i32 r
_$FUNC$fib
arg i8 110
call write
arg i8 61
call write
arg i32 n
call write
arg i8 32
call write
eq i32 n i32 1 i8 $t0
eq i32 n i32 0 i8 $t1
or i8 $t0 i8 $t1 i8 $t0
if_f i8 $t0 _$JMP$_L0
asn i32 1 i32 fib
jmp _$JMP$_L1
_$JMP$_L0
sub i32 n i32 1 i32 $t0
arg i32 $t0
call fib i32 $t0
sub i32 n i32 2 i32 $t0
arg i32 $t0
call fib i32 $t1
add i32 $t0 i32 $t1 i32 $t0
asn i32 $t0 i32 fib
_$JMP$_L1
arg i32 fib
call writeln
ret
.data
