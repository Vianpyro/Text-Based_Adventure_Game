# Shattered Kingdom: Text-Based Adventure Game

Welcome to **Shattered Kingdom**, a text-based RPG where you take on the role of a hero in the fractured world of **Elyndor**. Your mission is to recover the five pieces of the legendary **Shattered Crown** and unite the kingdom before the dark sorcerer **Malakar** plunges it into chaos.

## Features

- **Classes**: Choose between **Warrior**, **Mage**, or **Rogue**, each with unique abilities and playstyles.
- **Exploration**: Journey through the **Frostbound Peaks**, **Sunken Ruins**, **Forbidden Forest**, **Ashen Wastes**, and **Abyssal Tower**.
- **Combat**: Engage in turn-based battles with mythical creatures and rival warlords.
- **Quests and Choices**: Complete side quests, make moral decisions, and shape the future of Elyndor through your actions.
- **Multiple Endings**: Your choices throughout the game determine the fate of the kingdom.

## Inspiration

The world of Elyndor and the plot of **Shattered Kingdom** are inspired by classic RPG mechanics and fantasy tropes found in games like _The Elder Scrolls_ series, _The Legend of Zelda_, and traditional _Dungeons & Dragons_ campaigns. These inspirations helped shape the game's atmosphere and mechanics, but the story and characters are entirely original.

## Technologies Used

- **C++**: The game is written in C++ to take advantage of object-oriented programming and memory management.
- **STL**: Utilizes the Standard Template Library for efficient handling of player inventory, quests, and game logic.
- **File I/O**: Supports saving and loading game progress using file streams.
- **Smart Pointers**: Implements modern C++ techniques like smart pointers to manage memory and avoid leaks.

## Plot

Curious about the story of **Shattered Kingdom**? Learn more about the world of **Elyndor**, its history, and your mission to reclaim the **Shattered Crown** on our [Wiki Plot Page](https://github.com/Vianpyro/Text-Based_Adventure_Game/wiki/Plot:-The-Shattered-Kingdom).

## Getting Started

## Requirements

- **Compiler**: g++ with C++17 support
- **External Libraries**:
  - `nlohmann::json` (JSON for Modern C++)

### Build Instructions

1. Clone the repository:

    ```bash
    git clone https://github.com/Vianpyro/Text-Based_Adventure_Game.git
    ```

2. Navigate to the project directory:

    ```bash
    cd Text-Based_Adventure_Game
    ```

3. Include external libraries

    ```bash
    sudo apt install nlohmann-json3-dev
    ```

4. Compile the code:

    ```bash
    make all
    ```

5. Run the Unit Tests (optional):

    ```bash
    make distcheck
    ```

6. Run the game:
    ```bash
    ./bin/ShatteredKingdom
    ```

## Contributing

Feel free to open issues or submit pull requests to improve the game, add new features, or suggest new quests and storylines!
