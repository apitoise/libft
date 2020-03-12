#!/bin/sh
openrc
touch /run/openrc/softlevel
rc-service nginx start
rc-update add sshd
/etc/init.d/sshd start
adduser -D admin
echo 'admin' | chpasswd

tail -f /var/log/nginx/access.log /var/log/nginx/error.log
