#!/bin/sh


filesdir=$1
searchstr=$2

if [ $# -ne 2 ]
then
	echo "failed : any of the parameters above were not specified"
	exit 1
fi

if [ -d "$filesdir" ]
then
	echo ""
else
	echo "failed : "$filesdir" does not represent a directory on the filesystem"
	exit 1
fi

NUMBERFILES=$(find $filesdir -type f | wc -l)
COUNTWORD=$(grep -R $searchstr $filesdir | wc -l)

echo "The number of files are $NUMBERFILES and the number of matching lines are $COUNTWORD"




