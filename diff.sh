cd $1
mainoutfiles=(`ls out*.txt`)
yourfiles=(`ls yout*.txt`)

cmd="vim -c 'set diffopt=filler,vertical' -c 'edit ${mainoutfiles[0]}' -c 'diffsplit ${yourfiles[0]}' "
len=${#mainoutfiles[@]}
for((i=1; i<$len; i++)) do
  cmd="${cmd} -c 'tabe ${mainoutfiles[i]}' -c 'diffsplit ${yourfiles[i]}' "
done
eval $cmd
cd ..