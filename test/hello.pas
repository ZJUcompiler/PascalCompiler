program test;
var bb:boolean;
		bbbb,a,A:integer;
		c: integer;
		{c,d:boolean;
		a:char;
		a : array[1..25] of integer;}
function func(a:char):integer;
	function ff(a:integer):integer;
	begin
		a := 2;
	end;
begin
	a := 'a';
end;
begin
    A:=0;
    a:=10;
	repeat
		A:=A+1;
	until A>2;
    writeln(A);
	case (A)of
		1:a:=a+5;
		2:a:=a+10;
		3:a:=a+3;
	end;
    writeln(a);
	{bbbb := 3;
	repeat
		a:=a+1;
	until a = 0;
	a := 'b';
	c := true;
	d := 1>2;
	a[2] := 3;
	while number>0 do
	begin
   sum := sum + number;
   number := number - 2;
	end;
	for bbbb := 1 to 10 do begin
		a := a+1;
		if bbbb>0 then}
			{bbbb := func(bb);}
		{else
			a:=a+1;
	end;}
	bb := true and true;
end.




