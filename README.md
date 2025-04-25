# SimpleShell

SimpleShell is a lightweight, Unix-like command-line shell built in C. It provides a basic interface for user interaction with the operating system, supporting common shell functionalities like command execution, built-in commands, and environment variable management.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Authors](#authors)

## Features

- Interactive command prompt with current directory display
- Command execution from PATH or with absolute paths
- Built-in commands: `exit`, `env`, `cd`, `help`, `setenv`, `unsetenv`
- Environment variable support and management
- Input/output redirection (`>`, `<`)
- Pipeline support (`|`)
- Error handling with appropriate exit codes
- Command history (WIP)

## Installation

### Prerequisites

- GCC compiler
- make (optional, for using the Makefile)
- Linux/Unix environment

### Compilation

```bash
# Clone the repository
git clone https://github.com/yourusername/simple_shell.git
cd simple_shell

# Compile the project
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

# Or use make if a Makefile is available
# make
```

## Usage

Run the shell in interactive mode:

```bash
./hsh
```

Or use it in non-interactive mode:

```bash
echo "ls -la" | ./hsh
```

## Built-in Commands

| Command | Description |
|---------|-------------|
| `env` | Prints the current environment variables |
| `exit [status]` | Exits the shell with optional status code |
| `cd [directory]` | Changes the current directory |
| `help` | Displays help information |
| `setenv VARIABLE VALUE` | Sets an environment variable |
| `unsetenv VARIABLE` | Removes an environment variable |

## Examples

Interactive mode:
```
($) ls -la
total 120
drwxr-xr-x  3 user user  4096 Apr 20 15:30 .
drwxr-xr-x 12 user user  4096 Apr 19 10:15 ..
-rwxr-xr-x  1 user user 38656 Apr 20 15:30 hsh
-rw-r--r--  1 user user   925 Apr 18 10:40 builtins.c
-rw-r--r--  1 user user   104 Apr 18 09:30 builtins.h
-rw-r--r--  1 user user  1724 Apr 20 13:45 executor.c
...

($) pwd
/home/user/simple_shell

($) echo Hello, SimpleShell!
Hello, SimpleShell!

($) exit 0
```

Non-interactive mode:
```bash
$ echo "ls -la | grep .c" | ./hsh
builtins.c
executor.c
parser.c
path.c
shell.c
utils.c
```

## Project Structure

- `shell.c`: Main shell loop and entry point
- `executor.c`: Command execution handling
- `parser.c`: Input parsing functionality
- `builtins.c`: Built-in command implementations
- `path.c`: PATH resolution functions
- `utils.c`: Utility functions
- `simple_shell.h`: Main header file with declarations
- `builtins.h`: Header for built-in commands

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Authors

See the [AUTHORS](AUTHORS) file for a list of contributors:
- Haidar Alessa <10682@holbertonstudents.com>
- Miad Alzhrani <10694@holbertonstudents.com>

## Acknowledgements

- Holberton School for the project requirements and guidance
- The C Programming Language by Brian Kernighan and Dennis Ritchie
