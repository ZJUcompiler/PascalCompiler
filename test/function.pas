program func;
var 
    a: real;
    
    function max(a: real; b: real): real;
    var 
        result: real;
    begin
        if (num1 > num2) then
            result := num1
        else
            result := num2;
        max := result;
    end; 

begin
    a := max(1,2);
end.