uso = [1911.2, 2158, 3000]; 
desvio = [18.299, 20.373, 500];  
figure
hold on
title('Uso de memória para d = 4000')
xlabel('Nº de ciclistas')
ylabel('Uso de memória (kb)')
bar(uso, 0.5, 'w')
errorbar(uso,desvio, '.')