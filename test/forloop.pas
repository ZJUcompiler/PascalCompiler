program forloop;
var i:integer;
	r:integer;
    d:string;

begin
    { r:=3; }
    d:='Hello, world!';
    writeln(d);
    { read(d); }
    writeln(d);
    write('please input r: ');
    read(r);
	for i:= 1 to 10 do r:=r+1;
    writeln(r);
end.
