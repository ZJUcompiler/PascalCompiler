_$MAIN$_: 
mul i32 6 i32 5 i32 $t1
add i32 3 i32 $t1 i32 $t0
sub i32 $t0 i32 1 i32 $t0
asn i32 $t0 i32 a
fadd f32 1065353216 i32 a f32 $t0
asn f32 $t0 f32 f
asn f32 1110423634 f32 g
lt f32 f f32 g i8 $t0
asn i8 $t0 i8 b
