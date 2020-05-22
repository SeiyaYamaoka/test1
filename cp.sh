#!/bin/sh@#=ƒRƒƒ“ƒg
ymd=`date '+%Y%m%d'`
mkdir -p $ymd
for f in *.*; do
kmd=`date +%Y%m%d -r $f`
if [ $kmd = $ymd ]; then
echo $f
cp $f $ymd
fi
done