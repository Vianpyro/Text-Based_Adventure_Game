// Copyright 2024 Vianney Veremme
#include "../include/Story.h"

#include <fstream>
#include <iostream>
#include <string>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

std::string Story::getNextStoryName() {
    return nextStoryName;
}

void Story::loadStory(const std::string& saveFile) {
    std::string filePath = "assets/quests/" + saveFile + ".json";
    std::ifstream file(filePath);

    // Check if file opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << saveFile << "!" << std::endl;
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
        // Check if "description" exists
        if (!segment.contains("description")) {
            continue;  // Skip this segment if essential data is missing
        }

        StorySegment storySegment;
        storySegment.description = segment["description"];

        // Parse chapter_end if it exists
        if (segment.contains("chapter_end")) {
            storySegment.chapterEnd = true;
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
            for (auto& [choiceId, nextSegmentId] :
                 segment["nextSegmentIds"].items()) {
                storySegment.nextSegmentIds[std::stoi(choiceId)] =
                    nextSegmentId;
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

    // Save the next story name if it exists
    if (storyData.contains("next_chapter") &&
        !storyData["next_chapter"].is_null()) {
        nextStoryName = storyData["next_chapter"];
    }

    // Indicate the story has been loaded successfully
    std::cout << storyData["introduction"] << std::endl;
}

void Story::nextSegment(int choice) {
    const auto& currentSegment = storySegments[currentSegmentId];

    if (currentSegment.chapterEnd) {
        std::cerr << "Error: Cannot move to next segment, story is over!"
                  << std::endl;
        return;
    }

    if (currentSegment.choices.find(choice) == currentSegment.choices.end()) {
        std::cerr << "Error: Invalid choice ID " << choice << std::endl;
        return;
    }

    if (currentSegment.nextSegmentIds.find(choice) !=
        currentSegment.nextSegmentIds.end()) {
        currentSegmentId = currentSegment.nextSegmentIds.at(choice);
    } else {
        std::cerr << "Error: Invalid next segment for choice ID "
                  << choice << std::endl;
    }
}

bool Story::printSegment() {
    // If the key `"chapter_end": true` is met, the story is over, return false
    const auto& segment = storySegments[currentSegmentId];

    if (segment.chapterEnd) {
        return false;
    }

    std::cout << "------------------------" << std::endl;
    std::cout << segment.description << std::endl;
    std::cout << std::endl;

    std::cout << "Choose an option:" << std::endl;

    std::vector<std::pair<int, std::string>> sortedChoices(
        segment.choices.begin(), segment.choices.end());
    std::sort(sortedChoices.begin(), sortedChoices.end());

    for (const auto& [choiceId, choiceText] : sortedChoices) {
        std::cout << "  Choice ID: " << choiceId
                  << " - " << choiceText << std::endl;
    }

    std::cout << "------------------------" << std::endl;

    return true;
}

void Story::unloadStory() {
    storySegments.clear();
    currentSegmentId = 0;
    nextStoryName.clear();
}
