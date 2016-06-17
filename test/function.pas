program func;
var 
    a: real;
    
    function max(a: real; b: real): real;
    var 
        result: real;
    begin
        if (a > b) then
            result := a
        else
            result := b;
        max := result;
    end; 

begin
    a:=max(1,2);
end.