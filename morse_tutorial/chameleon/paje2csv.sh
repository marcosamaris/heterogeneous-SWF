inputfile=$1
outputfile=$2

# Sorting traces
grep -e '^\(\(%\)\|\(\(0\|1\|2\|3\|4\|5\|6\|7\|9\)\>\)\)' $inputfile > start.trace
grep -e '^\(\(%\)\|\(\(0\|1\|2\|3\|4\|5\|6\|7\|9\|18\|19\)\>\)\)' -v  $inputfile > end.trace
grep -e '10.*w.*Ctx.*' -v end.trace > end2.trace
sort -s -V --key=2,2 end2.trace > endSorted.trace
cat start.trace endSorted.trace > outputSorted.trace
# Converting to .csv
pj_dump -n -u outputSorted.trace > $outputfile
# Keeping only the states
perl -i -ne 'print if /^State/' $outputfile
# Delete temporary files
rm outputSorted.trace start.trace end.trace end2.trace endSorted.trace
# Adding a header manually
sed -i '1s/^/Nature, ResourceId, Type, Start, End, Duration, Depth, Value, Footprint , JobId , Params, Size, Tag\n/' $outputfile
