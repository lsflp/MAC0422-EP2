#gcloud compute instances start cpu1 cpu2 cpu4 --zone us-central1-b & 
#gcloud compute instances start cpu8 --zone us-east1-b
wait

CPU1=$(gcloud --format="value(networkInterfaces[0].accessConfigs[0].natIP)" compute instances list i1)
CPU2=$(gcloud --format="value(networkInterfaces[0].accessConfigs[0].natIP)" compute instances list i2)
CPU3=$(gcloud --format="value(networkInterfaces[0].accessConfigs[0].natIP)" compute instances list i3)
CPU4=$(gcloud --format="value(networkInterfaces[0].accessConfigs[0].natIP)" compute instances list i4)
CPU5=$(gcloud --format="value(networkInterfaces[0].accessConfigs[0].natIP)" compute instances list i5)
wait
echo "> Endereços obtidos!!"

scp -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no capellaresumo@$CPU1:~/EP2/resultados/* ./resultados  
scp -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no capellaresumo@$CPU2:~/EP2/resultados/* ./resultados  
scp -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no capellaresumo@$CPU3:~/EP2/resultados/* ./resultados  
scp -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no capellaresumo@$CPU4:~/EP2/resultados/* ./resultados  
scp -o UserKnownHostsFile=/dev/null -o StrictHostKeyChecking=no capellaresumo@$CPU5:~/EP2/resultados/* ./resultados  

wait
echo "> Finalizando"