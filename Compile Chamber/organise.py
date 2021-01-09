from glob import glob
import os, sys
from shutil import copyfile
from tqdm import tqdm

basePath = '../Codeforces/'
code_files = []
for filename in os.listdir(basePath):
    file = os.path.join(basePath, filename)
    if not os.path.isfile(file): continue
    code_files.append(filename)

for filename in tqdm(code_files):
    file, i = os.path.join(basePath, filename), 0
    while filename[i] in '01234556789': i += 1
    contest = filename[:i]
    if not contest:
        print("Wrong Filename Format : {}".format(filename))
        sys.exit()
    folder = os.path.join(basePath, 'organised', contest)
    if not os.path.exists(folder):
        os.makedirs(folder)
    out_file = os.path.join(folder, filename)
    if not os.path.isfile(out_file):
        copyfile(file, out_file)
    
    
        