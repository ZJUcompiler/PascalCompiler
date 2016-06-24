_$MAIN$_
asn i32 5 i32 a
asn i32 3 i32 b
add i32 a i32 b i32 $t0
asn i32 $t0 i32 c
asn i32 _$CONST$_L0 str $t0
arg str $t0
call write
arg i32 c
call writeln
sub i32 a i32 b i32 $t0
asn i32 $t0 i32 c
asn i32 _$CONST$_L1 str $t0
arg str $t0
call write
arg i32 c
call writeln
mul i32 a i32 b i32 $t0
asn i32 $t0 i32 c
asn i32 _$CONST$_L2 str $t0
arg str $t0
call write
arg i32 c
call writeln
div i32 a i32 b i32 $t0
asn i32 $t0 i32 c
asn i32 _$CONST$_L3 str $t0
arg str $t0
call write
arg i32 c
call writeln
mod i32 a i32 b i32 $t0
asn i32 $t0 i32 c
asn i32 _$CONST$_L4 str $t0
arg str $t0
call write
arg i32 c
call writeln
.data
_$CONST$_L0
.string "\0105 + 3 = \000"
_$CONST$_L1
.string "\0105 - 3 = \000"
_$CONST$_L2
.string "\0105 * 3 = \000"
_$CONST$_L3
.string "\0125 div 3 = \000"
_$CONST$_L4
.string "\0125 mod 3 = \000"
