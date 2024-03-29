#!/bin/bash

echo -n "Starting firewall: "
IPTABLES="/sbin/iptables" # path to iptables
$IPTABLES --flush

# the network interface you want to protect
# NOTE: This may not be eth0 on all nodes -- use ifconfig to
# find the experimental network (10.1.x.x) and adjust this
# variable accordingly. Use the variable by putting a $ in
# front of it like so: $ETH . It can go in any command line
# and will be expanded by the shell.

# For example: iptables -t filter -i $ETH etc... 

ETH="eth1"
CLIENT="10.1.1.2"
SERVER="10.1.1.3"


# all traffic on the loopback device (127.0.0.1 -- localhost) is OK.
# Don't touch this!
$IPTABLES -A INPUT -i lo -j ACCEPT
$IPTABLES -A OUTPUT -o lo -j ACCEPT

# Your changes go below this line:
# ---8<---------------------------

# Allow all inbound and outbound traffic; all protocols, states,
# addresses, interfaces, and ports (it's like no firewall at all!):

#$IPTABLES -t filter -A INPUT -m state --state NEW,RELATED,ESTABLISHED -j ACCEPT
#$IPTABLES -t filter -A OUTPUT -m state --state NEW,RELATED,ESTABLISHED -j ACCEPT

# You probably want to comment out the above "firewall".

# Put NEW firewall rules here:
# (Each "instruction" may represent multiple iptables rules)

$IPTABLES -A INPUT -i $ETH -s $SERVER -j DROP
$IPTABLES -t filter -A INPUT -m state --state RELATED,ESTABLISHED -j ACCEPT
$IPTABLES -t filter -A OUTPUT -m state --state RELATED,ESTABLISHED -j ACCEPT

# ANTI-SPOOFING
# Include a rule to block spoofing (traffic appearing to come from the server's IP address [the experiment, not the loopback or control network.])

# helpful divisions:
# EXISTING CONNECTIONS
# --------------------
# Rules here specifically allow inbound traffic and outbound traffic for ALL previously
# accepted connections.



# NEW CONNECTIONS
# ---------------
# Rules here allow NEW traffic:
# 1. allow inbound traffic to the OpenSSH, Apache2, and MySQL servers. (MySQL traffic only allowed from client.)

$IPTABLES -A INPUT -i $ETH -p tcp --dport 22 -m state --state NEW -j ACCEPT
$IPTABLES -A INPUT -i $ETH -p tcp --dport 80 -m state --state NEW -j ACCEPT
$IPTABLES -A INPUT -i $ETH -p tcp --dport 3306 -m state --state NEW -s $CLIENT -j ACCEPT
$IPTABLES -A INPUT -i $ETH -p tcp --dport 443 -m state --state NEW -j ACCEPT

# 2. allow new outbound tcp traffic to remote systems running OpenSSH,
# Apache, and SMTP servers (on their standard ports).

$IPTABLES -A OUTPUT -o $ETH -p tcp --dport 22 -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -o $ETH -p tcp --dport 80 -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -o $ETH -p tcp --dport 443 -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -o $ETH -p tcp --dport 25 -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -o $ETH -p tcp --dport 465 -m state --state NEW -j ACCEPT
$IPTABLES -A OUTPUT -o $ETH -p tcp --dport 587 -m state --state NEW -j ACCEPT

# 3. allow new inbound udp traffic to ports 10000-10005, and new outbound
# udp traffic to ports 10006-10010. Inbound and outbound UDP traffic should be limited to being from client (for input) or to client (for output).
# (You can get client's address from DETERLab.)

$IPTABLES -A INPUT -i $ETH -p udp --dport 10000:10005 -m state --state NEW -s $CLIENT -j ACCEPT
$IPTABLES -A OUTPUT -o $ETH -p udp --dport 10006:10010 -m state --state NEW -d $CLIENT -j ACCEPT

# 4. allow the server to send and respond to ICMP pings.

$IPTABLES -A INPUT -p icmp --icmp-type echo-request -j ACCEPT
$IPTABLES -A OUTPUT -p icmp --icmp-type echo-reply -j ACCEPT
$IPTABLES -A INPUT -p icmp --icmp-type echo-reply -j ACCEPT
$IPTABLES -A OUTPUT -p icmp --icmp-type echo-request -j ACCEPT

# OTHER CONNECTIONS
# -----------------
# *IGNORE* all other traffic

$IPTABLES -P INPUT DROP

# No changes below this line:
# ---8<---------------------------
echo "done."

