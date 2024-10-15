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
    void loadStory();
    void nextSegment(int choice);
    void printSegment();

 private:
    std::unordered_map<int, StorySegment> storySegments;
    int currentSegmentId;
};

#endif  // INCLUDE_STORY_H_
