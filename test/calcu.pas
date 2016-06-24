program calcu;
var a:integer;
	b:integer;
    c:integer;

begin
    a := 5;
    b := 3;
    c := a + b;
    write('5 + 3 = ');
    writeln(c);
    c := a - b;
    write('5 - 3 = ');
    writeln(c);
    c := a * b;
    write('5 * 3 = ');
    writeln(c);
    c := a div b;
    write('5 div 3 = ');
    writeln(c);
    c := a mod b;
    write('5 mod 3 = ');
    writeln(c);
end.
