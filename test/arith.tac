_$MAIN$_
asn i32 2 i32 a
asn i32 3 i32 b
asn f32 1084856730 f32 d
asn f32 1080033280 f32 e
lt i32 a i32 b i8 $t0
eq i8 $t0 i8 0 i8 $t0
asn i8 $t0 i8 c
asn i32 _$CONST$_L0 str $t0
arg str $t0
call write
arg i8 c
call writeln
lt i32 a i32 b i8 $t0
asn i8 $t0 i8 c
asn i32 _$CONST$_L1 str $t0
arg str $t0
call write
arg i8 c
call writeln
eq i32 a i32 b i8 $t0
xor i8 $t0 i8 1 i8 $t0
asn i8 $t0 i8 c
asn i32 _$CONST$_L2 str $t0
arg str $t0
call write
arg i8 c
call writeln
lt i32 b i32 a i8 $t0
eq i8 $t0 i8 0 i8 $t0
asn i8 $t0 i8 c
asn i32 _$CONST$_L3 str $t0
arg str $t0
call write
arg i8 c
call writeln
lt f32 d f32 e i8 $t0
eq i8 $t0 i8 0 i8 $t0
asn i8 $t0 i8 c
asn i32 _$CONST$_L4 str $t0
arg str $t0
call write
arg i8 c
call writeln
lt f32 d f32 e i8 $t0
asn i8 $t0 i8 c
asn i32 _$CONST$_L5 str $t0
arg str $t0
call write
arg i8 c
call writeln
eq f32 d f32 e i8 $t0
xor i8 $t0 i8 1 i8 $t0
asn i8 $t0 i8 c
asn i32 _$CONST$_L6 str $t0
arg str $t0
call write
arg i8 c
call writeln
lt f32 e f32 d i8 $t0
eq i8 $t0 i8 0 i8 $t0
asn i8 $t0 i8 c
asn i32 _$CONST$_L7 str $t0
arg str $t0
call write
arg i8 c
call writeln
.data
_$CONST$_L0
.string "\0102 >= 3: \000"
_$CONST$_L1
.string "\0092 < 3: \000"
_$CONST$_L2
.string "\0102 <> 3: \000"
_$CONST$_L3
.string "\0102 <= 3: \000"
_$CONST$_L4
.string "\0145.3 >= 3.5: \000"
_$CONST$_L5
.string "\0135.3 < 3.5: \000"
_$CONST$_L6
.string "\0145.3 <> 3.5: \000"
_$CONST$_L7
.string "\0145.3 <= 3.5: \000"
