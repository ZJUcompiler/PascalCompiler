program expr;
var a:integer;
	f:real;
    g:real;
    b:boolean;
function max: integer;
   var a: integer;
    b: real;
    begin
        a:= 2;
        b:= a * 3.5;
    end;
begin
	a := 3 + 6 * 5 - 1;
    f := 1.0 + a;
    g := 43.93;
    b := g > f;
end.
