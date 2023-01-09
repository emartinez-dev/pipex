# pipex

This project aims to deepen the understanding of the two concepts that we already know: Redirections and Pipes.
It is an introductory project for the bigger UNIX projects that will appear later on in the cursus.

## Usage
`$> ./pipex infile "ls -l" "wc -l" outfile`

Should behave like

`$> < file1 cmd1 | cmd2 > file2`

Where

- file1 and file2 are file names.

- cmd1 and cmd2 are shell commands with their parameters.
