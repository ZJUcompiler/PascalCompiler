program arith;
var a:integer;
	b:integer;
    c:boolean;
    d:real;
    e:real;

begin
    a := 1;
    b := 2;
    c := a < b;
    writeln(c);
    c := a > b;
    writeln(c);
    c := a = b;
    writeln(c);
    c := a <= b;
    writeln(c);

    d := 3.5;
    writeln(d);
end.
