#include <iostream>
#include <vector>
#include <random>
#include <ctime>

struct Room {
    std::vector<std::string> grid;  // 2D layout as text rows
};

// Generate a random room procedurally
Room generateRandomRoom(int width, int height, int enemyCount, int itemCount) {
    Room room;
    room.grid.resize(height, std::string(width, '.')); // start with floor

    // Place walls around edges
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
                room.grid[y][x] = '#';
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> xdist(1, width - 2);
    std::uniform_int_distribution<> ydist(1, height - 2);

    // Random enemies
    for (int i = 0; i < enemyCount; ++i) {
        int x = xdist(gen);
        int y = ydist(gen);
        room.grid[y][x] = 'E';
    }

    // Random items
    for (int i = 0; i < itemCount; ++i) {
        int x = xdist(gen);
        int y = ydist(gen);
        room.grid[y][x] = 'I';
    }

    // Random door placement (on outer walls)
    std::uniform_int_distribution<> doorChance(0, 1);
    int midX = width / 2;
    int midY = height / 2;

    if (doorChance(gen)) room.grid[0][midX] = 'D';          // north
    if (doorChance(gen)) room.grid[height - 1][midX] = 'D'; // south
    if (doorChance(gen)) room.grid[midY][0] = 'D';          // west
    if (doorChance(gen)) room.grid[midY][width - 1] = 'D';  // east

    return room;
}

// Render room
void renderRoom(const Room& room) {
    for (const auto& line : room.grid)
        std::cout << line << "\n";
}

int main() {
    // parameters: width, height, enemies, items
    Room room = generateRandomRoom(10, 6, 2, 1);

    std::cout << "Procedurally Generated Room:\n\n";
    renderRoom(room);

    return 0;
}
