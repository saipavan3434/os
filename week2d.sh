for fname in $*
do
          if [ -f $fname ] 
          then
                    echo " $fname is a file"
                    echo " no of lines in file " `cat $fname | wc -l`
          elif [ -d $fname ] 
          then
                    echo " $fname is a directory"
           else
                    echo "enter valid filename or directory name"
           fi
done
