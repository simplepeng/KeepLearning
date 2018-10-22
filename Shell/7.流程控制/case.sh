#! /bin/bash

a=5
case $a in
    1)
    echo "a == 1"
    ;;
    2)
    echo "a == 2"
    ;;
    *)
    echo "a不等于以上任何数"
    ;;
esac