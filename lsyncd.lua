settings {
logfile = "/var/log/lsyncd/lsyncd.log",
statusFile = "/var/log/lsyncd/lsyncd-status.log",
statusInterval = 20,
}
sync {
default.rsync,
source="/home/mwittie/google_drive/Teaching/CSCI 366/code/CSCI_366_examples/ec2_rsync_example",
target="18.205.184.157:/home/ubuntu/ec2_rsync_example",
delay = 2,
rsync = {
compress = true,
acls = true,
verbose = true,
rsh = "/usr/bin/ssh -p 22 -o StrictHostKeyChecking=no -i /home/mwittie/google_drive/Configs/keys/CSCI_366.pem -l ubuntu" }
}
