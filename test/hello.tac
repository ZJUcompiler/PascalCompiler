_$MAIN$_: 
asn i32 0 i32 A
asn i32 0 i32 a
_$JMP$_L0
add i32 A i32 1 i32 $t0
asn i32 $t0 i32 A
lt i32 2 i32 A i8 $t0
if_f i8 $t0 _$JMP$_L0
arg i32 A
call writeln
eq i32 A i32 1 i8 $t0
if_f i8 $t0 _$JMP$_L2
eq i32 A i32 2 i8 $t0
if_f i8 $t0 _$JMP$_L3
eq i32 A i32 3 i8 $t0
if_f i8 $t0 _$JMP$_L4
_$JMP$_L2
add i32 a i32 5 i32 $t0
asn i32 $t0 i32 a
jmp _$JMP$_L1
_$JMP$_L3
add i32 a i32 2 i32 $t0
asn i32 $t0 i32 a
jmp _$JMP$_L1
_$JMP$_L4
add i32 a i32 3 i32 $t0
asn i32 $t0 i32 a
jmp _$JMP$_L1
_$JMP$_L1
arg i32 a
call writeln
and i8 1 i8 1 i8 $t0
asn i8 $t0 i8 bb
_$FUNC$func$ff
asn i32 2 i32 a
ret
_$FUNC$func
asn i8 97 i8 a
ret
.data
