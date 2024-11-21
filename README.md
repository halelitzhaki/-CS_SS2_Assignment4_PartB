# Cowboy VS. Ninja Simulation

## Overview

This project is a C++ simulation of a strategic battle between cowboys and ninjas. It demonstrates object-oriented programming principles, including inheritance, polymorphism, and encapsulation. The simulation allows for the creation of teams composed of different character types, each with unique abilities and behaviors.

## Features

- **Character Classes**:
  - *Cowboy*: Equipped with a gun, can shoot enemies.
  - *Ninja*: Possesses agility and can slash enemies with a sword.
  - *YoungNinja*, *TrainedNinja*, *OldNinja*: Variants of Ninja with differing attributes.

- **Team Formation**: Create teams of up to ten characters, mixing cowboys and ninjas.

- **Battle Simulation**: Teams can engage in battles, with each character acting according to its abilities.

- **Point Class**: Represents positions on the battlefield, supporting distance calculations and movement.

## Getting Started

### Prerequisites

- C++17 compatible compiler
- Make utility

### Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/halelitzhaki/CowboyVsNinja-Simulation.git
   cd CowboyVsNinja-Simulation
   ```

2. **Build the Project**:

   Use the provided `Makefile` to compile the project:

   ```bash
   make
   ```

   This will compile the source code and generate the executable.

### Usage

After building the project, you can run the simulation using:

```bash
./demo
```

The demo program showcases the creation of characters, formation of teams, and execution of a battle simulation.

## Project Structure

- `sources/`: Contains the implementation of classes and functions.
- `Demo.cpp`: Demonstrates the usage of the classes and simulates a battle.
- `Makefile`: Build script to compile the project.
- `README.md`: Project documentation.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your changes. Ensure that your code adheres to the existing style and includes appropriate tests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

This project was developed as part of an academic assignment to practice advanced C++ programming concepts.

## Author

**Halel Itzhaki**

For any questions or suggestions, please feel free to contact me.
