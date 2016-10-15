#!/bin/bash
echo "Teste 1 d = 250 e n = 5"
for i in {0..9} 
do
	./pegaresultados < t-d250-n5-0$i.txt >> ueste1.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d250-n5-$i.txt >> ueste1.txt
done
./transforma 30 < ueste1.txt > u1teste.txt

echo "Teste 2 d = 250 e n = 20"
for i in {0..9} 
do
	./pegaresultados < t-d250-n20-0$i.txt >> ueste2.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d250-n20-$i.txt >> ueste2.txt
done
./transforma 30 < ueste2.txt > u2teste.txt

echo "Teste 3 d = 250 e n = 80"
for i in {0..9} 
do
	./pegaresultados < t-d250-n80-0$i.txt >> ueste3.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d250-n80-$i.txt >> ueste3.txt
done
./transforma 30 < ueste3.txt > u3teste.txt

echo "Teste 4 d = 1000 e n = 5"
for i in {0..9} 
do
	./pegaresultados < t-d1000-n5-0$i.txt >> ueste4.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d1000-n5-$i.txt >> ueste4.txt
done
./transforma 30 < ueste4.txt > u4teste.txt

echo "Teste 5 d = 1000 e n = 20"
for i in {0..9} 
do
	./pegaresultados < t-d1000-n20-0$i.txt >> ueste5.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d1000-n20-$i.txt >> ueste5.txt
done
./transforma 30 < ueste5.txt > u5teste.txt

echo "Teste 6 d = 1000 e n = 80"
for i in {0..9} 
do
	./pegaresultados < t-d1000-n80-0$i.txt >> ueste6.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d1000-n80-$i.txt >> ueste6.txt
done
./transforma 30 < ueste6.txt > u6teste.txt

echo "Teste 7 d = 4000 e n = 5"
for i in {0..9} 
do
	./pegaresultados < t-d4000-n5-0$i.txt >> ueste7.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d4000-n5-$i.txt >> ueste7.txt
done
./transforma 30 < ueste7.txt > u7teste.txt

echo "Teste 8 d = 4000 e n = 20"
for i in {0..9} 
do
	./pegaresultados < t-d4000-n20-0$i.txt >> ueste8.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d4000-n20-$i.txt >> ueste8.txt
done
./transforma 30 < ueste8.txt > u8teste.txt

echo "Teste 9 d = 4000 e n = 80"
for i in {0..9} 
do
	./pegaresultados < t-d4000-n80-0$i.txt >> ueste9.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d4000-n80-$i.txt >> ueste9.txt
done
./transforma 30 < ueste9.txt > u9teste.txt