program arith;
var a:integer;
	b:integer;
    c:integer;

begin
    a := 5;
    b := 2;
    c := a + b;
    writeln(c);
    c := a - b;
    writeln(c);
    c := a * b;
    writeln(c);
    c := a div b;
    writeln(c);
    c := a mod b;
    writeln(c);
    c := a + b + b;
    writeln(c);
end.
