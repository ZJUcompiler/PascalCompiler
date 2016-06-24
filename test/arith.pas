program arith;
var a:integer;
	b:integer;
    c:boolean;
    d:real;
    e:real;

begin
    a := 2;
    b := 3;
    d := 5.3;
    e := 3.5;

    c := a >= b;
    write('2 >= 3: ');
    writeln(c);
    c := a < b;
    write('2 < 3: ');
    writeln(c);
    c := a <> b;
    write('2 <> 3: ');
    writeln(c);
    c := a <= b;
    write('2 <= 3: ');
    writeln(c);

    c := d >= e;
    write('5.3 >= 3.5: ');
    writeln(c);
    c := d < e;
    write('5.3 < 3.5: ');
    writeln(c);
    c := d <> e;
    write('5.3 <> 3.5: ');
    writeln(c);
    c := d <= e;
    write('5.3 <= 3.5: ');
    writeln(c);
end.
