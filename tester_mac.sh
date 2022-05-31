#!/bin/sh

NBRS=$(./get_nbrs $1 $2 $3)
echo "list to sort is "$NBRS
./push_swap $NBRS
echo "moves needed : "$(./push_swap $NBRS | wc -l)
echo $'\033[1;7m'$(./push_swap $NBRS | ./checker_mac $NBRS)
