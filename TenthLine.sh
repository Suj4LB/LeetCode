# Given a text file file.txt, print just the 10th line of the file.

# Read from the file file.txt and output the tenth line to stdout.
line_num=0
while read line && [ $line_num -le 10 ]; do
    let 'line_num = line_num + 1'
    if [ ${line_num} -eq 10 ]; then echo $line
    fi
done < file.txt
curr=0
