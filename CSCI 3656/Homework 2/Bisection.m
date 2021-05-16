function root = Bisection(f, a, b, fin)
disp('Bisection Method'); 

%Set interval 
low = feval(f, a); 
high = feval(f, b); 
c = 0; 

%Error if bisection method fails 
if low * high > 0
    %Bisection method fails 
    disp('Bisection Method Fails')
    return 
end

while(abs(b - a) >= fin)
    c = c + 1; 
    %midpoint
    root = (a+b)/2; 
    i = feval(f, root);
    
    if i == 0
        fprintf('Root at x = %f \n\n', root); 
        return 
    end 
end 
    fprintf('%2c \t %f \t %f \t %f \n', c - 1, a, b, root); 
