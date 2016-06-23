_$MAIN$_: 
asn i32 0 i32 r
_$JMP$_L0
lt i32 i i32 10 i8 $t0
if_f i8 $t0 _$JMP$_L1
add i32 r i32 2 i32 $t0
asn i32 $t0 i32 r
add i32 i i32 1 i32 $t0
asn i32 $t0 i32 i
jmp _$JMP$_L0
_$JMP$_L1
.data
