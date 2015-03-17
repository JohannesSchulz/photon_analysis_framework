#!/bin/bash

for file in /nfs/dust/cms/user/jschulz/signals/*;
do
        outputName=signal_${file:46} #cutting away susyEvents_
        echo ./processMC Signal $outputName $file
done
