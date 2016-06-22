program syscalls;

var r:integer;
	a:char;
	i:integer;
	
begin
	read(i);
	r := abs(-1);
	a := chr(65);
	write(r);
	write(a);
	r := odd(1);
	r := sqr(4);
	r := sqrt(9);
end.