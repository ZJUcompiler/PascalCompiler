_$MAIN$_: 
arg i32 &r
call read
asn i32 1 i32 i
_$JMP$_L0
lt i32 10 i32 i i8 $t0
eq i8 $t0 i8 0 i8 $t0
if_f i8 $t0 _$JMP$_L1
add i32 r i32 1 i32 $t0
asn i32 $t0 i32 r
add i32 i i32 1 i32 i
jmp _$JMP$_L0
_$JMP$_L1
arg i32 r
call writeln
.data
