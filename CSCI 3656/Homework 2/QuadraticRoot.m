%Using the quadratic formula, compute the roots 
%of f(x) = 4x^2 - 3x - 3. Show your work. 
clear, clc 
for k = 1:3
    disp('Quadratic Equation: ax^2 + bx + c')
    a = input('Enter a: '); 
    b = input('Enter b: '); 
    c = input('Enter c: '); 
    d = b^2 - 4*a*c; 
    
    if d < 0
        fprintf('\n The equation has no real roots.\n\n')
    elseif d == 0
        root = -b / (2*a); 
        fprintf('\n The equation has one root. \n')
        fprintf(' %.3f\n\n', root)
    else 
        r1 = (-b + sqrt(d)) / (2*a); 
        r2 = (-b - sqrt(d)) / (2*a); 
        fprintf('\n The equation has two roots. \n') 
        fprintf(' %.3f and %.3f \n\n', r1, r2)
    end
 end