#!/bin/bash
echo "Teste 1 d = 250 e n = 5"
for i in {0..9} 
do
	./pegaresultados < t-d250-n5-0$i.txt >> teste1.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d250-n5-$i.txt >> teste1.txt
done
./transforma 30 < teste1.txt > s1teste.txt

echo "Teste 2 d = 250 e n = 20"
for i in {0..9} 
do
	./pegaresultados < t-d250-n20-0$i.txt >> teste2.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d250-n20-$i.txt >> teste2.txt
done
./transforma 30 < teste2.txt > s2teste.txt

echo "Teste 3 d = 250 e n = 80"
for i in {0..9} 
do
	./pegaresultados < t-d250-n80-0$i.txt >> teste3.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d250-n80-$i.txt >> teste3.txt
done
./transforma 30 < teste3.txt > s3teste.txt

echo "Teste 4 d = 1000 e n = 5"
for i in {0..9} 
do
	./pegaresultados < t-d1000-n5-0$i.txt >> teste4.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d1000-n5-$i.txt >> teste4.txt
done
./transforma 30 < teste4.txt > s4teste.txt

echo "Teste 5 d = 1000 e n = 20"
for i in {0..9} 
do
	./pegaresultados < t-d1000-n20-0$i.txt >> teste5.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d1000-n20-$i.txt >> teste5.txt
done
./transforma 30 < teste5.txt > s5teste.txt

echo "Teste 6 d = 1000 e n = 80"
for i in {0..9} 
do
	./pegaresultados < t-d1000-n80-0$i.txt >> teste6.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d1000-n80-$i.txt >> teste6.txt
done
./transforma 30 < teste6.txt > s6teste.txt

echo "Teste 7 d = 4000 e n = 5"
for i in {0..9} 
do
	./pegaresultados < t-d4000-n5-0$i.txt >> teste7.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d4000-n5-$i.txt >> teste7.txt
done
./transforma 30 < teste7.txt > s7teste.txt

echo "Teste 8 d = 4000 e n = 20"
for i in {0..9} 
do
	./pegaresultados < t-d4000-n20-0$i.txt >> teste8.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d4000-n20-$i.txt >> teste8.txt
done
./transforma 30 < teste8.txt > s8teste.txt

echo "Teste 9 d = 4000 e n = 80"
for i in {0..9} 
do
	./pegaresultados < t-d4000-n80-0$i.txt >> teste9.txt
done
for i in {10..29} 
do
    ./pegaresultados < t-d4000-n80-$i.txt >> teste9.txt
done
./transforma 30 < teste9.txt > s9teste.txt