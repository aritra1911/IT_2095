import os, re, sys

TEMPLATE = 'report.tex'
ROLL = '1930012'
LAB = sys.argv[1]
OUTPUT = ROLL + '_lab' + LAB + '.tex'
PATH = lambda file: "lab" + LAB + os.sep + file
BODY_BEGIN = '\\maketitle'
BODY_END = '\\end{document}'
PDFLATEX_BIN = 'pdflatex'

def main():
    with open(OUTPUT , 'w') as output_file:
        body = list()

        with open(TEMPLATE, 'r') as template_file:
            flag_body = False  # Inform if we're copying the body or not

            for line in template_file.readlines():
                if flag_body and line.strip() == BODY_END:
                    write_body(output_file, body)  # Time to compile the final body and
                    flag_body = False              # Make sure the \end{document} gets written

                if not flag_body:
                    output_file.write(line.replace('Lab N', 'Lab ' + LAB))
                    if line.strip() == BODY_BEGIN:
                        flag_body = True     # Realize we've got to the body
                else:                        # Then until EOF of template_file
                    body.append(line)        # Store the lines in `body`

    sys.exit(os.system(PDFLATEX_BIN + ' ' + OUTPUT + ' >> /dev/null'))


def write_body(output_file, body):
    flag_newpage = False
    source_files = filter(lambda f: f.endswith('.cpp'), os.listdir('lab' + LAB))
    files = sort_files(get_files_with_priority(source_files))

    for file in files:
        if not flag_newpage:
            flag_newpage = True
        else:
            output_file.write('\\newpage\n')

        for line in body:
            output_file.write(line.replace('Lab N', 'Lab ' + LAB)
                                  .replace('path/to/file.cpp', PATH(file))
                                  .replace('file.cpp', file.replace('_', '\_')))

def get_files_with_priority(files):
    files_with_priority = list()

    for file in files:
        with open(PATH(file), 'r') as source_file:
            files_with_priority.append((
                int(re.search(r'\d+', source_file.read()).group()),
                file
            ))

    return files_with_priority

def sort_files(files_with_priority):
    files = list()
    files_with_priority.sort()

    for _, file in files_with_priority:
        files.append(file)

    return files

if __name__ == '__main__':
    main()
