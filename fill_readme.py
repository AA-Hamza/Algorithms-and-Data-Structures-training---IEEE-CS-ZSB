#!/bin/python3

import sys
import os
import glob
import re

header = "#Problem Solving\n\n| Challenge | Solution |\n|:-------------:| :-----:|\n"

def get_name_from_file(file_name):
    name = file_name[0:file_name.find('.')]
    name = name.replace("-", " ")
    name = name.replace("_", " ")
    name = name.title()
    return name

def entry(url, file_name, folder):
    task_name = get_name_from_file(file_name)
    entry_buf = '|[{}]({})|[{}]({})|\n'.format(task_name, url, file_name, folder+file_name)
    return entry_buf

def main():
    regex = r"(?i)\b((?:https?://|www\d{0,3}[.]|[a-z0-9.\-]+[.][a-z]{2,4}/)(?:[^\s()<>]+|\(([^\s()<>]+|(\([^\s()<>]+\)))*\))+(?:\(([^\s()<>]+|(\([^\s()<>]+\)))*\)|[^\s`!()\[\]{};:'\".,<>???????]))" 
    #Yes I just copied it

    destination_name = "README.md"

    if (len(sys.argv) == 1):
        print("Filling defaults: README.md")
    elif (len(sys.argv) == 2):
        print("Working directory is . Modifying ", sys.argv[1], sep='')
        destination_name = sys.argv[1]
    else:
        print("Usage: ", sys.argv[0], " [File Name]", sep='')
        quit()
    
    readme_file = open(destination_name, "w")
    readme_file.write(header)

    dirs = glob.glob("CS21-Science-Day-*/")
    for day in dirs:
        print(day)
        tasks = os.listdir(day)
        for task in tasks:
            with open(day+task, "r") as f:
                try:
                    while True:
                        line = next(f)
                        urls = re.findall(regex, line) 
                        if (len(urls) > 0):
                            break;

                except StopIteration:
                    print("Couldn't find any url in file ", day, task, sep='')
            if (len(urls) > 0):
                link = urls[0][0]
                readme_file.write(entry(link, task, day))
                

        
    readme_file.close()

if __name__ == '__main__':
    main()
