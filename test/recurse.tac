_$MAIN$_: 
arg i32 5
call fib
_$FUNC$fib
eq i32 n i32 1 i8 $t0
eq i32 n i32 0 i8 $t1
or i8 $t0 i8 $t1 i8 $t0
if_f i8 $t0 _$JMP$_L0
asn i32 1 i32 fib
jmp _$JMP$_L1
_$JMP$_L0
sub i32 n i32 1 i32 $t0
arg i32 $t0
call fib
sub i32 n i32 2 i32 $t0
arg i32 $t0
call fib
add i32 $t0 i32 $t1 i32 $t0
asn i32 $t0 i32 fib
_$JMP$_L1
ret
.data
