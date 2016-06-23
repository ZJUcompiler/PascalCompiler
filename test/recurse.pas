program fib;

var r:integer;
	function fib(n:integer):integer;
	begin
		if (n=1) or (n=0) then
			fib:=1
		else
			fib:=fib(n-1)+fib(n-2);
	end;

begin
	fib(5);
end.
