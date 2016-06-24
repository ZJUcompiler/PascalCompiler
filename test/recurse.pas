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
    r := fib(0);
    writeln(r);
    r := fib(1);
    writeln(r);
    r := fib(2);
    writeln(r);
    r := fib(3);
    writeln(r);
    r := fib(4);
    writeln(r);
    r := fib(5);
    writeln(r);
    r := fib(6);
    writeln(r);
    r := fib(7);
    writeln(r);
    r := fib(8);
    writeln(r);
end.
