#!/bin/bash
for file in *; do
if [ -d $file ]; then
echo $file
cd $file
for file1 in *; do
echo $file1
done
cd ../
fi
done
