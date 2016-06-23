program fib;

var r:integer;
	function fib(n:integer):integer;
	begin
        write('n');
        write('=');
        write(n);
        write(' ');
		if (n=1) or (n=0) then
			fib:=1
		else
			fib:=fib(n-1)+fib(n-2);
        writeln(fib);
	end;

begin
    r := fib(3);
end.
