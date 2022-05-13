#！ /bin/bash

for i in 1 2 3 4
do
    if [ $i == 1 ]
    then
        continue
    elif [ $i == 3 ]
    then
        break
    fi
    echo "i == $i"
done