#!/usr/bin/python3
import os
import subprocess
import shutil

code_dir = "code"

def get_sections():
    sections = []
    for (root, dirs, files) in os.walk(code_dir):
        subsections = []
        section_name = os.path.basename(root)
        sections.append((section_name, subsections))
        for file_name in sorted(files):
            subsection_name = os.path.splitext(file_name)[0]
            if subsection_name.startswith('.'):   # Skip hidden files
                continue
            print(subsection_name)
            relative_path = os.path.join(root, file_name)
            number_of_lines = len(open(relative_path).readlines())

            # ✅ Use md5sum to compute file hash
            full = subprocess.check_output(["md5sum", relative_path]).split()[0].decode()
            hash_value = full[:8]

            subsections.append((relative_path, subsection_name, number_of_lines, hash_value))
    return sections[1:]  # Skip the root 'code' directory

def get_style(filename):
    ext = filename.lower().split('.')[-1]
    if ext in ['c', 'cc', 'cpp']:
        return 'c++'
    elif ext in ['java']:
        return 'java'
    elif ext in ['py']:
        return 'python'
    else:
        return 'text'

def texify(s):
    return s  # Add escaping if needed

def get_tex(sections):
    tex = ''
    for (section_name, subsections) in sections:
        tex += '\\section{%s}\n' % texify(section_name)
        for (relative_path, subsection_name, number_of_lines, hash_value) in subsections:
            tex += '\\subsection{\\small %s  \\scriptsize [%s lines] - %s}\n' % (texify(subsection_name), number_of_lines, hash_value)
            tex += '\\inputminted{%s}{%s}\n' % (get_style(relative_path), '"' + relative_path + '"')
        tex += '\n'
    return tex

if __name__ == "__main__":
    sections = get_sections()
    tex = get_tex(sections)
    with open('contents.tex', 'w') as f:
        f.write(tex)
    latexmk_options = ["latexmk", "-pdf", "-shell-escape", "-cd", "notebook.tex"]
    subprocess.call(latexmk_options)

