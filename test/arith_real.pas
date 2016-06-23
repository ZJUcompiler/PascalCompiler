program arith;
var a:integer;
	b:integer;
    c:boolean;
    d:real;
    e:real;
    f:real;

begin
    a := 2;
    b := 5;
    d := 3.5;
    e := 4.3;
    f := 4.3;
    c := f >= e;
    writeln(c);
    c := f < e;
    writeln(c);
    c := f > e;
    writeln(c);
    c := f = e;
    writeln(c);
    c := f <= e;
    writeln(c);

end.
