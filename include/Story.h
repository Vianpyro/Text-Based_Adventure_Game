// Copyright 2024 Vianney Veremme
#ifndef INCLUDE_STORY_H_
#define INCLUDE_STORY_H_

#include <string>
#include <unordered_map>

struct StorySegment {
    std::string description;
    std::unordered_map<int, std::string> choices;
    std::unordered_map<int, int> nextSegmentIds;
};

class Story {
 public:
    void loadStory();
    void printStory();

 private:
    std::unordered_map<int, StorySegment> storySegments;
};

#endif  // INCLUDE_STORY_H_
