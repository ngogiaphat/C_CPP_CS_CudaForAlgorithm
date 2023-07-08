program RecursiveExample;
function Factorial(n: Integer): Integer;
begin
  if n = 0 then
    Factorial := 1
  else
    Factorial := n * Factorial(n - 1);
end;
begin
  writeln('Factorial of 5: ', Factorial(5));
end.