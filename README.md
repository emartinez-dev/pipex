# Pipex Project @42 Málaga

## Introduction

The `pipex` program is a simplified UNIX pipeline emulator, implemented in C. The program mimics the functionality of running the following shell command:

```bash
< infile cmd1 | cmd2 > outfile
```

The project is also extended with bonus features, including error handling and support for multiple pipes.

## Contents

```
- src/
  - childs.c
  - errors.c
  - exit.c
  - init.c
  - main.c
  - parser.c
  - utils.c
- bonus/
  - childs_bonus.c
  - errors_bonus.c
  - exit_bonus.c
  - init_bonus.c
  - main_bonus.c
  - parser_bonus.c
  - utils_bonus.c
- inc/
  - pipex.h
- lib/
  - libft/
```

## Dependencies

- Standard C Libraries
- gcc compiler
- make

## Makefile

### Compilation Flags

- `-Wall -Wextra -Werror`

### Targets

- `all`: Compiles the main program.
- `bonus`: Compiles the bonus version.
- `clean`: Removes object files.
- `fclean`: Removes object files and the compiled program.
- `re`: Re-compiles the program.

## How to Compile

1. Clone the repository.
2. Run `make` for the main program or `make bonus` for the bonus version.

```bash
make
# OR
make bonus
```

## Usage

- Standard version:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

- Bonus version:

```bash
./pipex_bonus infile "cmd1" "cmd2" ... "cmdN" outfile
```

## Functions and Files

### Main Source Files

- `main.c`: Entry point of the program.
- `errors.c`: Contains error-handling functions.
- `utils.c`: Utility functions.
- `parser.c`: Command-line argument parser.
- `init.c`: Initialization functions.
- `childs.c`: Child process functions.
- `exit.c`: Exit and cleanup functions.

### Bonus Source Files

- `main_bonus.c`: Entry point for bonus version.
- `errors_bonus.c`: Bonus error-handling functions.
- `utils_bonus.c`: Bonus utility functions.
- `parser_bonus.c`: Bonus command-line argument parser.
- `init_bonus.c`: Bonus initialization functions.
- `childs_bonus.c`: Bonus child process functions.
- `exit_bonus.c`: Bonus exit and cleanup functions.
