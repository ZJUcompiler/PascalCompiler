program forloop;
var i:integer;
	r:integer;

begin
    { r:=3; }
    write('please input r: ');
    read(r);
	for i:= 1 to 10 do r:=r+1;
    writeln(r);
end.
