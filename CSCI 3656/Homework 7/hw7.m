clear 
clc 
close all 

x = -5:5; 

v = 1:10; 

p = 1; 
LegendText = cell(1, numel(v)); 

figure; 
hold on 

for k = v
    
    CurrColor = rand(1, 3); 
    y = (1)./(1 + exp((-k).*x));
    
    plot(x, y, 'Color', CurrColor); 
    
    LegendText{p} = sprintf('V = %d', k); 
    p = p+1; 
end
legend(LegendText, 'Location', 'best')

xVector = linspace(-5, 5, 7); 
for res = xVector
    n = 1; 
    yVector = (1)./(1 + exp((-n).*res));
    table1 = table(res, yVector); 
end

disp(table1)
