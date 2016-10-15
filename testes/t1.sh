#gcloud compute instances start cpu1 cpu2 cpu4 --zone us-central1-b & 
#gcloud compute instances start cpu8 --zone us-east1-b
wait
echo "> CPU ligadas!"

COUNTER=$(gcloud --format="value(networkInterfaces[0].accessConfigs[0].natIP)" compute instances list)
for i in $COUNTER;
do
	(for p in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15; 
	 do
		for ii in 250 1000 4000; 
		do
			for jj in 5 20 80; 
			do
				(	echo '> ' ./ep2 $ii $jj '(' $i ')' &&
					ssh -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no capellaresumo@$i "cd EP2 && /usr/bin/time -v ./ep2 $ii $jj v > rtmp 2> ttmp" 2>/dev/null &&
					scp -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no capellaresumo@$i:~/EP2/rtmp resultados2/r-d$ii-n$jj-p$p-$i.txt 2>/dev/null >/dev/null &&
					scp -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no capellaresumo@$i:~/EP2/ttmp resultados2/t-d$ii-n$jj-p$p-$i.txt 2>/dev/null >/dev/null 
				)
			done
		done
	done) &
done

wait

