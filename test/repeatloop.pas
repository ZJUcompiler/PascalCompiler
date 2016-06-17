program repeatloop;
var i:integer;
	r:integer;

begin
	i := 0;
	r := 2;
	repeat
		i := i+1;
		r := r*r;
	until i > 10;
end.