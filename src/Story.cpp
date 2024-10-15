// Copyright 2024 Vianney Veremme
#include "../include/Story.h"

#include <fstream>
#include <iostream>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

void Story::loadStory() {
    std::ifstream file("assets/quests/plot.json");

    // Check if file opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Could not open plot.json file!" << std::endl;
        return;
    }

    // Try to parse the JSON data
    json storyData;
    try {
        file >> storyData;
    } catch (const std::exception& e) {
        std::cerr << "Error: Failed to parse JSON data - "
                  << e.what() << std::endl;
        return;
    }

    // Iterate over story data
    for (auto& [id, segment] : storyData.items()) {
        StorySegment storySegment;

        // Check if "description" exists
        if (segment.contains("description")) {
            storySegment.description = segment["description"];
        } else {
            std::cerr << "Warning: Missing 'description' for story segment "
                      << id << std::endl;
            continue;  // Skip this segment if essential data is missing
        }

        // Parse choices if they exist
        if (segment.contains("choices")) {
            for (auto& [choiceId, choiceText] : segment["choices"].items()) {
                storySegment.choices[std::stoi(choiceId)] = choiceText;
            }
        } else {
            std::cerr << "Warning: Missing 'choices' for story segment "
                      << id << std::endl;
        }

        // Parse nextSegmentIds if they exist
        if (segment.contains("nextSegmentIds")) {
            for (auto& [choiceId, nextSegmentId] : segment["nextSegmentIds"].items()) {
                storySegment.nextSegmentIds[std::stoi(choiceId)] = nextSegmentId;
            }
        } else {
            std::cerr << "Warning: Missing 'nextSegmentIds' for story segment "
                      << id << std::endl;
        }

        // Add the fully populated story segment to the map
        storySegments[std::stoi(id)] = storySegment;
    }

    // Set the current segment to the first segment
    currentSegmentId = 1;

    // Indicate the story has been loaded successfully
    std::cout << "Story loaded! Total segments: "
              << storySegments.size() << std::endl;
}

void Story::nextSegment(int choice) {
    const auto& currentSegment = storySegments[currentSegmentId];

    if (currentSegment.choices.find(choice) == currentSegment.choices.end()) {
        std::cerr << "Error: Invalid choice ID " << choice << std::endl;
        return;
    }

    if (currentSegment.nextSegmentIds.find(choice) != currentSegment.nextSegmentIds.end()) {
        currentSegmentId = currentSegment.nextSegmentIds.at(choice);
    } else {
        std::cerr << "Error: Invalid next segment for choice ID " << choice << std::endl;
    }
}

void Story::printSegment() {
    const auto& segment = storySegments[currentSegmentId];

    std::cout << "------------------------" << std::endl;

    std::cout << "Description: " << segment.description << std::endl;

    std::cout << "Choices:" << std::endl;
    for (const auto& [choiceId, choiceText] : segment.choices) {
        std::cout << "  Choice ID: " << choiceId
                  << " - " << choiceText << std::endl;
    }

    std::cout << "------------------------" << std::endl;
}

int Story::getCurrentSegment() const {
    return currentSegmentId;
}
