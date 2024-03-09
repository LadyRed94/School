#!/bin/bash
# traffic between client and server
x=1
a=1000000
while (( x < a )); do
    curl -o index.html https://localhost/2389
    (( x++ ))
done