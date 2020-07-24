from glob import glob
import os, json, sys

basePath = os.path.abspath(__file__)
basePath = os.path.dirname(basePath)

def get_contents(file):
    with open(file) as fp:
        content = fp.readlines()
    content = [x.replace('\r', '') for x in content]
    return content

def parse_content(content):
    code = ''.join(content[2:-6])
    trigger = content[-4].replace('tabTrigger', '')
    trigger = trigger.replace('/', '').replace('<>', '')
    return code.strip(), trigger.strip()

def get_snippet(file):
    filename = os.path.basename(file).split('.')[0]
    content = get_contents(file)
    code, trigger = parse_content(content)
    snippet = {
        'prefix' : trigger,
        'body' : code,
        'description' : filename,
        'scope' : 'cpp'
    }
    return trigger, snippet

files = glob(os.path.join(basePath, '*.sublime-snippet'))
snippets = {}
for file in files:
    key, snippet = get_snippet(file)
    snippets[key] = snippet

out_name = 'VSCodeSnippetsC++'
if len(sys.argv) > 1:
	out_name = sys.argv[1]
out_file = os.path.join(basePath, out_name + '.code-snippets')
with open(out_file, 'w+') as fp:
    json.dump(snippets, fp, indent=4)
