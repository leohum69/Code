#!/bin/bash

touch b1.sh

echo "#!/bin/bash" > b1.sh
chmod +x b1.sh
echo date >> b1.sh
echo "echo Name : $1" >> b1.sh
echo "echo Total Marks : $2" >> b1.sh
echo "echo English : $3">>b1.sh
echo "echo Urdu : $4">>b1.sh
echo "echo Maths : $5">>b1.sh


./b1.sh 
