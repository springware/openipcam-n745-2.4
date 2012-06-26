#
# $Id: net.sunset.sh,v 1.1.1.1 2006-07-11 09:28:12 andy Exp $
#
if [ -n "$UML_private_CTL" ]
then
    net_eth0="eth0=daemon,10:00:00:ab:cd:01,unix,$UML_private_CTL,$UML_private_DATA";
else
    net_eth0="eth0=mcast,10:00:00:ab:cd:01,239.192.0.2,40800"
fi

net="$net_eth0"

