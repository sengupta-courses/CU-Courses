x = a; 
y = a; 
for i = 1:maxIter 
    x = 2+log(x); 
    err = abs(x-y); 
    y = x; 
    if(err < tolX)
        break; 
    end
end
