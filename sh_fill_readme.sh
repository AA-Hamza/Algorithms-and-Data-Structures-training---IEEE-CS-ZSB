#!/usr/bin/bash

#Shell version of fill_README & shell is slower but it is just for learning purposes

FILES=$(ls CS21-Science-Day-[1-9]*/*.[!o]*)

DESTINATION="README.md"
mv "$DESTINATION" "${DESTINATION}_bak"
touch $DESTINATION
echo -e "# Problem Solving\n\n| Challenge | Solution |\n|:-------------:| :-----:|" >> $DESTINATION

for file_path in $FILES;
do
    FILE_NAME=$(echo "$file_path" | sed "s/.*\///")
    TITLE=$(echo "$FILE_NAME" | sed -r "s/(.+)\..+/\1/" | sed $'s/[^[:alnum:]\t]/ /g' | sed -e "s/\b\(.\)/\u\1/g")
    URL=$(grep -Eo "(http|https)://[a-zA-Z0-9./?=_%:-]*" $file_path)
    if [ -z "$URL" ]; then
        #echo -e "\033[0;31m Warning: Couldn't Find URL for " "$TITLE" " Passing it"
        echo "$(tput setaf 1)Warning: $(tput sgr0)Couldn't Find URL for" "$TITLE" "$(tput setaf 2)Passing it$(tput sgr0)."
        continue
    fi
    ENTRY=$(printf "|[%s](%s)|[%s](%s)|\n" "$TITLE" "$URL" "$FILE_NAME" "$file_path")
    echo $ENTRY >> $DESTINATION
    echo "$TITLE $(tput setaf 2)Done$(tput sgr0)."

done
