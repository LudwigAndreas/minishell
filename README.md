# Minishell

The minishell project is a simple bash implementation. The project is a part of the School 21 curriculum. The project is written in C.

## Table of Contents

- [About](#about)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installing](#installing)
- [Running the tests](#running-the-tests)
- [Usage](#usage)
- [Built Using](#built-using)
- [Authors](#authors)
- [Acknowledgements](#acknowledgements)
- [License](#license)

## About

The minishell is a simple bash implementation with a few built-in commands. The project is written in C. The minishell supports the following built-in commands:

- `echo` (with -n option)
- `cd` (with only relative or absolute path)
- `pwd` (without any options)
- `export` (without any options)
- `unset` (without any options)
- `env` (without any options and any arguments)
- `exit` (without any options)

The minishell also supports the following features:

- Command line editing
- Signal handling (`Ctrl-C`, `Ctrl-D`, `Ctrl-\\`)
- Environment variables
- Redirections (`>`, `>>`, `<`, `<<`)
- Pipes (`|`)
- Exit status (`$?`)
- Separators (`;`)
- Quotes (`'` and `"`)
- Logical operators (`&&` and `||`)
- Wildcards (`*` and `?`)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

What things you need to install the software and how to install them.

```text
gcc >= 7.5.0
make >= 4.1
```

```bash
sudo apt-get install make
sudo apt-get install gcc
```

### Installing

A step by step series of examples that tell you how to get a development env running.

Clone the repository.

```bash
git clone https://github.com/LudwigAndreas/minishell.git

cd minishell
```

Build the project.

```bash
make
```

or build with bonus.

```bash
make bonus
```

Run the project.

```bash
./minishell
```

## Running the tests

Explain how to run the automated tests for this system.

```bash
make test
```

## Usage

After running the program, you will see the minishell prompt. You can enter the command you want to execute. Supported commands and features described in the [About](#about) section. You can exit the minishell by typing the `exit` command.

## Built Using

- [C](https://en.wikipedia.org/wiki/C_(programming_language)) - Programming language
- [Make](https://en.wikipedia.org/wiki/Make_(software)) - Build automation tool

## Authors

This project was developed by:

| <img src="https://avatars.githubusercontent.com/u/88089961?v=4" alt="drawing" width="50"/> |[LudwigAndreas](https://github.com/LudwigAndreas)|
| --- | --- |
| <img src="https://avatars.githubusercontent.com/u/57820208?s=60&v=4" alt="drawing" width="50"/> | [AndrefHub](https://github.com/AndrefHub) |

## Acknowledgements

- [School 21](https://21-school.ru/) - Educational institution
- [42](https://www.42.fr/) - Educational institution
- [Bash](https://www.gnu.org/software/bash/) - GNU Project's shell
- [Linux](https://www.kernel.org/) - Operating system kernel
- [Man](https://ru.wikipedia.org/wiki/Man) - Manual pages for Linux

## License

This project is licensed under the School 21 License - see the [LICENSE](LICENSE) file for details.
