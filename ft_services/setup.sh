#!/bin/bash

echo -ne "\033[1;32m\033[0;33m....................................................
:  ___ ___     __   ___  __ .    . .  ___  ___  __ :
: |_    |     |__  |__  | _| \  /  | |    |__  |__ :
: |     |  __  __| |___ | \   \/   | |___ |___  __|:
:..................................................:\n"

#echo ' Init docker ...'
#./init_docker.sh
#echo -ne "\033[1;32m\033[0;33m Waiting for docker ...\n"
#echo '30 seconds left ...'
#sleep 10
#echo '20 seconds left ...'
#sleep 10
#echo '10 seconds left ...'
#sleep 10
#echo 'Docker is started'

eval $(minikube docker-env)

echo 'Start minikube (can take some minutes) ...'
minikube start --vm-driver=virtualbox
minikube addons enable dashboard
minikube addons enable metrics-server

echo ' Build images ...'
docker build -t nginx-image srcs/containers/nginx

#docker save nginx-image > nginx-image.tar
#docker load < nginx-image.tar
#rm nginx-image.tar

#echo ' Apply yaml ...'
#kubectl apply -f srcs/yaml/nginx.yaml
