program syscalls;

var r:integer;
	a:char;
	i:integer;
    tr:boolean;
    float:real;
	
begin
	read(i);
	r := abs(-1);
	a := chr(65);
	write(r);
	write(a);

	tr := odd(123);
	r := sqr(4);
	float := sqrt(9);
end.