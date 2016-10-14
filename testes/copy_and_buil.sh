#gcloud compute instances start cpu1 cpu2 cpu4 --zone us-central1-b & 
#gcloud compute instances start cpu8 --zone us-east1-b
wait
echo "> CPU ligadas!"

COUNTER=$(gcloud --format="value(networkInterfaces[0].accessConfigs[0].natIP)" compute instances list)
for i in $COUNTER;
do
	(ssh -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no capellaresumo@$i "mkdir EP2" &
    scp -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no -r ./* capellaresumo@$i:~/EP2/ &
	ssh -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no capellaresumo@$i "cd EP2 && make") &
done
