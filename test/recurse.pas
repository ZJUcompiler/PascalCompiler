program fib;

var r:integer;
	
	function fib(n:integer):integer;
	begin
		fib:=fib(n-1);
	end;

begin
	fib(5);
end.
