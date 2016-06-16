program test;
const
	PI = 3.1415;
	kk = 4;
type 
	name=string;
	mm = integer;
	cc = char;	
var bb, bbb, b : char ;
	c : integer;
	A : integer;
	d : real;
	e : boolean;
	f : name;
function funcname(a,b:integer; c,d:char):integer;
var 
	funca:integer;
	funcb:char;
type
	funcnam = string;
	funcmm = integer;
begin
	funca := 2;
end;
begin  writeln('hello');
	A := 3 + 4 * 4 - 2 + 10;
	c := 4;
	d := A + d;
	e := true;
	writeln(e); 
	writeln(A);
	if (c = 0) then 
	begin
		c := 1;
	end;
	writeln(c);
	
	while c>0 do
	begin
		c:=c-1;
		A:=c+1;
	end;

	for c:=1 to 10 do
	begin
		A:=A+1;
		A:=A+1;
	end;

	repeat
		A:=A+1;
	until A>10;
end.




