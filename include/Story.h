// Copyright 2024 Vianney Veremme
#ifndef INCLUDE_STORY_H_
#define INCLUDE_STORY_H_

#include <map>
#include <string>
#include <unordered_map>

struct StorySegment {
    std::string description;
    std::map<int, std::string> choices;
    std::map<int, int> nextSegmentIds;
};

class Story {
 public:
    void Story::loadStory(const std::string& saveFile);
    void nextSegment(int choice);
    void printSegment();

 private:
    int currentSegmentId;
    std::string nextStoryName;
    std::unordered_map<int, StorySegment> storySegments;
};

#endif  // INCLUDE_STORY_H_
