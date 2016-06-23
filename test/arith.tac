_$MAIN$_: 
asn i32 2 i32 a
asn i32 2 i32 b
lt i32 a i32 b i8 $t0
eq i8 $t0 i8 0 i8 $t0
asn i8 $t0 i8 c
arg i8 c
call writeln
lt i32 a i32 b i8 $t0
asn i8 $t0 i8 c
arg i8 c
call writeln
eq i32 a i32 b i8 $t0
xor i8 $t0 i8 1 i8 $t0
asn i8 $t0 i8 c
arg i8 c
call writeln
lt i32 b i32 a i8 $t0
eq i8 $t0 i8 0 i8 $t0
asn i8 $t0 i8 c
arg i8 c
call writeln
asn f32 1080033280 f32 d
arg f32 d
call writeln
.data
