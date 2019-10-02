with Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;
use Ada.Text_IO, Ada.Integer_Text_IO, Ada.Float_Text_IO;

procedure Solution is

function solveMeFirst (a, b: Integer) return Integer is
begin
   return a+b;
   
end solveMeFirst;

a, b, sum: Integer;
begin
    Get (a); 
    Get (b);
    sum := solveMeFirst(a, b);  
    Put (sum, Width => 1);

end Solution;