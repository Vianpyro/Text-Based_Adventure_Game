// Copyright 2024 Vianney Veremme
#include "../include/Story.h"

#include <fstream>
#include <iostream>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

void Story::setCurrentSegment(int segmentId) {
    if (storySegments.find(segmentId) == storySegments.end()) {
        std::cerr << "Error: Segment ID " << segmentId
                  << " does not exist!" << std::endl;
        return;
    }
    currentSegmentId = segmentId;
}

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

        // Parse next segment IDs if they exist
        if (segment.contains("nextSegmentIds")) {
            for (auto& [choiceId, nextId] : segment["nextSegmentIds"].items()) {
                storySegment.nextSegmentIds[std::stoi(choiceId)] = nextId;
            }
        } else {
            std::cerr << "Warning: Missing 'nextSegmentIds' for story segment "
                      << id << std::endl;
        }

        storySegments[std::stoi(id)] = storySegment;
    }

    // Set the current segment to the first segment
    currentSegmentId = 1;

    // Indicate the story has been loaded successfully
    std::cout << "Story loaded! Total segments: "
              << storySegments.size() << std::endl;
}

void Story::printSegment() {
    const auto& segment = storySegments[currentSegmentId];

    std::cout << "Segment ID: " << currentSegmentId << std::endl;
    std::cout << "Description: " << segment.description << std::endl;

    std::cout << "Choices:" << std::endl;
    for (const auto& [choiceId, choiceText] : segment.choices) {
        std::cout << "  Choice ID: " << choiceId
                  << " - " << choiceText << std::endl;
    }

    std::cout << "Next Segment IDs:" << std::endl;
    for (const auto& [choiceId, nextId] : segment.nextSegmentIds) {
        std::cout << "  Choice ID: " << choiceId
                  << " -> Next Segment ID: " << nextId << std::endl;
    }

    std::cout << "------------------------" << std::endl;
}

void Story::printStory() {
    for (const auto& [id, segment] : storySegments) {
        if (id == currentSegmentId) {
            std::cout << ">>> CURRENT SEGMENT <<<" << std::endl;
        }
        std::cout << "Segment ID: " << id << std::endl;
        std::cout << "Description: " << segment.description << std::endl;

        std::cout << "Choices:" << std::endl;
        for (const auto& [choiceId, choiceText] : segment.choices) {
            std::cout << "  Choice ID: " << choiceId
                      << " - " << choiceText << std::endl;
        }

        std::cout << "Next Segment IDs:" << std::endl;
        for (const auto& [choiceId, nextId] : segment.nextSegmentIds) {
            std::cout << "  Choice ID: " << choiceId
                      << " -> Next Segment ID: " << nextId << std::endl;
        }

        std::cout << "------------------------" << std::endl;
    }
}

int Story::getCurrentSegment() const {
    return currentSegmentId;
}
