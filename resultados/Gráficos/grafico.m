uso = [3.817667, 18.924, 81.49567]; 
desvio = [0.381718, 1.881, 7.26671];  
figure
hold on
title('Tempo de execução para d = 4000')
xlabel('Nº de ciclistas')
ylabel('Tempo (s)')
bar(uso, 0.5, 'w')
errorbar(uso,desvio, '.')